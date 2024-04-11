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
    	int n, x;
    	cin >> n >> x;
    	vector<int> cnt(2);
    	for(int i = 0;i < n;i++) {
    		int v;
    		cin >> v;
    		cnt[v % 2]++;
    	}

    	if (cnt[1] == 0 || (x == n && cnt[1] % 2 == 0) || (cnt[0] == 0 && x % 2 == 0)) cout << "No";
    	else cout << "Yes";
    	cout << endl;
    }
}