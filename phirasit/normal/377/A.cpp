#include <stdio.h>

#define MX_N 510

char str[MX_N][MX_N];
int pass[MX_N][MX_N];
int d[10][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n,m,k;

int dfs(int x,int y,int lx,int ly) {
	if(x < 0 || y < 0 || x >= n || y >= m) return 0;
	if(str[x][y] != '.') return 0;
	if(pass[x][y]) return 0;
	pass[x][y] = 1;
	int cnt = 0;
	for(int i=0;i<4;i++) {
		int nx = d[i][0] + x,ny = d[i][1] + y;
		if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if(nx == lx && ny == ly) continue;
		cnt += dfs(nx,ny,x,y);
	}
	if(cnt == 0) {
		if(k-- > 0) {
			str[x][y] = 'X';
			return 0;
		}
	}
	return 1;
}
int main() {
	int i,j;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<n;i++) {
		scanf("%s",str[i]);
	}
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			if(str[i][j] == '.') {
				dfs(i,j,-1,-1);
				break;
			}
		}
		if(j < m) break;
	}
	for(i=0;i<n;i++) {
		printf("%s\n",str[i]);
	}
	return 0;
}