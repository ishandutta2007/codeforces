#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<int> numbers;
  for(int len = 1; len <= 9; ++len) {
    for(int mask = 0; mask < (1 << len); ++mask){
      int cur = 0;
      for(int i = 0; i < len; ++i) {
        cur *= 10; cur += 4;
        if(mask & (1 << i)) cur += 3;
      }
      numbers.push_back(cur);
    }
  }

  int ans = 0;
  int m = max(1, n - 15), len = n - m + 1;
  for(int x : numbers) if(x < m) ans++;

  vector<long long> fact(len + 5);

  fact[0] = 1;
  for(int i = 1; i < fact.size(); ++i) {
    fact[i] = fact[i - 1] * i;
  }

  vector<int> rem;
  for(int i = n - len + 1; i <= n; ++i) rem.push_back(i);

  if(k > fact[len]) {
    cout << -1 << endl;
    return 0;
  }

  for(int i = 1; i <= len; ++i) {
    int pos = n - len + i;
    int id = (k - 1) / fact[len - i];
    k -= fact[len - i] * id;

    int num = rem[id], flag = 0;

    vector<int> newrem;
    for(int j = 0; j < rem.size(); ++j) if(j != id) newrem.push_back(rem[j]);
    rem = newrem;

    for(int x : numbers) {
      flag += (x == pos) + (x == num);
    }

    ans += (flag == 2);
  }

  cout << ans << endl;

  return 0;
}