#include <bits/stdc++.h>

using namespace std;

int A[200001];
int RM[200001], LM[200001];

bool board[52][52];

bool okay[52][52];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int32_t main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			if(s[j] == 'B'){
				board[i + 1][j + 1] = 1;
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int x = 1; x <= n; x++){
				for(int y = 1; y <= m; y++){
					okay[x][y] = false;
				}
			}
			
			if(!board[i][j]) continue;
			vector<pair<int, int>> vp {{0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 0}, {2, 1}, {3, 0}, {3, 1}};
			if(board[i][j]){
				for(auto dirs : vp){
					int dir1 = dirs.first, dir2 = dirs.second;
					int cx = i, cy = j;
					while(board[cx][cy]){
						okay[cx][cy] = true;
						int x = cx, y = cy;
						while(board[x][y]){
							okay[x][y] = true;
							x += dx[dir2], y += dy[dir2];
						}
						cx += dx[dir1], cy += dy[dir1];
					}
				}
			}
			
			for(int x = 1; x <= n; x++){
				for(int y = 1; y <= m; y++){
					if(board[x][y] && !okay[x][y]){
						cout << "NO" << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}