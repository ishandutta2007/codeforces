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

int vst[4], bull, b, c, lis[4];
vector<int> ans;

int f(int x) {
  if (x == 4) {
    REP (i, 4) cout << lis[i];
    cout << endl;
    cout.flush();
    cin >> b >> c;
    if (b == 4) return 1;
    return 0;
  }
  REP (i, 4) if (!vst[i]) {
    vst[i] = 1;
    lis[x] = ans[i];
    if (f(x + 1)) return 1;;
    vst[i] = 0;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  bull = 0;
  REP (digit, 10) {
    REP (i, 4) cout << digit;
    cout << endl;
    cout.flush();
    cin >> b >> c;
    if (b + c == 1) ans.pb(digit);
  }
  f(0);
}