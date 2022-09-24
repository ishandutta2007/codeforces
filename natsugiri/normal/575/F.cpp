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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }


int N, X, S[5011], E[5011];
LL INF;
LL cur[10011], nxt[10011];

int main() {
    scanf("%d%d", &N, &X);
    REP (i, N) scanf("%d%d", S+i, E+i);


    VI I;
    I.push_back(X);
    REP (i, N) {
	I.push_back(S[i]); 
	I.push_back(E[i]);
    }
    sort(I.begin(), I.end());
    I.erase(unique(I.begin(), I.end()), I.end());
//    eprintf("%lu\n", I.size());

    int M = I.size();
    memset(cur, 0x3f, sizeof cur);
    memset(&INF, 0x3f, sizeof INF);

    LL MAX = I.back() + 1;
    REP (j, M) if (I[j] == X) cur[j] = 0;

    REP (i, N) {
	LL cost = INF;
	memset(nxt, 0x3f, sizeof (LL) * (M+1));
	REP (j, M) {
	    amin(cost, cur[j] - I[j]);
	    amin(nxt[j], cost + I[j]);
	}
	cost = INF;
	for (int j=M; j--; ) {
	    amin(cost, cur[j] - (MAX-I[j]));
	    amin(nxt[j], cost + (MAX-I[j]));
	}

	REP (j, M) {
	    if (I[j] < S[i]) nxt[j] = min(INF, nxt[j] + S[i] - I[j]);
	    if (E[i] < I[j]) nxt[j] = min(INF, nxt[j] + I[j] - E[i]);
	}
	swap(cur, nxt);
    }

    LL ans = *min_element(cur, cur+M);
    printf("%lld\n", ans);

    return 0;
}