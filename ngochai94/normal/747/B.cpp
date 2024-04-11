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

int n, a, b, c, d;
string s;

int main() {
  // ios::sync_with_stdio(false);
  cin >> n >> s;
  if (n % 4 != 0) {
    cout << "===";
    return 0;
  }
  for (char cc: s) {
    if (cc == 'A') a++;
    else if (cc == 'C') c++;
    else if (cc == 'G') b++;
    else if (cc == 'T') d++;
  }
  n /= 4;
  if (a > n || b > n || c > n || d > n) {
    cout << "===";
    return 0;
  }
  // cout << a << b << c << d;
  REP (i, s.size()) if (s[i] == '?') {
    if (a++ < n) s[i] = 'A';
    else if (b++ < n) s[i] = 'G';
    else if (c++ < n) s[i] = 'C';
    else if (d++ < n) s[i] = 'T';
    else {
      cout << "===";
      return 0;
    }
  }
  cout << s;
}