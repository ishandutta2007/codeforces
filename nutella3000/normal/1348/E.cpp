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


    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    vector<bool> can(k);
    int sum1 = 0, sum2 = 0;
    for(int i = 0;i < n;i++) {
    	cin >> a[i] >> b[i];
    	sum1 += a[i];
    	sum2 += b[i];
    }
    can[sum1 % k] = true;

    //cout << sum1 << endl;

    for(int i = 0;i < n;i++) {
    	//if (a[i] + b[i] < k) continue;
   		int Max = min(a[i], k);
   		int Min = k - min(b[i], k);

   		Max = -Max + k, Min = -Min + k, swap(Max, Min);

   		//cout << Min << " " << Max << endl;
   		vector<bool> new_can(k);
   		for(int j = 0;j < k;j++) new_can[j] = can[j];
		for(int q = 0;q < k;q++) {
   			if (can[q]) {
   				for(int j = Min;j <= Max;j++) {
   					new_can[(q + j) % k] = true;
   				}
   			}
   		}
   		can = new_can;
    }

    int Min = inf;
    for(int i = k - 1;i >= 0;i--) if (can[i]) Min = i;

    //cout << Min << endl;

    sum2 += (sum1 % k - Min);
	sum1 -= (sum1 % k - Min);

	cout << (sum1 / k + sum2 / k);
}