#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORN(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BUG(x) cerr << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl;}
#define PB push_back
#define MP make_pair
#define BIT(s,i) (((s)&(1<<(i)))>0)
#define TWO(x) (1<<(x))
#define FI first
#define SE second
#define SZ(x) ((int)x.size())

const int MOD = 1000000007;
const double E = 1e-8;
const double PI = acos(-1);
const int NMAX = 1000;

int n;
vector<pii> s;

int main() {
  cin >> n;
  s.PB(pii(1, 2*MOD));
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    int pos = -1;
    REP (i, SZ(s)) if (s[i].FI <= u && u + v - 1 <= s[i].SE) {
      pos = i;
      break;
    }

    if (pos != -1) {
      pii tmp = s[pos];
      s.erase(s.begin() + pos);
      if (tmp.FI <= u - 1) s.PB(pii(tmp.FI, u - 1));
      if (u + v <= tmp.SE) s.PB(pii(u + v, tmp.SE));
      cout << u << " " << u + v - 1 << endl;
      continue;
    }

    REP (i, SZ(s)) if (s[i].SE - s[i].FI + 1 >= v) {
      if (pos == -1 || s[pos].FI > s[i].FI) pos = i;
    }
    pii tmp = s[pos];
    s.erase(s.begin() + pos);
    cout << tmp.FI << " " << tmp.FI + v - 1 << endl;
    if (tmp.FI + v <= tmp.SE) s.PB(pii(tmp.FI + v, tmp.SE));
  }


}