#include <bits/stdc++.h>
#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int n, v, last;
long long sum1, sum2;
vector <long long> a, b;

int main() {
  ios_base::sync_with_stdio(0);
 // fi, fo;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> v;
    if(v > 0) {
      a.push_back(v);
      sum1 += v;
    }
    else {
      b.push_back(-v);
      sum2 -= v;
    }
    if(i == n) last = v;
  }
  if(sum1 != sum2) {
    if(sum1 < sum2) cout << "second";
    else cout << "first";
    return 0;
  }
  for(int i = 0; i < min((int)a.size(), (int)b.size()); i++)
  if(a[i] != b[i]) {
    if(a[i] < b[i]) cout << "second";
    else cout << "first";
    return 0;
  }
  if(last < 0) cout << "second";
  else cout << "first";
  return 0;
}