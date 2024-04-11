#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool comp(ll a, ll b) {
      ll x = a, y = b;
      int c = 0, d = 0;
      while (x % 3 == 0) {
            x /= 3;
            c++;
      }
      while (y % 3 == 0) {
            y /= 3;
            d++;
      }

      if (c == d) {return (x < y);}
      return (c > d);
}

int main() {
      ios::sync_with_stdio(0);

      int n;
      cin >> n;
      vector<ll> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i];
      }
      sort(a.begin(), a.end(), comp);

      for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
      }

      return 0;
}