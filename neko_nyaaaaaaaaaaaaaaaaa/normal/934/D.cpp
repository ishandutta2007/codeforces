#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0);
      
      ll p, k, a;
      vector<ll> ans;
      cin >> p >> k;
      while (p) {
            a = p % k;
      	while (a < 0) {a += k;}
            ans.push_back(a);
            p -= a;
            p /= -k;
      }
      cout << ans.size() << endl;
      for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
      }
      
}