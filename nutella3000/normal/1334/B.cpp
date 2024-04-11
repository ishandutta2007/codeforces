#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;



signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while(t--) {
    	int n, x;
    	cin >> n >> x;
    	vector<int> a(n);
    	for(int i = 0;i < n;i++) cin >> a[i];
    	sort(a.begin(), a.end(), [](int v1, int v2) {return v1 > v2;});

    	int res = 0;
    	double sum = 0;
    	for(int i = 0;i < n;i++) {
    		sum += a[i];
    		if (sum / (i + 1) >= x) res++;
    	}

    	cout << res << '\n';

    }

}