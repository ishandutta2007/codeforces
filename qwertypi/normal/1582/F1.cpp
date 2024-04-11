#include <bits/stdc++.h>

using namespace std;

vector<int> g[8192];
bool ex[8192];
int mn[8192];
// very beautiful problem.
int main(){
	int n;
	cin >> n;
	fill(mn, mn + 8192, 5000);
	ex[0] = true;
	for(int i = 1; i <= 5000; i++){
		g[i].push_back(0);
	}
	for(int i = 0; i < n; i++){
		int v; cin >> v;
		ex[v] = true;
		for(auto j : g[v]){
			ex[j ^ v] = true;
			while(mn[j ^ v] > v){
				g[mn[j ^ v]].push_back(j ^ v);
				mn[j ^ v]--;
			}
		}
		g[v].clear();
	}
	vector<int> ans;
	for(int i = 0; i < 8192; i++){
		if(ex[i]) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for(auto i : ans){
		cout << i << ' ';
	}
	cout << endl;
}