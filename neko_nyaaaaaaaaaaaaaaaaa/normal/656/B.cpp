#include <bits/stdc++.h>
using namespace std;

int main() {
      
      int n;
      cin >> n;
      vector<long long> m(n), r(n);
      for (int i = 0; i < n; i++) {
      	cin >> m[i];
      }
      for (int i = 0; i < n; i++) {
      	cin >> r[i];
      }
      long long lcm = 1;
      for (int i = 0; i < n; i++) {
      	lcm = (lcm*m[i])/__gcd(lcm, m[i]);
      }
      vector<bool> check(lcm, false);
      for (int i = 0; i < n; i++) {
      	long long tmp = r[i];
      	while (r[i] < lcm) {
      		check[r[i]] = true;
      		r[i] += m[i];
      	}
      }
      double ans = 0;
      for (long long i = 0; i < lcm; i++) {
      	if (check[i]) {ans += 1;}
      } 
      ans /= lcm;
      cout << fixed << setprecision(6) << ans;
      
      return 0;
}