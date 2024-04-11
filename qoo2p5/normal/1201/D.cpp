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

const int N = (int) (2e5 + 123);

int n, m, k, q;
ll pos[N][2];
ll dp[N][2];
vector<ll> s;

vector<ll> get(ll x) {
    auto it = lower_bound(s.begin(), s.end(), x);
    vector<ll> res;
    if (it != s.end()) {
        res.push_back(*it);
    }
    if (it != s.begin()) {
        --it;
        res.push_back(*it);
    }
    return res;
}

void run() {
    rep(i, 0, N) {
        pos[i][0] = LINF;
        pos[i][1] = -LINF;
        dp[i][0] = LINF;
        dp[i][1] = LINF;
    }
    cin >> n >> m >> k >> q;
    vector<ll> lines = {1};
    pos[1][0] = pos[1][1] = 1;
    rep(i, 0, k) {
        ll r, c;
        cin >> r >> c;
        maxi(pos[r][1], c);
        mini(pos[r][0], c);
        lines.push_back(r);
    }
    sort(all(lines));
    lines.resize(unique(all(lines)) - lines.begin());
    s.resize(q);
    rep(i, 0, q) {
        cin >> s[i];
    }
    sort(all(s));
    s.resize(unique(all(s)) - s.begin());
    dp[1][0] = (pos[1][1] - 1) * 2;
    dp[1][1] = pos[1][1] - 1;
    rep(i, 0, sz(lines) - 1) {
        ll cur = lines[i];
        ll nxt = lines[i + 1];
        rep(d1, 0, 2) {
            rep(d2, 0, 2) {
                ll cur_x = pos[cur][d1];
                ll nxt_x = pos[nxt][!d2];
                for (ll safe : get(cur_x)) {
                    mini(dp[nxt][d2], dp[cur][d1] + abs(cur_x - safe) + abs(safe - nxt_x) + pos[nxt][1] - pos[nxt][0]);
                }
            }
        }
    }
    
    cout << min(dp[lines.back()][0], dp[lines.back()][1]) + lines.back() - 1 << "\n";
}