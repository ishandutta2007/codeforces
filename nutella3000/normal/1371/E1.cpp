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
    int n, p;
   	cin >> n >> p;
   	vector<int> a(n);
   	for(int i = 0;i < n;i++) cin >> a[i];
   	sort(a.begin(), a.end());
   	int Max = a[p - 1] - 1, Min = 0;

   	vector<int> res;
   	vector<int> bad(p + 1);
  	for(int i = 0;i < n;i++) {
  		int q = i + 1 - a[i];
   		Min = max(Min, -q + 1);
   		q = (-(q % p) + p) % p;
   		bad[q] = a[i] + 1;
   	}
   	
   	/*cout << Min << " " << Max << endl;
   	for(int i : a) cout << i << " ";
   	cout << endl;
   	for(int i : bad) cout << i << " ";*/

   	for(int i = 0;i < p;i++) {
   		int q = i + p * (max(Min, bad[i]) / p);
   		//cout << q << endl;
   		if (q < max(Min, bad[i])) q += p;
   		while(q <= Max) {
   			res.emplace_back(q);
   			q += p;
   		}
   	}

   	sort(res.begin(), res.end());
   	cout << res.size() << endl;
   	for(int i : res) cout << i << " ";
}