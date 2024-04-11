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

int N;
typedef vector<VI> Adj;
Adj G;

const int END = 5, NO = 6, T = 7;
int ty[100011];
int par[100011];

int main() {
    scanf("%d", &N);
    G = Adj(N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    const int ROOT = 0;
    memset(par, -1, sizeof par);
    VI ord; ord.push_back(ROOT);

    REP (i, N) {
	int x = ord[i];
	EACH (e, G[x]) if (*e != par[x]) {
	    par[*e] = x;
	    ord.push_back(*e);
	}
    }
    REP (i_, N) {
	int x = ord[N-1-i_];
	int cnt[T] = {}, ch = 0, ma = 0;
	EACH (e, G[x]) if (*e != par[x]) {
	    cnt[ty[*e]]++;
	    ch++;
	    amax(ma, ty[*e]);
	}

	if (ma == 0) {
	    if (cnt[0] <= 1) ty[x] = 0;
	    else if (cnt[0] == 2) ty[x] = 1;
	    else /* cnt[0] > 2 */ ty[x] = 2;
	} else if (ma == 1) {
	    ty[x] = 2;
	} else if (ma == 2) {
	    if (cnt[2] == 1) ty[x] = 2;
	    else if (cnt[2] == 2) ty[x] = 3;
	    else /* cnt[2] > 2 */ ty[x] = NO;
	} else if (ma == 3) {
	    if (cnt[3] == 1) {
		if (cnt[2] || cnt[1] || cnt[0] > 2) ty[x] = NO;
		else if (cnt[0] <= 1) ty[x] = 4;
		else /* cnt[0] == 2 */ ty[x] = END;
	    } else {
		ty[x] = NO;
	    }
	} else if (ma == 4) {
	    if (ch == 1) ty[x] = 4;
	    else if (ch == 2 && cnt[0] == 1) ty[x] = END;
	    else ty[x] = NO;
	} else /* ma == END || ma == NO */ {
	    ty[x] = NO;
	}
//	eprintf("%d %d\n", x+1, ty[x]);
    }

    if (ty[ROOT] == NO) puts("No");
    else puts("Yes");
    return 0;
}