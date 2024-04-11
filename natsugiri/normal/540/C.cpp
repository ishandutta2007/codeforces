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
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int N, M;
char F[555][555];
bool A[555][555];
int Rs, Cs, Rt, Ct;

bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);
    scanf("%d%d%d%d", &Rs, &Cs, &Rt, &Ct);
    Rs--; Cs--; Rt--; Ct--;

    queue<int> X, Y;
    Y.push(Rs);
    X.push(Cs);
    A[Rs][Cs] = true;
    while (Y.size()) {
	int y = Y.front(); Y.pop();
	int x = X.front(); X.pop();
	
	REP (d, 4) {
	    int yy= y + dy[d], xx = x + dx[d];
	    if (in(yy, xx) && F[yy][xx] == '.' && !A[yy][xx]) {
		A[yy][xx] = true;
		Y.push(yy); X.push(xx);
	    }
	}
    }

    
    bool yes = false;
    int cnt = 0;
    REP (d, 4) {
	int y = Rt + dy[d], x = Ct + dx[d];
	if (in(y, x) && A[y][x]) cnt++;
    }
    if (F[Rt][Ct] == 'X' && cnt > 0) yes = true;
    if (F[Rt][Ct] == '.' && cnt > 1) yes = true;

    puts(yes? "YES": "NO");
    
    return 0;
}