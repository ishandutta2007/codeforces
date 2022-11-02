#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G(100001);
int A[100000][3];
int main(){
	int n;
	cin >> n; 
	for(int i = 0; i < n - 2; i++){
		cin >> A[i][0] >> A[i][1] >> A[i][2];
		G[A[i][0]].push_back(A[i][1]);
		G[A[i][0]].push_back(A[i][2]);
		G[A[i][1]].push_back(A[i][0]);
		G[A[i][1]].push_back(A[i][2]);
		G[A[i][2]].push_back(A[i][0]);
		G[A[i][2]].push_back(A[i][1]);
	}
	vector<int> cnt_1, cnt_2;
	for(int i = 1; i <= n; i++){
		if(G[i].size() == 2){
			cnt_1.push_back(i); 
		}
		if(G[i].size() == 4){
			cnt_2.push_back(i);
		}
	}
	int prev = 0;
	int st = cnt_1.front();
	set<int> visited = {st};
	for(auto i : G[st]){
		if(G[i].size() == 4){
			prev = st;
			st = i;
			visited.insert(st);
		}
	}
	cout << prev << ' ' << st << ' ';
	for(int i = 0; i < n - 2; i++){
		for(auto j : G[st]){
			if(count(G[j].begin(), G[j].end(), st) == 2 && visited.find(j) == visited.end()){
				cout << j << ' ';
				prev = st;
				st = j;
				visited.insert(st);
				break;
			}
			
		}
	}
	for(int i = 1; i <= n; i++){
		if(visited.find(i) == visited.end()){
			cout << i;
		}
	}
}