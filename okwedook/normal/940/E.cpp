#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, c;
ll summ = 0;
deque<ll> q;
vector<ll> a, dp;

void add(ll x) {
  while (!q.empty() && q.back() > x) q.pop_back();
  q.push_back(x);
}

void del(ll x) {
  if (q.front() == x) q.pop_front();
}

int main() {
  cin >> n >> c;
  a.resize(n + 1), dp.resize(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i], summ += a[i];
  dp[0] = 0;
  for (ll i = 1; i <= n; ++i){
    add(a[i]); 
    if (i > c) del(a[i - c]);
    dp[i] = dp[i - 1];
    if (i >= c)  dp[i] = max(dp[i], dp[i - c] + q.front());
  }
  cout << summ - dp[n];
  return 0;
}