#include <bits/stdc++.h>

using namespace std;

int b[100002];

bool vis[100002];
vector<int> G[100002];
vector<int> tp;
void solve(){
	int n;
	cin >> n;
	fill(vis, vis + n + 2, false);
	for(int i = 0; i <= n + 1; i++){
		G[i].clear();
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	for(int i = 1; i <= n; i++){
		G[b[i]].push_back(i);
	}
	int l = 0, r = n;
	for(int i = 1; i <= n; i++){
		if(b[i] <= i){
			r = min(r, i - 1);
		}else{
			l = max(l, i);
		}
	}
	cout << l << endl;
	deque<int> dq;
	dq.push_back(0); vis[0] = true;
	dq.push_back(n + 1); vis[n + 1] = true;
	vector<int> ans;
	while(!dq.empty()){
		int t = dq.back();
		dq.pop_back();
		for(auto i : G[t]){
			if(!vis[i] && !G[i].size()){
				ans.push_back(i);
				dq.push_back(i);
			}
		}
		for(auto i : G[t]){
			if(!vis[i] && G[i].size()){
				ans.push_back(i);
				dq.push_back(i);
			}
		}
	}
	for(auto i : ans){
		cout << i << ' ';
	}
	cout << '\n';
}

int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}