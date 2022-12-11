#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;

#define MP make_pair
#define L first
#define R second

const int maxn = 2e3 + 85 - 69;
char t[maxn][maxn];
int n, m;
queue<pie> Q;
pie adj[8] = {MP(-1, 0), MP(+1, 0), MP(0, -1), MP(0, +1), MP(-1, -1), MP(-1, +1), MP(+1, -1), MP(+1, +1)};

bool isgush(int x, int y){
	return (t[x][y - 1] == '.' and t[x - 1][y - 1] == '.' and t[x - 1][y] == '.') or
		(t[x - 1][y] == '.' and t[x - 1][y + 1] == '.' and t[x][y + 1] == '.') or
		(t[x][y + 1] == '.' and t[x + 1][y + 1] == '.' and t[x + 1][y] == '.') or
		(t[x + 1][y] == '.' and t[x + 1][y - 1] == '.' and t[x][y - 1] == '.');
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> t[i][j];
			if(t[i][j] == '.')
				Q.push(MP(i, j));
		}
	}
	while(Q.size()){
		pie x = Q.front();
		Q.pop();
		for(int i = 0; i < 8; i++){
			int xx = x.L + adj[i].L,
				yy = x.R + adj[i].R;
			if(isgush(xx, yy) and t[xx][yy] == '*'){
				Q.push(MP(xx, yy));
				t[xx][yy] = '.';
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			cout << t[i][j];
		cout << '\n';
	}
	return 0;
}