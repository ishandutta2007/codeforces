#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      
      int n, m;
      cin >> n >> m;
      
      if (m > n) {cout << -1;}
      else if (m == n) {cout << n;}
      else {
      	int ans = 0;
      	while (ans*2 < n) {
      		ans += m;
      	}
      	cout << ans;
      }
      
}