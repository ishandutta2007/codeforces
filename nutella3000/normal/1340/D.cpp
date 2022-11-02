#include <bits/stdc++.h>
using namespace std;
  
//#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e9 + 7;
vector<vector<int>> gr;
int n, max_num = 0;
vector<int> res_v, res_t;

void dfs(int v, int t, int pr) {
	res_v.emplace_back(v);
	res_t.emplace_back(t);

	deque<int> a;
	for(int i : gr[v]) 
		if (i != pr) a.emplace_back(i);
	

	int v_t = t;

	while(!a.empty() && v_t != max_num) {
		int to = a.front();
		a.pop_front();
		dfs(to, v_t + 1, v);
		v_t++;
		res_v.emplace_back(v);
		res_t.emplace_back(v_t);
	}

	if (v == 0) return;

	v_t = t - 1 - a.size();
	res_v.emplace_back(v);
	res_t.emplace_back(v_t);

	while(!a.empty()) {
		int to = a.front();
		a.pop_front();
		dfs(to, v_t + 1, v);
		v_t++;
		res_v.emplace_back(v);
		res_t.emplace_back(v_t);
	}
}

void solve() {
	cin >> n;
	gr.resize(n);
	for(int i = 0;i < n - 1;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		gr[v1].emplace_back(v2);
		gr[v2].emplace_back(v1);
	}

	for(int i = 0;i < n;i++) max_num = max(max_num, sz(gr[i]));

	dfs(0, 0, -1);

	cout << res_v.size() << endl;

	for(int i = 0;i < sz(res_v);i++) {
		cout << res_v[i] + 1 << " " << res_t[i] << endl;
	}
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