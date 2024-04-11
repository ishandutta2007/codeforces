#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;
const int max_n =2e5 + 4;
const int mod = 998244353;
int n, k, a[max_n], id[max_n];


signed main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

   	cin >> n >> k;
   	for(int i = 0;i < n;i++) cin >> a[i];
   	for(int i = 0;i < n;i++) id[i] = i;
   		
   	sort(id, id + n, [](int v1, int v2){return a[v1] > a[v2];});

   	bool good[n];
   	for(int i =0;i < n;i++) good[i] = false;
   	for(int i = 0;i < k;i++) good[id[i]] = true;
   	int last = -1;
   	int ans1 = 0;
   	for(int i = 0;i < k;i++) ans1 += n - i;
   	int ans2 = 1;

   	for(int i = 0;i < n;i++) {
   		if (good[i]) {
   			if (last != -1) {
   				ans2 = ans2 * (i - last) % mod;
   			}

   			last = i;
   		}
   	}

   	cout << ans1 << " " << ans2;
}