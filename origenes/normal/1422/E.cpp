#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112345;

char s[maxn], nex[maxn];
int n;
int len[maxn];
string ans[maxn];

string build(const string &t) {
  if (t.size() <= 10) {
    string x = t;
    reverse(all(x));
    return x;
  }
  string x;
  REP(i, 5) x += t[t.size() - 1 - i];
  x += string("...") + t[1] + t[0];
  return x;
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  string suf;
  char nxt = 0;
  bool ok = false;
  ROF(i, n - 1, 0) {
    if (suf.empty()) {
      suf += s[i];
      ok = true;
    } else if (suf.back() == s[i]) {
      if (nxt <= s[i] && ok) {
        suf.pop_back();
        nxt = nex[i + 2];
        ok = false;
      } else {
        suf += s[i];
        ok = true;
      }
    } else {
      nxt = suf.back();
      suf += s[i];
      ok = true;
    }
    len[i] = suf.size();
    ans[i] = build(suf);
    nex[i] = nxt;
  }
  REP(i, n) printf("%d %s\n", len[i], ans[i].c_str());
}