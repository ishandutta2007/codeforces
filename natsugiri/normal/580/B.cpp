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

int N, D;
pair<int, int> P[100011];
int main() {
    scanf("%d%d", &N, &D);
    REP (i, N) scanf("%d%d", &P[i].first, &P[i].second);
    sort(P, P+N);
    
    LL ans = 0, s = 0;
    for (int i=0, j=0; i<N; i++) {
	while (j<N && P[j].first - P[i].first < D) {
	    s += P[j].second;
	    j++;
	}
	amax(ans, s);
	s -= P[i].second;
    }

    printf("%lld\n", ans);
    
    return 0;
}