#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int s, x1, x2, t1, t2, p, d;

int f(int st, int en, int dir) {
  if (dir == 1) {
    if (en >= st) return (en - st) * t1;
    else return (s - st + s - en) * t1;
  } else {
    if (en <= st) return (st - en) * t1;
    else return (en + st) * t1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
  int ans = abs(x1 - x2) * t2;
  int tmp = f(p, x1, d);
  if (d == 1 && x1 >= p || d == -1 && x1 <= p) d = d;
  else d = -d;
  tmp += f(x1, x2, d);
  cout << min(ans, tmp);
}