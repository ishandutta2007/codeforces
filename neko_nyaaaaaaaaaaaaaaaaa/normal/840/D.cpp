/*
      https://codeforces.com/contest/840/problem/D

      - We have queries of the form [L, R, K]. Let ceil((R - L + 1)/K) be F, which is the required frequency. Consider these two solutions:
            + For each query, we will iterate from L to R, finding the smallest number with frequency at least F.
            + Iterate from 1 to N, create prefix sum frequency for each number in O(N). Now we can answer each query in O(1).

      - Both of these solutions are O(N^2), which will get TLE. Let's notice a few characteristics for each solution:
            + Solution 1 works very well on queries with short length.
            + For queries of longer length, the required frequency is higher. We can't have too many numbers with high frequency in the array.

      - We will now combine these inefficient solutions to make an efficient one:
            + For numbers with frequency more than sqrt(N), we will use solution 2. We won't be doing this more than sqrt(N) times.
            + For queries with length <= K*sqrt(N), we will use solution 1. The complexity won't exceed O(Q*sqrt(N)*K).

      - The asymptote may look high, but with careful implementation, it can pass the 2500ms TL.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, q; cin >> n >> q;
      vector<int> a(n+1);
      vector<int> freq(n+1);
      for (int i = 1; i <= n; i++) {
            cin >> a[i]; freq[a[i]]++;
      }

      vector<int> l(q), r(q), k(q), ans(q, 500000);
      for (int i = 0; i < q; i++) {
            cin >> l[i] >> r[i] >> k[i];
      }

      for (int t = 1; t <= n; t++) {
            if (freq[t] <= 500) continue;

            vector<int> pr(n+1);
            for (int i = 1; i <= n; i++) {
                  pr[i] = pr[i-1] + (a[i] == t);
            }

            for (int i = 0; i < q; i++) {
                  int len = r[i] - l[i] + 1;
                  if (k[i] * (pr[r[i]] - pr[l[i] - 1]) > len) {
                        ans[i] = min(ans[i], t);
                  }
            }
      }

      fill(freq.begin(), freq.end(), 0);
      for (int i = 0; i < q; i++) {
            int len = r[i] - l[i] + 1;
            if (len >= 500*k[i]) continue;

            for (int j = l[i]; j <= r[i]; j++) {
                  freq[a[j]]++;
            }

            for (int j = l[i]; j <= r[i]; j++) {
                  if (freq[a[j]]*k[i] > len) {
                        ans[i] = min(ans[i], a[j]);
                  }
                  freq[a[j]] = 0;
            }
      }

      for (int i = 0; i < q; i++) {
            if (ans[i] == 500000) cout << "-1\n";
            else cout << ans[i] << '\n';
      }

      return 0;
}