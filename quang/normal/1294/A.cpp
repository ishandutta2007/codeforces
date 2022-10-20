#include <bits/stdc++.h>
 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    long long a, b, c, n;
    cin >> a >> b >> c >> n;
    n += a + b + c;
    if (n % 3) {
      cout << "NO\n";
      continue;
    }
    n /= 3;
    if (n < a || n < b || n < c) {
      cout << "NO\n";
    } else cout << "YES\n";
  }
  return 0;  
}