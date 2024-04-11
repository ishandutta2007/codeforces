#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

struct BySecond {
    template<class T, class U> bool operator()(const pair<T, U> &x, const pair<T, U> &y) const {
	return x.second < y.second;
    }
} bySecond;

int N;
LL A, Cf, Cm, M;
pair<LL, int> S[100011];

int main() {
    scanf("%d%lld%lld%lld%lld", &N, &A, &Cf, &Cm, &M);
    REP (i, N) {
	scanf("%lld", &S[i].first);
	S[i].second = i;
    }

    sort(S, S+N);
    S[N].first = 1LL<<60;
    
    LL sumh = 0, suml = 0;
    REP (i, N) suml += S[i].first;
    int j = N-1;

    LL ans = -10;
    LL bestI = -1, bestJ = -1, bestL = -1;

    REP (i, N+1) {
	if (i) sumh += S[N-i].first;
	LL cost = i*A - sumh;
	if (cost > M) break;

	while (j >= (N-i) || (j >= 0 && (j+1)*S[j].first - suml + cost > M)) {
	    suml -= S[j].first;
	    j--;
	}

	if (j < 0) {
	    LL tmp = 0;
	    if (i == N) tmp = i * Cf + A * Cm;
	    else tmp = i * Cf + S[0].first * Cm;
	    if (ans < tmp) {
		ans = tmp;
		bestI = i;
		bestJ = -1;
	    }
	} else {
	    LL cost2 = (j+1)*S[j].first - suml;
	    if (cost + cost2 <= M) {
		// amax(ans, i * Cf + S[j] * Cm);
		LL rest = M - cost - cost2;
		LL z;
		if (j == N-1 || j+i==N-1) z = min(A, S[j].first + rest / (j+1));
		else z = min(S[j+1].first, S[j].first + rest / (j+1));

		LL tmp = i * Cf + z * Cm;
		if (ans < tmp) {
		    ans = tmp;
		    bestI = i;
		    bestJ = j;
		    bestL = z;
		}
	    }
	}
    }

    printf("%lld\n", ans);

    REP (i, bestJ+1) S[i].first = bestL;
    REP (i, bestI) S[N-1-i].first = A;
    sort(S, S+N, bySecond);
    REP (i, N) printf("%lld%c", S[i].first, i==N-1? '\n': ' ');
    return 0;
}