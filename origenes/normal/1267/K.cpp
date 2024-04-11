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

const int N = 2123456;
const int INF = int(1e9);

LL x;
LL C[25][25];

int main() {
    for (int i = 0; i <= 20; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    vector<int> tmp = { 0, 0, 0, 0, 2, 3, 3, 4 };
//    int tot = 0;
//    while (next_permutation(all(tmp))) {
//        bool ok = true;
//        for (int i = 0; i < tmp.size(); ++i) {
//            if (tmp[i] > i + 1) { ok = false; break; }
//        }
//        if (ok) {
//            ++tot;
//            int cur =
//        }
//    }

    int T;
    cin >> T;

    while (T--) {
        cin >> x;
        vector<int> cnt(25);
        int n = 0;

        for (int i = 2; ; ++i) {
            if (x == 0) break;
            ++n;
            ++cnt[x % i];
            x /= i;
        }

        LL ans = 1;
        int alr = 0;
        for (int i = n; i >= 0; --i) {
            if (cnt[i] == 0) continue;
            ans *= C[min(n - i + 1, n) - alr][cnt[i]];
            alr += cnt[i];
        }

        if (cnt[0]) {
            LL tot = 1;
            alr = 1;
            for (int i = n; i >= 1; --i) {
                if (cnt[i] == 0) continue;
                int cur = min(n - i + 1, n) - alr;
                if (cur < cnt[i]) { tot = 0; break; }
                tot *= C[cur][cnt[i]];
                alr += cnt[i];
            }
            ans -= tot;
        }
        cout << ans - 1 << '\n';
    }
    return 0;
}