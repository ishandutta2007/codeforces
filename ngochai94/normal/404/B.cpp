#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

long double a, d;
int n;

int main() {
  ios::sync_with_stdio(false);
  long double cur = 0;
  cin >> a >> d >> n;
  while (n--) {
    cur += d;
    // BUG(cur);
    long double tmp = cur - ((int)(cur / (4 * a))) * (4 * a);
    // BUG(tmp);
    if (tmp <= a) cout << setprecision(11) << tmp << ' ' << 0 << endl;
    else if (tmp <= 2 * a) cout << setprecision(11) << a << ' ' << tmp - a << endl;
    else if (tmp <= 3 * a) cout << setprecision(11) << 3 * a - tmp << ' ' << a << endl;
    else cout << setprecision(11) << 0 << ' ' << 4 * a - tmp << endl;
    cur = tmp;
  }
}