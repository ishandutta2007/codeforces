#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAXN = 100000;

long double A[MAXN];

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
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  long double ans = 0;
  long double pref1 = 0;
  for (int i = 0; i < n; ++i){
    ans += pref1 * A[i];
    pref1 = A[i] * (pref1 + 1);
  }
  ans *= 2;
  for (int i = 0; i < n; ++i)
    ans += A[i];
  cout << setprecision(30) << ans << '\n';
  return 0;
}