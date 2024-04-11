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

ll n, b;
map<ll, int> facs;

int main() {
    cin >> n >> b;
    int upp = sqrt(b) + 0.5;
    FOR(i, 2, upp) while (b % i == 0) {
            b /= i;
            facs[i]++;
        }
    if (b > 1) facs[b]++;
    vector<ll> cnt;
    for (auto it : facs) {
        ll base = 1, a = it._1, now = 0;
        while (n / a >= base) {
            base *= a;
            now += n / base;
        }
        cnt.eb(now);
    }
    int it = 0;
    ll ans = 1e18 + 50;
    for (auto now : facs) {
        int one = now._2;
        ans = min(ans, cnt[it] / one);
        it++;
    }
    cout << ans;
}