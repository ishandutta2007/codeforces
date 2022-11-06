#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const int MAXN = (int) 2e5;

vector<int> g[MAXN + 1];
vector<int> top;
int vis[MAXN + 1];
bool bad;

void dfs(int nod) {
	vis[nod] = 1;
	for(auto it : g[nod]) {
		if(vis[it] == 0) {
			dfs(it);
		}
		else if(vis[it] == 1) {
			bad = true;
		}
	}
	top.push_back(nod);
	vis[nod] = 2;
}


int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
   	int	i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(i = 1; i <= m; i++) {
    	int x, y;
    	cin >> x >> y;
    	g[x].push_back(y);
    }

    for(i = 1; i <= n; i++) {
    	if(vis[i] == 0)
    		dfs(i);
    }
  	
  	if(bad) {
  		cout << -1;
  		return 0;
  	}

  	vector<int> mn(n + 1, n + 1), deg(n + 1);
  	for(auto nod : top) {
  		mn[nod] = nod;
  		for(auto it : g[nod]) {
  			mn[nod] = min(mn[nod], mn[it]);
  		}
  		if(mn[nod] < nod) {
  			deg[nod] = 1;
  		}
  	}

  	fill(mn.begin(), mn.end(), n + 1);
  	reverse(top.begin(), top.end());

  	for(auto nod : top) {
  		mn[nod] = min(mn[nod], nod);
  		for(auto it : g[nod]) {
  			mn[it] = min(mn[nod], mn[it]);
  		}
  		if(mn[nod] < nod) {
  			deg[nod] = 1;
  		}
  	}

  	cout << count(deg.begin(), deg.end(), 0) - 1 << "\n";
  	for(i = 1; i <= n; i++) {
  		if(deg[i]) {
  			cout << 'E';
  		}
  		else {
  			cout << 'A';
  		}
  	}
    
    return 0;
}