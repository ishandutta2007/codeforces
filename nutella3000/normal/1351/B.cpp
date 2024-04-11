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
   		int a, b, c, d;
   		cin >> a >> b >> c >> d;

   		if (a < b) swap(a, b);
   		if (c < d) swap(c, d);
   		if (a == c && b + d == a) cout << "Yes" << endl;
   		else cout << "No" << endl;
   	}
}