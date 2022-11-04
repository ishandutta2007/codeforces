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
    int t, i, j;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   	cin >> t;
   	while(t--) {
   		int n, m;
   		cin >> n >> m;
   		vector<vector<int>> a(n + 1, vector<int>(m + 1));
   		for(i = 1; i <= n; i++) {
   			for(j = 1; j <= m; j++) {
   				cin >> a[i][j];
   			}
   		}

   		ll ans = 0;
   		for(i = 1; i <= (n + 1) / 2; i++) {
   			for(int j = 1; j <= (m + 1) / 2; j++) {
   				vector<int> dist;
   				dist.push_back(a[i][j]);
   				if(i != n - i + 1) {
   					dist.push_back(a[n - i + 1][j]);
   				}
   				if(j != m - j + 1) {
   					dist.push_back(a[i][m - j + 1]);
   				}
   				if(n - i + 1 != i || m - j + 1 != j) {
   					dist.push_back(a[n - i + 1][m - j + 1]);
   				}
   				ll mn = 1e18;
   				for(auto cur : dist) {
   					ll cst = 0;
   					for(auto it : dist) {
   						cst += abs(it - cur);
   					}
   					mn = min(mn, cst);
   				}
   				ans += mn;
   			}
   		}
   		cout << ans << "\n";
   	}

 	
    return 0;
}