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

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, q;
  cin >> n >> q;
  string s; cin >> s;
  vector<int> zero(n), one(n);
  FOR(i, 1, n - 1) if (s[i] == s[i - 1]) {
    if (s[i] == '1') one[i]++;
    else zero[i]++;
  }
  FOR(i, 1, n - 1) {
    zero[i] += zero[i - 1];
    one[i] += one[i - 1];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    cout << max(zero[r] - zero[l], one[r] - one[l]) + 1 << '\n';
  }
}