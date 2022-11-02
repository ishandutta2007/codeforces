#include <bits/stdc++.h>
 
using namespace std;
 
int A[10000];
 
vector<vector<int>> dd(101);
bool okay[101];
int Q[101][2];
void sub(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n * k; i++){
		cin >> A[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < n * k; j++){
			if(A[j] == i) dd[i].push_back(j);
		}
	}
	
	int idx = 0;
	for(int i = 0; i < k - 1; i++){
		map<int, int> M;
		int cnt = 0;
		for(; idx < n * k; idx++){
			if(cnt == (n + k - 2) / (k - 1)) break;
			if(okay[A[idx]]) continue;
			if(M.find(A[idx]) != M.end()){
				cnt++;
				Q[A[idx]][0] = M[A[idx]] + 1;
				Q[A[idx]][1] = idx + 1;
				okay[A[idx]] = true;
			}else{
				M[A[idx]] = idx;
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(Q[i][0] > Q[i][1]) swap(Q[i][0], Q[i][1]);
		cout << Q[i][0] << ' ' << Q[i][1] << endl;
	}
}
 
int32_t main(){
	int t = 1;
	while(t--) sub();
}