#include <bits/stdc++.h>

using namespace std;

int B[100][100];
int ans[100][100];
int choose[100];
bool used[100][100];
void sub(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> A;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> B[i][j];
			A.push_back({B[i][j], {i, j}});
		}
	}
	sort(A.begin(), A.end());

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			used[i][j] = false;
			ans[i][j] = 0;
		}
	}
	
	for(int i = 0; i < m; i++){
		ans[A[i].second.first][i] = A[i].first;
		used[A[i].second.first][A[i].second.second] = true;
	}
	
	for(int i = 0; i < n; i++){
		int idx = 0;
		for(int j = 0; j < m; j++){
			while(used[i][idx]) idx++;
			if(ans[i][j] == 0){
				ans[i][j] = B[i][idx++];
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}