#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);
      
      int n; cin >> n;
      string a, b;
      cin >> a >> b;
      int ans = 0;
      for (int i = 0, j = n-1; i <= j; i++, j--) {
      	if (i == j) {
      		ans += (a[i] != b[i]);
      		continue;
      	}
      	
      	if (a[i] == b[i] && a[j] == b[j]) continue;
      	if (a[j] == b[i] && a[i] == b[j]) continue;
      	if (a[i] == a[j] && b[i] == b[j]) continue;
      	if (a[i] == b[i] || a[i] == b[j] || a[j] == b[i] || a[j] == b[j] || b[i] == b[j]) ans++;
      	else ans += 2;
      }
      cout << ans;
      
      return 0;
}