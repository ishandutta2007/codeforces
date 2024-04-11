#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0);
      
      int n;
      cin >> n;
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i];
      }
      int m;
      cin >> m;
      vector<int> b(m);
      for (int i = 0; i < m; i++) {
            cin >> b[i];
      }
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      int i = 0;
      int j = 0;
      int ans = 0;
      while (i < n && j < m) {
            if (abs(a[i] - b[j]) < 2) {
                  ans++;
                  i++;
                  j++;
            } else if (a[i] > b[j]) {
                  j++; 
            } else {i++;}
      }
      cout << ans;
}