#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(long long)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto i:x) cout << i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n;
string s;
char ud, lr;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> s;
  int ans = 1;
  ud = ' ';
  lr = ' ';
  for (char c: s) {
    // BUG(c);
    if (c == 'U' || c == 'D') {
      if (ud != ' ' && ud != c) {
        ans++;
        lr = ' ';
      }
        ud = c;
    } else {
      if (lr != ' ' && lr != c) {
        ans++;
        ud = ' ';
      }
        lr = c;
    }
    // BUG(ans);
    // BUG(ud);
    // BUG(lr);
  }
  cout << ans;
}