#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e15 + 7;



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
    	int n;
    	cin >> n;
    	vector<int> a(n), b(n);
    	for(int i = 0;i < n;i++) {
    		cin >> a[i] >> b[i];
    	}
    	for(int i = 0;i < n;i++) b[i] = min(b[i], a[(i + 1) % n]);

    	int sum = 0;
    	for(int i = 0;i < n;i++) sum += a[i] - b[i];
    	int m = inf;
    	for(int i = 0;i < n;i++) m = min(m, b[i]);
    	sum += m;
    	cout << sum << '\n';
    }

}