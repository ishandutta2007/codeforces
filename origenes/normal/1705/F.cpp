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

int ask(const string &s) {
  cout << s << endl;
  int ret; cin >> ret;
  return ret;
}

int main() {
  int n; cin >> n;
  string a(n, 'F'), b(a);
  for (int i = 1; i < n; i += 2) b[i] = 'T';
  int ra = ask(a), rb = ask(b);
  string ans(n, ' ');
  for (int i = 0; i < n; i += 3) {
    string q = a;
    if (i + 3 >= n) {
      q[i] = 'T';
      int now = ask(q) - ra;
      ans[i] = now == 1 ? 'T' : 'F';
      i -= 2;
      continue;
    }
    q[i] = q[i + 1] = q[i + 2] = 'T';
    int now = ask(q) - ra;
    if (now == 3 || now == -3) {
      ans[i] = ans[i + 1] = ans[i + 2] = now == 3 ? 'T' : 'F';
      continue;
    }
    q = b;
    q[i] = q[i] == 'T' ? 'F' : 'T';
    q[i + 1] = q[i + 1] == 'T' ? 'F' : 'T';
    int now2 = ask(q) - rb;
    if (now2 == 2 || now2 == -2) {
      ans[i] = now2 == 2 ? q[i] : b[i];
      ans[i + 1] = now2 == 2 ? q[i + 1] : b[i + 1];
      ans[i + 2] = now == 1 ? 'T' : 'F';
    } else {
      ans[i] = ans[i + 1] = now == 1 ? 'T' : 'F';
      ans[i + 2] = now == 1 ? 'F' : 'T';
    }
  }
  ask(ans);
}