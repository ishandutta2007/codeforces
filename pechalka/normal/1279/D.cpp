#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAXN = 1000000;

const long long MOD = 998244353;

long long pow(long long a, int n){
  if (n == 0)
    return 1;
  if (n % 2 == 1)
    return pow(a, n - 1) * a % MOD;
  long long tmp = pow(a, n / 2);
  return tmp * tmp % MOD;
}

long long kek[MAXN];
vector<int> A[MAXN];

int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i){
    int k;
    cin >> k;
    while (k--){
      int x;
      cin >> x;
      A[i].emplace_back(x - 1);
      ++kek[x - 1];
    }
  }
  for (int i = 0; i < MAXN; ++i)
    kek[i] = kek[i] * pow(n, MOD - 2) % MOD;
  long long sum = 0;
  for (int i = 0; i < n; ++i){
    long long tmp = 0;
    for (int x: A[i])
      tmp += kek[x];
    tmp = tmp % MOD * pow(A[i].size(), MOD - 2) % MOD;
    sum += tmp;
  }
  sum = sum % MOD * pow(n, MOD - 2) % MOD;
  cout << sum << '\n';
  return 0;
}