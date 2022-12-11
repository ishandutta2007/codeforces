#include <stdio.h>
#include <queue>

#define INF (-1u/2)
#define mp make_pair
#define A first
#define B second
#define MX_N 1010

using namespace std;

typedef pair<int,int> pii;
queue<pii> que;
char str[MX_N][MX_N];
int use[MX_N][MX_N];
int pass[MX_N][MX_N];
int cnt[MX_N][MX_N];
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n,m,ans = -INF;

char next(char ch) {
	if(ch == 'D') return 'I';
	if(ch == 'I') return 'M';
	if(ch == 'M') return 'A';
	if(ch == 'A') return 'D';
}
void dfs(int x,int y) {
	if(use[x][y]) {
		if(pass[x][y]) ans = INF;
		return;
	}
	pass[x][y] = 1;
	use[x][y] = 1;
	for(int i=0;i<4;i++) {
		int nx = d[i][0] + x,ny = d[i][1] + y;
		if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if(str[nx][ny] == next(str[x][y])) {
			dfs(nx,ny);
		}
	}
	pass[x][y] = 0;
	que.push(mp(x,y));
}
int main() {
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) {
		scanf("%s",str[i]);
	}
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			if(!use[i][j] && str[i][j] == 'D') {
				dfs(i,j);
			}
		}
	}
	while(!que.empty()) {
		pii top = que.front();
		que.pop();
		int mx = 0;
		int x = top.A,y = top.B;
		for(i=0;i<4;i++) {
			int nx = d[i][0] + x,ny = d[i][1] + y;
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if(next(str[x][y]) == str[nx][ny]) {
				if(cnt[nx][ny] > mx)
					mx = cnt[nx][ny];
			}
		}
		cnt[x][y] = mx+1;
		if(cnt[x][y] > ans)
			ans = cnt[x][y];
	}
	if(ans == INF) {
		printf("Poor Inna!\n");
	}else if(ans/4 == 0 || ans == -INF) {
		printf("Poor Dima!\n");
	}else {
		printf("%d\n",ans/4);
	}
	return 0;
}