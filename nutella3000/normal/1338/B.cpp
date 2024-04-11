#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e15 + 7;
const int max_n = 1e5 + 1;
int n;
vector<int> gr[max_n];
int num[max_n];
int min_ans = 1, max_ans = 0;
 
bool dist1[max_n];
 
 
void dfs(int v, int pr) {
 
	vector<bool> have(2);
 
	bool new_v = false;
 
	for(int to : gr[v]) {
		if (to == pr) continue;
 
		dfs(to, v);
 
		max_ans++;
		//cout << to + 1 << " " << new_v << '\n';
		if (new_v && gr[to].size() == 1) max_ans--;
		else if (dist1[to] && gr[v].size() == 1) max_ans--; 
		if (gr[to].size() == 1) new_v = true;
 
 
		if (gr[to].size() == 1) dist1[v] = true;
 
 
		have[num[to]] = true;
	}
 	
 	if (gr[v].size() == 1 && have[0]) min_ans = 3;
	if (have[0] && have[1]) min_ans = 3;
	else if (have[0]) num[v] = 1;
	else num[v] = 0;
}
 
 
void scan() {
	cin >> n;
	for(int i = 0;i < n - 1;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		gr[v1].emplace_back(v2);
		gr[v2].emplace_back(v1);
	}
}
 
 
void solve() {
	scan();
 
	dfs(0, -1);
 
	cout << min_ans << " " << max_ans;
}
 
 
signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);
 
   	solve();
 
}