#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*
    change null_type to int if we want to use map instead
    find_by_order(k) returns an iterator to the k-th element (0-indexed)
    order_of_key(k) returns numbers of item being strictly smaller than k
*/
template<typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 200010;
const int MOD = 998244353;

int n;
int a[N];
long long sum[N];
long long sum2[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum[i] = sum[i - 1] + a[i];
      sum2[i] = a[i];
      if (i > 1) sum2[i] += sum2[i - 2];
    }
    long long tot = sum[n];
    long long res = 0;
    // 1111...0000
    for (int i = 1; i <= n; i++) {
      long long now = tot - sum[i];
      if (now * 2 < tot) {
        res++;
      }
    }

    // ([0] > 0) ([10] >= 0) ([1] > 0) 0?
    ordered_set<long long> vals[2];
    for (int i = 2; i <= n; i++) {
      // update 
      vals[i % 2].insert(sum[i - 1] - sum2[i - 1]);
      
      // get
      // ends with 0
      long long lim = (tot + 1) / 2;
      lim -= sum2[i - 1];
      lim -= a[n];
      if (i < n) res += vals[i % 2].order_of_key(lim);
      // ends without 0
      lim = (tot + 1) / 2;
      lim -= sum2[i - 1];
      res += vals[i % 2].order_of_key(lim);
    }

    // 1 ([0] > 0) ([10] >= 0) ([1] > 0) 0?
    vals[0].clear();
    vals[1].clear();
    for (int i = 3; i <= n; i++) {
      // update
      // cout << "# " << i << endl;
      // cout << "add " << sum[i - 1] - sum2[i - 1] << endl;
      vals[i % 2].insert(sum[i - 1] - sum2[i - 1]);

      // get
      // ends with 0
      long long lim = (tot + 1) / 2;
      lim -= sum2[i - 1];
      lim -= a[n];
      lim += a[1];
      // cout << lim << endl;
      if (i < n) res += vals[i % 2].order_of_key(lim);
      // ends without 0
      lim = (tot + 1) / 2;
      lim -= sum2[i - 1];
      lim += a[1];
      res += vals[i % 2].order_of_key(lim);
      // cout << lim << endl;
    }

    cout << res % MOD << '\n';
  }  
  return 0;
}