#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

long long n, k, m, t, a, b, c, d, e, f, x, y;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool vis[1005][1005];
char arr[1005][1005];

void fill(int x, int y){
	vis[x][y] = true;
	for (int i=0; i<4; i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
		if (arr[xx][yy] == '.') continue;
		if (vis[xx][yy]) continue;
		fill(xx,yy);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int cnt = 0;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> arr[i][j];
			if (arr[i][j] == '#') cnt++;
		}
	}
	bool bruh1 = true, bruh2 = true;;
	bool rows = true, cols = true;
	for (int i=0; i<n; i++){
		int gd = 0;
		for (int j=0; j<m; j++){
			if (arr[i][j] == '.') gd++;
		}
		if (gd == m) bruh1 = false;
		if (gd == 0) rows = false;
	}
	for (int i=0; i<m; i++){
		int gd = 0;
		for (int j=0; j<n; j++){
			if (arr[j][i] == '.') gd++;
		}
		if (gd == n) bruh2 = false;
		if (gd == 0) cols = false;
	}
	if (bruh1 == false && bruh2 == true){
		cout << -1;
		return 0;
	}
	if (bruh2 == false && bruh1 == true){
		cout << -1;
		return 0;
	}
	bool bruh = true;
	for (int i=0; i<n; i++){
		int gd = 0;
		for (int j=0; j<m; j++){
			if (arr[i][j] == '#' && gd == 0) gd = 1;
			if (arr[i][j] == '.' && gd == 1) gd = 2;
			if (arr[i][j] == '#' && gd == 2) gd = 3;
		}
		if (gd == 3) bruh = false;
	}
	for (int i=0; i<m; i++){
		int gd = 0;
		for (int j=0; j<n; j++){
			if (arr[j][i] == '#' && gd == 0) gd = 1;
			if (arr[j][i] == '.' && gd == 1) gd = 2;
			if (arr[j][i] == '#' && gd == 2) gd = 3;
		}
		if (gd == 3) bruh = false;
	}
	if (!bruh){
		cout << -1;
		return 0;
	}
	int ans = 0;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (vis[i][j]) continue;
			if (arr[i][j] == '.') continue;
			ans++;
			fill(i,j);
		}
	}
	cout << ans;
}