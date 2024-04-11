#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e18 + 7;


signed main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
  	#endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
    	int n, m, a, b;
    	cin >> n >> m >> a >> b;
    	if (n * a != m * b) {
    		cout << "NO" << endl;
    		continue;
    	}
    	cout << "YES" << endl;

    	vector<vector<int>> res(n, vector<int>(m));
    	vector<int> cnt(m);

    	for(int i = 0;i < n;i++) {
    		int cnt1 = a;

    		while(cnt1) {
    		int M = inf;
    		for(int j = 0;j < m;j++) M = min(M, cnt[j]);
    		for(int j = 0;j < m;j++) {
    			if (cnt1 == 0) break;
    			if (cnt[j] == M) {
    				res[i][j] = 1;
    				cnt1--;
    				cnt[j]++;
    			}
    		}
    		}
    	}

    	for(int i = 0;i < n;i++) {
    		for(int j : res[i]) cout << j;
    			cout << endl;
    	}
    }
}