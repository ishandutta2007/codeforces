#include<queue>
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

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1};


int N, M;
char S[1011][1011];
int SY, SX, TY, TX;

int D[4][1011][1011];

bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

const string door[4] = {
    "+|^LRD",
    "+->LUD",
    "+|vLRU",
    "+-<RUD",
};

bool has(int y, int x, int d, int l) {
    d = (d + 4 - l) % 4;
    return door[d].find(S[y][x]) != door[d].npos;
}

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", S[i]);
    scanf("%d%d%d%d", &SY, &SX, &TY, &TX);
    SY--; SX--; TY--; TX--;

    memset(D, 0x3f, sizeof D);
    D[0][SY][SX] = 0;
    queue<int> Y, X, L;
    Y.push(SY);
    X.push(SX);
    L.push(0);

    int ans = -1;
    
    while (!Y.empty()) {
	int y = Y.front(); Y.pop(); 
	int x = X.front(); X.pop(); 
	int l = L.front(); L.pop(); 
	int c = D[l][y][x];

	if (y == TY && x == TX) {
	    ans = c;
	    break;
	}


	REP (d, 4) {
	    int yy = y + dy[d];
	    int xx = x + dx[d];
	    if (in(yy, xx) && D[l][yy][xx] > c + 1 && has(y, x, d, l) && has(yy, xx, (d + 2) % 4, l)) {
		D[l][yy][xx] = c + 1;
		Y.push(yy);
		X.push(xx);
		L.push(l);
	    }
	}

	int ll = (l + 1) % 4;
	if (D[ll][y][x] > c + 1) {
	    D[ll][y][x] = c + 1;
	    Y.push(y);
	    X.push(x);
	    L.push(ll);
	}
    }


    printf("%d\n", ans);
    return 0;
}