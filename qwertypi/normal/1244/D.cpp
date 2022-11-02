#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define int long long
int C[100000][3];
int A[100000];
int dp[100001][3][2];
int ans[100000];
vector<vector<int>> graph(100000);
int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> C[i][0];
	}
	for(int i = 0; i < n; i++){
		cin >> C[i][1];
	}
	for(int i = 0; i < n; i++){
		cin >> C[i][2];
	}
	for(int i = 0; i < n - 1; i++){
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		graph[v1].push_back(v2); 
		graph[v2].push_back(v1);
	}
	int st = -1;
	for(int i = 0; i < n; i++){
		if(graph[i].size() > 2){
			cout << -1 << endl;
			return 0;
		}else if(graph[i].size() == 1){
			st = i;
		}
	}
	A[0] = st;
	A[1] = graph[A[0]].front();
	for(int i = 1; i < n - 1; i++){
		for(auto j : graph[A[i]]){
			if(j != A[i-1]){
				A[i+1] = j;
			}
		}
	}
	int Ans = (1LL << 60);
	string ver;
	vector<vector<int>> K = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
	for(vector<int> i : K){
		int CK = 0;
		for(int j = 0; j < n; j++){
			CK += C[A[j]][i[j % 3]-1];
		}
		if(CK < Ans){
			Ans = CK;
			ver = to_string(i[0] * 100 + i[1] * 10 + i[2]);
		}
	}
	cout << Ans << endl;
	for(int i = 0; i < n; i++){
		ans[A[i]] = ver[i % 3];
	}
	for(int i = 0; i < n; i++){
		cout << (char)ans[i] << ' ';
	}
}