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

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

const int dy[] = { 0, 1, 0, -1 };
const int dx[] = {  1, 0, -1 , 0};

int R, C;
char F[2111][2111];


bool in(int y, int x) {
    return 0 <= y && y < R && 0 <= x && x < C;
}

stack<int> X, Y; // tiled
int CNT(int y, int x) {
    int cnt = 0;
    REP (d, 4) {
	int xx = x + dx[d], yy = y + dy[d];
	if (in(yy, xx) && F[yy][xx] == '.') cnt++;
    }
    return cnt;
}
bool tile(int y, int x) {
    int yy = y, xx = x;
    if (in(y, x+1) && F[y][x+1] == '.') { F[y][x] = '<' ; F[y][x+1] = '>'; xx++; }
    else if (in(y, x-1) && F[y][x-1] == '.') { F[y][x-1] = '<' ; F[y][x] = '>'; xx--; }
    else if (in(y+1, x) && F[y+1][x] == '.') { F[y][x] = '^' ; F[y+1][x] = 'v'; yy++; }
    else if (in(y-1, x) && F[y-1][x] == '.') { F[y-1][x] = '^' ; F[y][x] = 'v'; yy--; }
    else return false;

    X.push(xx);
    Y.push(yy);
    return true;
}


int main() {
    scanf("%d%d", &R, &C);
    REP (i, R) scanf("%s", F[i]);


    bool ok = true;
    REP (y, R) REP (x, C) if (F[y][x] == '.') {
	if (CNT(y, x) == 1 && !tile(y, x)) ok = false;
    }
    while (ok && !X.empty()) {
	int px = X.top(); X.pop();
	int py = Y.top(); Y.pop();
	REP (d, 4) {
	    int x = px + dx[d], y = py + dy[d];
	    if (!in(y, x) || F[y][x] != '.') continue;
	    if (CNT(y, x) == 1 && !tile(y, x)) ok = false;
	}
    }
    
    REP (i, R) REP (j, C) if (F[i][j] == '.') ok = false;

    if (ok) {
	REP (i, R) puts(F[i]);
    } else {
	puts("Not unique");
    }

    
    return 0;
}