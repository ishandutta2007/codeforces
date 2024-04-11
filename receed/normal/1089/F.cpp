#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

pair<ll, ll> gc(ll x, ll y) {
  if (y == 0)
    return {1, 0};
  auto pp = gc(y, x % y);
  return {pp.second, pp.first - x / y * pp.second};
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n, p = -1;
  cin >> n;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) {
      p = i;
      break;
    }
  if (p == -1) {
    cout << "NO\n";
    return 0;
  }
  ll a = 1, b = n;
  while (b % p == 0) {
    a *= p;
    b /= p;
  }
  if (b == 1) {
    cout << "NO\n";
    return 0;
  }
  auto [ca, cb] = gc(a, b);
  ca = (b - ca % b) % b;
  cb = (a - cb % a) % a;
  assert(a * ca + b * cb == a * b - 1);
  cout << "YES\n";
  cout << "2\n" << ca << ' ' << b << '\n' << cb << ' ' << a << '\n';
}