#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

long long n, m, t, a, b, c;
char arr[1005][1005];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool gd[1005][1005];
bool vis[1005][1005];
int dist[1005][1005];
queue<pair<pair<int, int>, int> > q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> t;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	bool bruh = false;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			for (int k=0; k<4; k++){
				int x = dx[k] + i;
				int y = dy[k] + j;
				if (x < 0 || x >= n || y < 0 || y >= m) continue;
				if (arr[x][y] == arr[i][j]){
					gd[i][j] = true;
					q.push(mp(mp(i,j),0));
					vis[i][j] = true;
					bruh = true;
				}
			}
		}
	}
	while(!q.empty()){
		int i = q.front().first.first;
		int j = q.front().first.second;
		int d = q.front().second;
		q.pop();
		dist[i][j] = d;
		for (int k=0; k<4; k++){
			int x = dx[k] + i;
			int y = dy[k] + j;
			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			if (vis[x][y]) continue;
			vis[x][y] = true;
			q.push(mp(mp(x,y),d+1));
		}
	}
	for (int i=0; i<t; i++){
		cin >> a >> b >> c;
		a--;
		b--;
		if (!bruh) cout << arr[a][b] << "\n";
		else if (c <= dist[a][b]) cout << arr[a][b] << "\n";
		else {
			long long tt = (c - dist[a][b])%2;
			long long bb;
			if (arr[a][b] == '0') bb = 0;
			else bb = 1;
			cout << (bb + tt)%2 << "\n";
		}
	}
}