#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> primes;
    vector<int> divisors;
    {
      int n = N;
      for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
          primes.emplace_back(i);
        }
        while (n % i == 0) {
          n /= i;
        }
      }
      if (n > 1) {
        primes.emplace_back(n);
      }
    }
    for (int i = 1; i * i <= N; i++) {
      if (N % i == 0) {
        if (i > 1) {
          divisors.emplace_back(i);
        }
        if (i != N / i && N / i > 0) {
          divisors.emplace_back(N / i);
        }
      }
    }

    vector<int> ans;
    if (primes.size() == 1) {
      ans = divisors;
    } else if (primes.size() == 2) {
      vector<int> border;
      vector<int> p1, p2;
      for (auto d : divisors) {
        if (d % primes[0] == 0 && d % primes[1] == 0) {
          border.emplace_back(d);
        } else {
          if (d % primes[0] == 0) {
            p1.emplace_back(d);
          } else if (d % primes[1] == 0) {
            p2.emplace_back(d);
          }
        }
      }
      if (!border.empty()) {
        p1.emplace_back(border.back());
        border.pop_back();
      }
      while (!border.empty()) {
        p2.emplace_back(border.back());
        border.pop_back();
      }
      for (auto i : p1) {
        ans.emplace_back(i);
      }
      for (auto i : p2) {
        ans.emplace_back(i);
      }
    } else {
      vector<int> need;
      vector<vector<int>> vals;
      for (int i = 0; i < (int) primes.size(); i++) {
        need.emplace_back(primes[i]);
        vals.emplace_back();
      }
      vector<int> nd;
      for (auto d : divisors) {
        bool used = false;
        for (int i = 0; i < (int) primes.size(); i++) {
          if (primes[i] * primes[(i + 1) % primes.size()] == d) {
            used = true;
          }
        }
        if (!used) {
          nd.emplace_back(d);
        }
      }
      for (int i = 0; i < (int) primes.size(); i++) {
        vector<int> nnd;
        for (auto d : nd) {
          if (d % primes[i] == 0) {
            ans.emplace_back(d);
          } else {
            nnd.emplace_back(d);
          }
        }
        nd = nnd;
        ans.emplace_back(primes[i] * primes[(i + 1) % primes.size()]);
      }
    }

    for (auto i : ans) {
      cout << i << " ";
    }
    cout << "\n";
    int cnt = 0;
    for (int i = 0; i < (int) ans.size(); i++) {
      if (__gcd(ans[i], ans[(i + 1) % ans.size()]) == 1) {
        cnt++;
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}