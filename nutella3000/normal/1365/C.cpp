#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e9 + 7;
const int max_n = 2e5 + 7;


signed main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
  	#endif
 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);


   	int n;
   	cin >> n;
   	vector<int> a(n);
   	map<int, int> b;

   	for(int i = 0;i < n;i++) cin >> a[i];
   	for(int i = 0;i < n;i++) {
   		int v;
   		cin >> v;
   		b[v] = i;
   	}

   	vector<int> res(n + 1);
   	int ans = 0;
   	for(int i = 0;i < n;i++) {
   		res[(b[a[i]] - i + n) % n]++;
   		ans = max(ans, res[(b[a[i]] - i + n) % n]);
   	}

   	//for(int i = 0;i < n;i++) cout << res[i] << " ";
   	//cout << endl;
   	cout << ans;
}