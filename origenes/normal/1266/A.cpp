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

int n;
string s;

int main() {
  cin >> n;
  while (n--) {
    cin >> s;
    int zero = 0, even = 0, sum = 0;
    for (auto ch : s) {
      ch -= '0';
      if (ch == 0) zero++;
      if (ch % 2 == 0) even++;
      sum += ch;
    }
    if (zero >= 1 && even >= 2 && sum % 3 == 0) cout << "red\n";
    else cout << "cyan\n";
  }
}