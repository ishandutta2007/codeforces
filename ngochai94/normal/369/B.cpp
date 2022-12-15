#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.0000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, k, l, r, sall, sk;

 int main(){
  ios::sync_with_stdio(0);
  cin >> n >> k >> l >> r >> sall >> sk;
  n -= k;
  sall -= sk;
  if (n) {
    REP (i, sall % n) cout << (n - 1 + sall) / n << ' ';
    REP (i, n - sall % n) cout << (sall) / n << ' ';
  }
  REP (i, sk % k) cout << (k - 1 + sk) / k << ' ';
  REP (i, k - sk % k) cout << sk / k << ' ';
}