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

    int n;
   	cin >> n;
   	int b[n];
   	int a[n];
   	int x = 0;
   	for(int i = 0;i < n;i++) cin >> b[i];
   	a[0] = b[0];
   	for(int i = 1;i < n;i++) {
   		x = max(x, a[i - 1]);
   		a[i] = b[i] + x;
   	}

   	for(int i = 0;i < n;i++) {
   		cout << a[i] << " ";
   	}
}