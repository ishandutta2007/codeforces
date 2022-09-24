#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<cctype>
using namespace std;

typedef long long LL;
const int INF = 1<<29;
const int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};

int R, C;
char F[1024][1024];
int len[1024][1024];

int si, sj, ei, ej;

int main() {
    scanf("%d%d", &R, &C);
    for (int i=0; i<R; i++) scanf("%s", F[i]);

    for (int i=0; i<R; i++) {
	for (int j=0; j<C; j++) {
	    len[i][j] = INF;

	    if (F[i][j]=='S') { si = i; sj = j; }
	    if (F[i][j]=='E') { ei = i; ej = j; }
	}
    }

    queue<pair<int,int> > qu;
    qu.push(make_pair(ei, ej));
    len[ei][ej] = 0;
    for (;!qu.empty();) {
	int y = qu.front().first, x = qu.front().second;
	qu.pop();
	for (int d=0; d<4; d++) {
	    int yy = y+dy[d], xx = x+dx[d];
	    if (yy<0 || R<=yy || xx<0 || C<=xx || F[yy][xx]=='T' || len[yy][xx]<INF) continue;
	    len[yy][xx] = len[y][x] + 1;
	    qu.push(make_pair(yy, xx));
	}
    }

    int ans=0;
    for (int i=0; i<R; i++) {
	for (int j=0; j<C; j++) {
	    if (isdigit(F[i][j]) && len[i][j]<INF && len[i][j] <= len[si][sj]) {
		ans += F[i][j] - '0';
	    }
	}
    }
    printf("%d\n", ans);
    
    return 0;
}