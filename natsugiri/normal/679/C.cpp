#include<stack>
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

const int dy[] = { 1, 0, -1, 0 };
const int dx[] = { 0, -1, 0, 1 };

int N, K;
char F[555][555];
int H[555][555];
int cnt;

bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N && F[y][x] == '.';
}

int B[555 * 555];
int C[555 * 555];


int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%s", F[i]);

    memset(H, -1, sizeof H);

    REP (i, N) REP (j, N) if (H[i][j] == -1 && F[i][j] == '.') {
	stack<int> Y, X;
	Y.push(i);
	X.push(j);
	while (Y.size()) {
	    int y = Y.top(); Y.pop();
	    int x = X.top(); X.pop();
	    if (H[y][x] != -1) continue;
	    H[y][x] = cnt;
	    B[cnt]++;

	    REP (d, 4) {
		int yy = y + dy[d];
		int xx = x + dx[d];
		if (in(yy, xx) && H[yy][xx] == -1) {
		    Y.push(yy);
		    X.push(xx);
		}
	    }
	}
	cnt++;
    }

    int ans = 0;

    for (int y=0; y+K <= N; y++) {
	// init;

	memset(C, 0, sizeof C);
	REP (i, K) REP (j, K) {
	    if (F[i+y][j] == '.') C[H[i+y][j]]++;
	}

	for (int x=0; x+K <= N; x++) {
	    VI v;
	    REP (t, K) {
		if (in(y-1, x+t)) v.push_back(H[y-1][x+t]);
		if (in(y+K, x+t)) v.push_back(H[y+K][x+t]);
		if (in(y+t, x-1)) v.push_back(H[y+t][x-1]);
		if (in(y+t, x+K)) v.push_back(H[y+t][x+K]);
	    }

	    sort(v.begin(), v.end());
	    v.erase(unique(v.begin(), v.end()), v.end());

	    int tmp = K * K;
	    EACH (e, v) {
		tmp += B[*e];
		tmp -= C[*e];
	    }

	    amax(ans, tmp);

	    if (x + K < N) REP (i, K) if (in(i+y, x+K)) C[H[i+y][x+K]]++;
	    REP (i, K) if (in(i+y, x)) C[H[i+y][x]]--;
	}
    }


    printf("%d\n", ans);

    return 0;
}