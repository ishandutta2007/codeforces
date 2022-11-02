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
    	int n, m;
    	cin >> n >> m;
    	vector<string> a(n);
    	string s;
    	for(int i = 0;i < n;i++) {
    		cin >> a[i];
    	}

    	bool good = false;
    	for(int i = 0;i < m;i++) {
    		s = a[0];
    		for(char j = 'a';j <= 'z';j++) {
    			s[i] = j;

    			bool bad = false;
    			for(int q = 0;q < n;q++) {
    				int cnt = 0;
    				for(int w = 0;w < m;w++) {
    					if (s[w] != a[q][w]) cnt++;
    				}
    				if (cnt > 1) bad = true;
    			}
    			if (bad) continue;
    			cout << s << endl;
    			good = true;
    			goto kuku;
    		}
    	}
    	kuku:

    	if (!good)
    	cout << -1 << endl;

    }
}