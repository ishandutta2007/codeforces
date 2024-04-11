#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;




 
 
int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t, i;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
	
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;

    	vector<vector<int>> g(n + 1);
    	for(i = 1; i < n; i++) {
    		int x, y;
    		cin >> x >> y;
    		g[x].push_back(y);
    		g[y].push_back(x);
    	}

    	vector<int> sz(n + 1);
    	
    	function<void(int, int)> dfs = [&](int nod, int par) {
    		sz[nod] = 1;
    		for(auto it : g[nod]) {
    			if(it != par) {
    				dfs(it, nod);
    				sz[nod] += sz[it];
    			}
    		}
    	};

    	dfs(1, 0);

    	vector<int> centroids;
    	for(i = 1; i <= n; i++) {
    		int mx = 0;
    		for(auto it : g[i]) {
    			if(sz[it] > sz[i]) {
    				mx = max(mx, n - sz[i]);
    			}
    			else {
    				mx = max(mx, sz[it]);
    			}
    		}
    		if(mx <= n / 2) {
    			centroids.push_back(i);
    		}
    	}

    	if((int)centroids.size() == 1) {
    		cout << 1 << " " << g[1][0] << "\n" << 1 << " " << g[1][0] << "\n";
    		continue;
    	}

    	for(auto it : g[centroids[1]]) {
    		if(it != centroids[0]) {
    			cout << it << " " << centroids[1] << "\n" << it << " " << centroids[0] << "\n";
    			break;
    		}
    	}

    }
	

 
    return 0;
}