#include <bits/stdc++.h>
using namespace std;
 
char A[1000][1000];
int d[1000][1000];
bool visited[1000][1000];
 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
 
int n, m, q;
bool isValid(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}
 
int main(){
	cin >> n >> m >> q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			d[i][j] = (1 << 30);
		}
	}
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if((i + j) % 2 == 0){
				A[i][j] = (A[i][j] == '1' ? '0' : '1');
			}
		}
	}
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < m; j++){
// 			cout << A[i][j];
// 		}
// 		cout << endl;
// 	}
	deque<pair<int, int>> dq;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m - 1; j++){
			if(A[i][j] != A[i][j + 1]){
				d[i][j] = d[i][j + 1] = 0;
				dq.push_back({i, j});
				dq.push_back({i, j + 1});
			}
		}
	}
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < m; j++){
			if(A[i][j] != A[i + 1][j]){
				d[i][j] = d[i + 1][j] = 0;
				dq.push_back({i, j});
				dq.push_back({i + 1, j});
			}
		}
	}
	while(dq.size()){
		pair<int, int> op = dq.front();
		dq.pop_front();
		int x = op.first, y = op.second;
		if(visited[x][y]) continue;
		visited[x][y] = 1;
		for(int dir = 0; dir < 4; dir++){
			int nx = x + dx[dir], ny = y + dy[dir];
			if(isValid(nx, ny)){
				if(d[x][y] + 1 < d[nx][ny]){
					d[nx][ny] = d[x][y] + 1;
					dq.push_back({nx, ny});
				}
			}
		}
	}
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < m; j++){
// 			cout << d[i][j];
// 		}
// 		cout << endl;
// 	}
	if(d[0][0] == (1 << 30)){
		for(int i = 0; i < q; i++){
			long long x, y, p;
			cin >> x >> y >> p;
			x--; y--;
			int res = A[x][y] - '0';
			res ^= (x + y) % 2 == 0;
			cout << res << endl;
		}
		return 0;
	}
	for(int i = 0; i < q; i++){
		long long x, y, p;
		cin >> x >> y >> p;
		x--; y--;
		if(d[x][y] >= p){
			cout << ((A[x][y] - '0') ^ ((x + y) % 2 == 0)) << endl;
		}else{
			p -= d[x][y];
			if((p % 2) ^ (A[x][y] == '1')){
				cout << (1 ^ ((x + y) % 2 == 0)) << endl;
			}else{
				cout << (0 ^ ((x + y) % 2 == 0)) << endl;
			}
		}
	}
}