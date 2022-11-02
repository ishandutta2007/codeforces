#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)
#define fi first
#define se second
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int d1[2013][2013], d2[2013][2013];
bool visited[2013][2013];
int A[2013][2013];

int32_t main(){
	ios_base::sync_with_stdio(false);
	int n, m, w;
	cin >> n >> m >> w;
	for(int i = 0; i <= n + 1; i++){
		for(int j = 0; j <= m + 1; j++){
			A[i][j] = -1;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> A[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			d1[i][j] = inf;
			d2[i][j] = inf;
		}
	}
	d1[1][1] = d2[n][m] = 0;
	
	deque<pair<int, pair<int, int>>> dq;
	dq.push_back({0, {1, 1}});
	for(int i = 0; i <= n + 1; i++){
		for(int j = 0; j <= m + 1; j++){
			visited[i][j] = 0;
		}
	}
	
	visited[1][1] = true;
	while(dq.size()){
		pair<int, pair<int, int>> op = dq.front();
		dq.pop_front();
		int d = op.fi, i = op.se.fi, j = op.se.se;
		d1[i][j] = d;
		for(int dir = 0; dir < 4; dir++){
			int ni = i + dx[dir], nj = j + dy[dir]; // new i, j
			if(!visited[ni][nj] && A[ni][nj] != -1){
				dq.push_back({d + w, {ni, nj}});
				visited[ni][nj] = true;
			}
		}
	}

	dq.push_back({0, {n, m}});
	for(int i = 0; i <= n + 1; i++){
		for(int j = 0; j <= m + 1; j++){
			visited[i][j] = 0;
		}
	}
	
	visited[n][m] = true;
	while(dq.size()){
		pair<int, pair<int, int>> op = dq.front();
		dq.pop_front();
		int d = op.fi, i = op.se.fi, j = op.se.se;
		d2[i][j] = d;
		for(int dir = 0; dir < 4; dir++){
			int ni = i + dx[dir], nj = j + dy[dir]; // new i, j
			if(!visited[ni][nj] && A[ni][nj] != -1){
				dq.push_back({d + w, {ni, nj}});
				visited[ni][nj] = true;
			}
		}
	}

	int ans = d1[1][1] + d2[1][1];
	int costL = inf, costR = inf;
	for(int i = 0; i <= n + 1; i++){
		for(int j = 0; j <= m + 1; j++){
			if(A[i][j] != -1 && A[i][j] != 0){
				if(d1[i][j] != -1) costL = min(costL, d1[i][j] + A[i][j]);
				if(d2[i][j] != -1) costR = min(costR, d2[i][j] + A[i][j]);
			}
		}
	}
	ans = min(ans, costL + costR);
	if(ans >= (inf >> 1)){
		cout << -1 << endl;
	}else{
		cout << ans << endl;
	}
}