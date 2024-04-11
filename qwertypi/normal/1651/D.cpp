#include <bits/stdc++.h>

using namespace std;

int A[200001][2];
int ans[200001][2];
map<pair<int, int>, int> S;
int dx[4] = {1, -1, 0, 0}; int dy[4] = {0, 0, 1, -1};
bool visited[200001];
void sub(){
	int n;
	cin >> n;
	fill(visited, visited + n, 0);
	S.clear();
	for(int i = 0; i < n; i++){
		cin >> A[i][0] >> A[i][1];
		S[{A[i][0], A[i][1]}] = i;
	}
	deque<int> dq;
	for(int i = 0; i < n; i++){
		bool fail = false;
		for(int t = 0; t < 4; t++){
			if(S.find({A[i][0] + dx[t], A[i][1] + dy[t]}) == S.end()){
				ans[i][0] = A[i][0] + dx[t];
				ans[i][1] = A[i][1] + dy[t]; 
				dq.push_back(i);
				visited[i] = true;
				fail = true;
				break;
			}
		}
	}
	while(dq.size()){
		int i = dq.front(); dq.pop_front();
		for(int t = 0; t < 4; t++){
			if(S.find({A[i][0] + dx[t], A[i][1] + dy[t]}) != S.end()){
				int id = S[{A[i][0] + dx[t], A[i][1] + dy[t]}];
				if(visited[id]) continue;
				dq.push_back(id);
				ans[id][0] = ans[i][0];
				ans[id][1] = ans[i][1]; 
				visited[id] = true;
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << ans[i][0] << ' ' << ans[i][1] << endl;
	}
}
int main(){
	int t = 1;
	// cin >> t;
	while(t--){
		sub();
	}
}