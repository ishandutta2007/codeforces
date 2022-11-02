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
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	vector<int> cnt(2);
    	for(int i = 0;i < n;i++) {
    		cin >> a[i];
    		cnt[a[i] % 2]++;
    	}
    	sort(a.begin(), a.end());
    	bool good = false;
    	for(int i = 1;i < a.size();i++) if (a[i] == a[i - 1] + 1) good = true;
    	if ((cnt[1] % 2 == 0) ^ (cnt[0] % 2 == 0)) cout << "NO";
    	else if (cnt[1] % 2 == 1 && cnt[0] % 2 == 1 && !good) cout << "NO";
    	else cout << "YES";
    	cout << endl;
    }
}