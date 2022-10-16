#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); --(i))
#define REP(i, n) FOR(i, 0, (n) - 1)
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
using LL = long long;
using ll = long long;
using pii = pair<int, int>;

const int N = 1123;

string ans[N];
int n, k, l;
string dic;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l >> k;
    cin >> dic;
    sort(all(dic));

    int pos = 0, up = 1;

    for (int i = 0; i < l; ++i) {
        for (int j = up; j <= k; ++j) ans[j].pb(dic[pos++]);
        for (int j = k - 1; j >= up; --j) {
            if (ans[j].back() != ans[k].back()) {
                up = j + 1;
                break;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        while (ans[i].length() < l) ans[i].pb(dic[pos++]);
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
    return 0;
}