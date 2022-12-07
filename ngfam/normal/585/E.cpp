#include <bits/stdc++.h>

using namespace std;

const int N = 500050;
const int M = 10000010;
const int mod = 1e9 + 7;

int n;
int a[N];
int of[M];
int pw_2[N];
int mobius[M];
int p_count[M];
int high_prime[M];

long long if_delete[M];

vector < pair < int, int > > factors(int x) {
  vector < pair < int, int > > risan;
  while(x > 1) {
    if(risan.size() && high_prime[x] == risan.back().first) risan.back().second++;
    else risan.emplace_back(high_prime[x], 1);
    x /= high_prime[x];
  }
  return risan;
}

int sz;
int divisors[N];

void backtrack(int i, int d, vector < pair < int, int > > &v) {
  if(i == v.size()) {
    divisors[sz++] = d;
    return;
  }
  for(int j = 0; j <= v[i].second; ++j) {
    backtrack(i + 1, d, v);
    d *= v[i].first;
  }
}

void work(int x) {
  vector < pair < int, int > > w = factors(x);
  sz = 0;
  backtrack(0, 1, w);
}

int main(){

  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++of[a[i]];
  }

  pw_2[0] = 1;
  for(int i = 1; i <= n; ++i) {
    pw_2[i] = pw_2[i - 1] + pw_2[i - 1];
    pw_2[i] %= mod;
  }

  for(int i = 1; i < M; ++i) mobius[i] = 1;

  for(int i = 1; i < M; ++i) {
    int is_prime = (i > 1 && high_prime[i] == 0);
    for(int j = i; j < M; j += i) {
      p_count[i] += of[j];
      if(is_prime && (j / i) % i == 0) mobius[j] = 0;
      if(is_prime) high_prime[j] = i, mobius[j] *= -1;
    }
  }

  long long subset = 0;
  for(int i = 1; i < M; ++i) {
    subset += mobius[i] * (pw_2[p_count[i]] - 1);
    subset += mod;
    while(subset >= mod) subset -= mod;
  }

  for(int i = 1; i < M; ++i) {
    if(mobius[i] == 0) continue;
    for(int j = i; j < M; j += i) {
      if_delete[j] += mobius[i] * (pw_2[p_count[i]] - pw_2[p_count[i] - 1]);
      if_delete[j] += mod;
      while(if_delete[j] >= mod) if_delete[j] -= mod;
    }
  }


  long long risan = 0;

  for(int i = 1; i <= n; ++i) {
    work(a[i]);
    long long ans = 0;
    for(int j = 0; j < sz; ++j) {
      int x = divisors[j];
      ans += (pw_2[(p_count[x] - 1)] - 1) * mobius[x];
      ans += mod;
      ans %= mod;
    }

    risan += ans - (subset - if_delete[a[i]]);
    risan %= mod;
  }

  cout << (risan + 1LL * mod * mod) % mod << endl;

  return 0;
}