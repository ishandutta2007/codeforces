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

   	int n, x;
   	cin >> n >> x;

   	n = n * 2 + 100;
   	vector<int> d(n), pref1(n), pref2(n);

   	for(int i = 1;i <= (n - 100) / 2;i++) cin >> d[i];

   	for(int i = (n - 100) / 2 + 1;i < n;i++) d[i] = d[i - (n - 100) / 2];

   	for(int i = 1;i < n;i++) {
   		pref1[i] = pref1[i - 1] + d[i];
   		//cout << pref1[i] << " ";
   		pref2[i] = pref2[i - 1] + d[i] * (d[i] + 1) / 2;
   	}
   	//cout << endl;

   	int res = 0;

   	for(int fin = (n - 100) / 2 + 1;fin < n;fin++) {
   		int l = 0;
   		int r = fin + 1;
   		while(r - l > 1) {
   			int mid = ((l + r) >> 1);

   			if (pref1[fin] - pref1[mid - 1] >= x) l = mid;
   			else r = mid;
   		}

   		//cout << fin - l << " ";

   		int st_num = d[l] - (x - (pref1[fin] - pref1[l]));

   		int new_res = d[l] * (d[l] + 1) / 2 - st_num * (st_num + 1) / 2 + pref2[fin] - pref2[l];

   		res = max(res, new_res);

   		//cout << new_res << " ";
   	}
   	//cout << endl;

   	cout << res;
}