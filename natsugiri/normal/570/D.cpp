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

const char *const YES = "Yes";
const char *const NO = "No";

typedef vector<VI> Adj;
const int MAX = 500111;
int N, M;
int depth[MAX], idx[MAX];
int P[MAX][20];
char S[MAX];

int parent(int v, int h) {
    for (int i=0; h; i++, h>>=1) {
	if (h&1) v = P[v][i];
    }
    return v;
}

int main() {
    scanf("%d%d", &N, &M);
    Adj G(N);
    Adj sums;
    
    REP (i, N-1) {
	int p;
	scanf("%d", &p);
	p--;
	//G[i+1].push_back(p);
	G[p].push_back(i+1);
	depth[i+1] = depth[p]+1;
	P[i+1][0] = p;
    }

    const int MAXH = *max_element(depth, depth+N) + 1;
    Adj H(MAXH);
    H[0].push_back(0);
    REP (i, MAXH-1) EACH (e, H[i]) EACH (v, G[*e]) {
	idx[*v] = H[i+1].size();
	H[i+1].push_back(*v);
    }

    REP (t, 19) REP (i, N) P[i][t+1] = P[P[i][t]][t];


    scanf("%s", S);

    sums.resize(MAXH);
    REP (d, MAXH) sums[d].assign(H[d].size()+1, 0);

    REP (i, N) {
	int k = S[i] - 'a';
	sums[depth[i]][idx[i]+1] ^= 1<<k;
    }
    REP (d, MAXH) REP (j, H[d].size()) sums[d][j+1] ^= sums[d][j];
        
    
    REP ($, M) {
	int v, height, de;
	scanf("%d%d", &v, &de);
	v--; de--;
	height = de - depth[v];

	if (height < 0 || de >= MAXH) {
	    puts(YES); // empty string
	    continue;
	}

	int L, R;
	int lo, hi;
	lo = -1; hi = H[de].size();
	while (hi - lo > 1) {
	    int m = (hi + lo) / 2;
	    int w = parent(H[de][m], height);
	    if (idx[w] < idx[v]) lo = m;
	    else hi = m;
	}
	L = hi;

	lo = -1; hi = H[de].size();
	while (hi - lo > 1) {
	    int m = (hi + lo) / 2;
	    int w = parent(H[de][m], height);
	    if (idx[w] > idx[v]) hi = m;
	    else lo = m;
	}
	R = hi;

	int k = sums[de][R] ^ sums[de][L];
	int len = R-L, od = __builtin_popcount(k);

	if ((len % 2 && od > 1) || (len % 2 == 0 && od > 0)) puts(NO);
	else puts(YES);
    }

    return 0;
}