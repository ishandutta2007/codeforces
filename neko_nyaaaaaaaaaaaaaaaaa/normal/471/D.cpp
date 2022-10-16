#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, w; cin >> n >> w;
      vector<int> arr(n), a(n);
      for (int i = 0; i < n; i++) {
      	cin >> arr[i];
      	if (i) a[i] = arr[i] - arr[i-1] + 1e9 + 7;
      }
      vector<int> brr(w), b(w);
      for (int i = 0; i < w; i++) {
      	cin >> brr[i];
      	if (i) b[i] = brr[i] - brr[i-1] + 1e9 + 7;
      }
      
	n--; w--;
      if (w == 0) {cout << n+1; return 0;}
      
      vector<int> prev(1000007);		// KMP table
	prev[0] = -1;
	
	for (int i = 1; i <= w; i++) {
		for (int j = prev[i-1]; j != -1; j = prev[j]) {
			if (b[j+1] == b[i]) {prev[i] = j+1; break;}
		}
	}
	
	int u = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		while (u != 0 && b[u+1] != a[i]) {u = prev[u];}
		if (b[u+1] == a[i]) {u++;}
		if (u == w) {ans++;}
	}
	cout << ans;
      
      return 0;
}