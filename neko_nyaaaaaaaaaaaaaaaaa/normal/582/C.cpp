/*
      https://codeforces.com/contest/582/problem/C

      - First let's notice, a periodic subarray is "good" if for all i and j such that (i == j) mod gcd(N, S), it holds that a[j] >= a[i].
      This gives us an important detail, that is the period of each element in the subarray in relation with the original array.

      - We will iterate on the divisors of N. Let's fix this divisor and call it D.
      An array element a[i] is "good" if and only if for a[i] >= a[j] for all j such that (i == j) mod D.
      A subarray is "good" if and only if all of its elements are good.

      - Let's turn this array into a cyclic binary string, where the i-th character is 1 if a[i] is a "good" element.
      Now question becomes, how many "good" binary substrings of length S are there such that gcd(N, S) == D.

      - We can answer this question efficiently, storing all counts of subarrays. We will only add to the answers valid S.

      - The total complexity is O(N*d(N)), with d(N) being the divisor count of N. This is approximately O(NlogN)
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, gcd[200001];
vector<int> a;

void init() {
      for (int i = 1; i <= 200000; i++) {
            gcd[i] = __gcd(i, n);
      }
}

ll solve(int d) {
      vector<int> b(n+1);
      int has_zero = 0;
      for (int i = 1; i <= d; i++) {
            int mx = 0;
            for (int j = i; j <= n; j += d) {
                  mx = max(mx, a[j]);
            }
            for (int j = i; j <= n; j += d) {
                  b[j] = (mx == a[j]);
                  if (!b[j]) has_zero = 1;
            }
      }

      vector<ll> freq(n+1);
      if (!has_zero) {
            for (int i = 1; i <= n; i++) {
                  freq[i] = n;
            }
      } else {
            int start = 1;
            while (b[start]) {
                  b.push_back(1);
                  start++;
            }

            vector<int> c;
            int cnt = 0;
            for (int i = start; i < b.size(); i++) {
                  if (!b[i]) {
                        if (cnt) c.push_back(cnt);
                        cnt = 0;
                  } else {
                        cnt++;
                  }
            }
            if (cnt) c.push_back(cnt);

            for (int f: c) {
                  for (int i = f, j = 1; j <= f; i--, j++) {
                        freq[i] += j;
                  }
            }
      }

      ll ans = 0;
      for (int i = 1; i <= n; i++) {
            if (gcd[i] == d) {ans += freq[i];}
      }
      return ans;
}

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> n; a.resize(n+1); init();
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
      }

      ll ans = 0;
      for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                  ans += solve(i);
            }
      }
      cout << ans;

	return 0;
}