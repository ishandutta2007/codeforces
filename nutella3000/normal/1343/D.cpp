#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e15 + 7;



int sgn(int a) {
	if (a > 0) return 1;
	return -1;
}



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
   		int n, k;
   		cin >> n >> k;

   		vector<int> pr(2 * k + 3, 0);

   		vector<int> a(n);
   		for(int i = 0;i < n;i++) cin >> a[i];

   		for(int i = 0;i < n / 2;i++) {
   			int j = n - i - 1;

   			int mid = a[i] + a[j];

   			int left = mid - max(a[i], a[j]) + 1;

   			int right = mid + k - min(a[i], a[j]);

   			//cout << mid << " " << left << " " << right << '\n';

   			pr[0] += 2;
   			pr[left]--;
   			pr[mid]--;
   			pr[mid + 1]++;
   			pr[right + 1]++;
   		}


   		for(int i = 1;i <= 2 * k;i++) pr[i] += pr[i - 1];

   		int res = inf;
   		for(int i = 0;i <= 2 * k;i++) res = min(res, pr[i]);

   		cout << res << '\n';
   	}


}