#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N, M;

int X[21];
bool use[1000011];

void MAIN() {
    scanf("%d%d", &N, &M);

    VI cur, nxt, aux;
    REP (i, M) cur.push_back(i+1);
    X[1] = cur.size();
    
    for (int t=2; t<=20; t++) {
	nxt.clear();
	REP (i, M) nxt.push_back(t * (i+1));
	aux.resize(cur.size() + nxt.size());
	merge(cur.begin(), cur.end(), nxt.begin(), nxt.end(), aux.begin());
	aux.erase(unique(aux.begin(), aux.end()), aux.end());
	swap(cur, aux);
	X[t] = cur.size();
    }

    LL ans = 1; // 1;

    for (int i=2; i<=N; i++) if (!use[i]) {
	int cnt = 0;
	for (LL j=i; j<=N; j*=i) {
	    use[j] = true;
	    cnt++;
	}
	ans += X[cnt];
    }
    

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}