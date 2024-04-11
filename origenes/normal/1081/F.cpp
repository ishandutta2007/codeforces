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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

inline int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int ret;
    cin >> ret;
    return ret;
}

const int maxn = 312;

int n, t, ans[maxn];

int main() {
    cin >> n >> t;
    int cur = t;
    FOR(i, 1, n - 1) {
        REP(it, 32) {
            int now = ask(i + 1, n);
            if (now != n - t || it == 31) {
                int tmp = it & 1 ? (n - i - (t - now)) / 2 : (n - i + (t - now)) / 2;
                ans[i] = cur - tmp;
                t = it & 1 ? now : ask(i + 1, n);
                break;
            } else t = now;
        }
        cur -= ans[i];
    }
    ans[n] = cur;
    cout << "! ";
    FOR(i, 1, n) cout << ans[i];
    cout << endl;
}