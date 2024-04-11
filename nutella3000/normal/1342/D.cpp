#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e9 + 7;


struct dsu {
	vector<int> parent;

	dsu(int n) {
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
		//for(int i = 0;i < n;i++) parent[i] = i;
	}

	int get(int v) {
		int p = v;
		while(v != parent[v]) v = parent[v];
		while(p != v) {
			int t = parent[p];
			parent[p] = v;
			p = t;
		}
		return v;
	}

	void merge(int a, int b) {
		parent[a] = b;
	}
	
};
 
signed main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
  	#endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> cnt(k + 1), prev2(k + 1);
    dsu prev1 = dsu(k + 1);
    for(int i = 0;i < n;i++) {
    	int v;
    	cin >> v;
    	cnt[v]++;
    }

   	vector<int> c(k + 1);
   	int last = 0;
   	for(int i = 1;i <= k;i++) {
   		cin >> c[i];
   		if (c[i] != c[i - 1]) last = i - 1;
   		prev2[i] = last;
   	}

   	for(int i = 1;i <= k;i++) {
   		if (cnt[i] == 0) prev1.merge(i, i - 1);
   	}

   	vector<vector<int>> res;

   	while(prev1.get(k) != 0) {
   		res.emplace_back(vector<int>());
   		int res_id = sz(res) - 1;

   		int id = k;

   		while(id != 0) {
   			id = prev1.get(id);
   			if (id == 0) break;
   			while(cnt[id] != 0 && res[res_id].size() != c[id]) {
   				cnt[id]--;
   				res[res_id].emplace_back(id);
   			}
   			if (cnt[id] == 0) prev1.merge(id, id - 1);
   			if (res[res_id].size() == c[id]) id = prev2[id];
   		}
   	}

   	cout << sz(res) << '\n';
   	for(auto i : res) {
   		cout << i.size() << " ";
   		for(int j : i) cout << j << " ";
   		cout << endl;
   	}
}