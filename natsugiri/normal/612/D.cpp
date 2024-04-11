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

int N, K;
vector<pair<int, int> > P, ans;

int main() {
    scanf("%d%d", &N, &K);
    P.reserve(2*N);
    REP (i, N) {
	int a, b;
	scanf("%d%d", &a, &b);
	P.push_back(make_pair(a, -1));
	P.push_back(make_pair(b, +1));
    }

    sort(P.begin(), P.end());

    int d = 0;
    int last = 0;
    REP (i, 2*N) {
	if (P[i].second == -1) {
	    d++;
	    if (d == K) last = P[i].first;
	} else {
	    if (d == K) ans.push_back(make_pair(last, P[i].first));
	    d--;
	}
    }


    printf("%d\n", (int)ans.size());
    EACH (e, ans) printf("%d %d\n", e->first, e->second);
    return 0;
}