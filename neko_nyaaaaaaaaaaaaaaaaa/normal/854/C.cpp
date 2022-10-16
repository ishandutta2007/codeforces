#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0);
      
      ll n, k;
      cin >> n >> k;
      vector<pair<ll, ll>> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
      }
      
      // max from heap
      
      priority_queue<pair<ll, ll>> q;
      for (int i = 0; i < k; i++) {
            q.push(a[i]);
      }
      
      ll pt = k+1;
      vector<ll> ans(n);
      for (int i = k; i < n; i++) {
            q.push(a[i]);
            pair<ll, ll> p = q.top();
            ans[p.second] = pt;
            pt++;
            q.pop();
      }
      
      while (q.size()) {
            pair<ll, ll> p = q.top();
            ans[p.second] = pt;
            pt++;
            q.pop();
      }
      
      // end of heap, calculating ans
      
      ll anss = 0;
      for (int i = 0; i < n; i++) {
            anss += (ans[i] - i - 1)*a[i].first;
      }
      cout << anss << endl;
      for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
      }
      
      return 0;
}