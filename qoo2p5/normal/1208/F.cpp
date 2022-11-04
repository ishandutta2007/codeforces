#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, t) for (int i = s; i < t; i++)
#define per(i, s, t) for (int i = s; i >= t; i--)
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);

template<typename A, typename B> bool mini(A& x, const B& y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A& x, const B& y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

bool test(int mask, int bit) {
    return mask & (1 << bit);
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(12);
    run();
    return 0;
}

const int N = 21;


int n;
int a[1 << N];
pair<int, int> dp[1 << N];

void upd(int m, int i) {
    static vector<int> t;
    t.resize(3);
    t[0] = i;
    t[1] = dp[m].first;
    t[2] = dp[m].second;
    sort(all(t));
    t.resize(unique(all(t)) - t.begin());
    assert(sz(t) >= 2);
    dp[m].first = t[sz(t) - 1];
    dp[m].second = t[sz(t) - 2];
}

void run() {
    rep(i, 0, 1 << N) {
        dp[i] = {-2, -1};
    }
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        upd(a[i], i);
    }
    per(i, (1 << N) - 1, 0) {
        rep(j, 0, N) {
            if (!test(i, j)) continue;
            upd(i ^ (1 << j), dp[i].first);
            upd(i ^ (1 << j), dp[i].second);
        }
    }
    int ans = 0;
    rep(i, 0, n) {
        int cur = 0;
        per(j, N - 1, 0) {
            if (test(a[i], j)) {
                continue;
            }
            int need = cur ^ (1 << j);
            if (dp[need].first > i && dp[need].second > i) {
                cur = need;
            }
        }
        assert((cur & a[i]) == 0);
        maxi(ans, cur | a[i]);
    }
    cout << ans << "\n";
}