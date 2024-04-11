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
const int NMAX = 111;

int n, m, match[NMAX], del[NMAX];
string s[NMAX];

int main() {
  cin >> n >> m;
  FOR (i, 1, n) cin >> s[i];
  int del_size = 0;
  FOR (i, 1, m) {
    int u;
    cin >> u;
    del[u] = true;
    del_size = SZ(s[u]);
  }


  FOR (i, 1, n) if (del[i] && SZ(s[i]) != del_size) {
    cout << "No" << endl;
    return 0;
  }

  FOR (i, 1, n) if (!del[i] && SZ(s[i]) == del_size) match[i] = true;

  string res = "";
  FOR (pos, 0, del_size - 1) {
    int cnt = 0;
    char ch = ' ';
    FOR (i, 1, n) if (del[i]) {
      char c = s[i][pos];
      if (c != ch) {
        cnt++;
        ch = c;
      }
    }

    // BUG(ch);
    // BUG(cnt);

    if (cnt == 1) {
      res += ch;
      FOR (i, 1, n) if (match[i] && s[i][pos] != ch)
        match[i] = false;
    } else
      res += '?';
  }

  FOR (i, 1, n) if (match[i]) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  cout << res << endl;
}