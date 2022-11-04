#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;

const ll INF = 1e18;
const int MAXN = (int) 1e5;

vector<int> g[MAXN + 1];
ll s[MAXN + 1], mn[MAXN + 1];

void dfs(int nod, ll mx) {
	mx = max(mx, s[nod]);
	mn[nod] = INF;
	if(s[nod] != -1) {
		mn[nod] = min(mn[nod], s[nod]);
	}
	for(auto it : g[nod]) {
		dfs(it, mx);
		mn[nod] = min(mn[nod], mn[it]);
	}
	if(mn[nod] == INF) {
		mn[nod] = mx;
	}
}

int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(i = 2; i <= n; i++) {
    	int par; cin >> par;
    	g[par].push_back(i);
    }
    for(i = 1; i <= n; i++) {
    	cin >> s[i];
    }
    dfs(1, -1LL);
    ll ans = s[1];
   	for(i = 1; i <= n; i++) {
   		if(s[i] != -1 && s[i] > mn[i]) {
   			cout << -1;
   			return 0;
   		}
   		for(auto it : g[i]) {
   			ans += mn[it] - mn[i];
   		}
   	}
   	cout << ans;

    return 0;
}