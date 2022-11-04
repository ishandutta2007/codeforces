#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int MAXN = (int) 1e5;

vector<int> g[MAXN + 1];
vector<pair<int, int>> sol;

int dfs(int nod, int par, int cur_time, int back_time, int T) {
	sol.push_back({nod, cur_time});
	//cerr << nod << " " << cur_time << "\n";

	int sons_left = (int)g[nod].size() - 1;
	for(int i = 0; i < (int)g[nod].size(); i++) {
		int son = g[nod][i];
		if(son != par) {
			if(cur_time == T) {
				cur_time = back_time - sons_left;
				sol.push_back({nod, cur_time});
				//cerr << nod << " " << cur_time << "\n";
			}

			int new_time = dfs(son, nod, cur_time + 1, cur_time, T) + 1;

			cur_time = new_time;
			sol.push_back({nod, cur_time});
			//cerr << nod << " " << cur_time << "\n";

			sons_left--;
		}
	}

	assert(back_time <= cur_time);
	if(back_time < cur_time) {
		sol.push_back({nod, back_time});
	}

	//cerr << nod << " " << back_time << "\n";

	return back_time;
} 


int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
   	int	i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   	cin >> n;
   	for(i = 1; i < n; i++) {
   		int u, v;
   		cin >> u >> v;
   		g[u].push_back(v);
   		g[v].push_back(u);
   	}

   	int T = 0;
   	for(i = 1; i <= n; i++) {
   		T = max(T, (int)g[i].size());
   	}

   	dfs(1, 0, 0, (int)g[1].size(), T);

   	cout << sol.size() << "\n";
   	for(auto it : sol) {
   		cout << it.first << " " << it.second << "\n";
   	}
    
    return 0;
}