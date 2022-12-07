#include<bits/stdc++.h>

using namespace std;

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  vector<long long> a(n);
  for(long long &x : a) cin >> x;

  long long ans = 1;

  set<long long> done;

  for(int it = 0; it < 13; ++it){
    long long cur = a[rng() % n];
    if(done.count(cur)) {
      continue;
    }
    done.insert(cur);

    vector<long long> divisors;

    for(long long i = 1; i * i <= cur; ++i) {
      if(cur % i == 0) {
        divisors.push_back(i);
        if(i * i != cur) divisors.push_back(cur / i);
      }
    }

    sort(divisors.begin(), divisors.end());
    vector<int> f(divisors.size());

    for(auto &x : a) {
      long long y = __gcd(x, cur);
      if(y < ans) continue;
      int fpos = lower_bound(divisors.begin(), divisors.end(), y) - divisors.begin();
      ++f[fpos];
    }

    for(int i = divisors.size() - 1; i >= 0; --i) {
      if(divisors[i] < ans) {
        break;
      }
      int cnt = 0;
      for(int j = i; j < divisors.size(); ++j){
        if(divisors[j] % divisors[i] == 0) cnt += f[j];
      }
      if(cnt * 2 >= n) {
        ans = max(ans, divisors[i]);
      }
    }
  }

  cout << ans << endl;

  return 0;
}