#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e9 + 7;


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
		int n, m, x, y, cnt = 0, cnt2 = 0;
		cin >> n >> m >> x >> y;
		string s;
		for(int i =0;i < n;i++) {
			cin >> s;

			for(int j = 0;j < m;j++) if (s[j] == '.') cnt++;

			for(int j = 0;j < m - 1;j++) {
				if (s[j] == '.' && s[j + 1] == '.') {
					cnt2++;
					j++;
				}
			}
		}

		if (2 * x <= y) cout << cnt * x;
		else cout << cnt2 * y + (cnt - 2 * cnt2) * x;
		cout << endl;
	}
}