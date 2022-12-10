#include <bits/stdc++.h>

using namespace std;

#define MT(x, y, z) make_pair(make_pair(x, y), z)
#define L first.first
#define M first.second
#define R second

const int maxn = 10 + 85 - 85 + 2;
bool a[maxn][maxn][maxn], mark[maxn][maxn][maxn];
int n, m, h;
int ans;
pair<pair<int, int>, int> move[6] = {MT(1, 0, 0), MT(-1, 0, 0), MT(0, 1, 0), MT(0, -1, 0), MT(0, 0, 1), MT(0, 0, -1)};

void dfs(int x, int y, int z){
	mark[x][y][z] = true;
	ans++;
	for(int i = 0; i < 6; i++)
		if(!mark[x + move[i].L][y + move[i].M][z + move[i].R] and a[x + move[i].L][y + move[i].M][z + move[i].R])
			dfs(x + move[i].L, y + move[i].M, z + move[i].R);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> h >> n >> m;
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= m; k++){
				char c;
				cin >> c;
				a[i][j][k] = c - '#';
			}

	int x, y;
	cin >> x >> y;
	dfs(1, x, y);
	cout << ans << endl;
	return 0;
}