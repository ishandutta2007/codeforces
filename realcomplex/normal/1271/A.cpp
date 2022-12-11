#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  swap(b,d);
  a = min(a, b);
  c = min(c, b);
  d = min(d, b);
  c = min(c, d);
  int ans = 0;
  for(int i = 0; i <= a; i ++ ){
    ans = max(ans, i * e + min(b - i, c) * f);
  }
  cout << ans << "\n";
  return 0;
}