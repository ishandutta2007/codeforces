#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
const ll INF = 2e18;

struct segment {
    int to;
    ll l, r;

    segment() : l(0), r(0), to(0) {}
};

vector<pair<ll, ll>> result;
void solve(ll l, ll r, vector<segment> &segs) {
    if (segs.empty()) return;
    ar<bool, 2> have = {false, false};
    for(auto &seg : segs) {
        have[seg.to] = true;
    }
    if (!have[0]) return;
    if (!have[1]) {
        result.emplace_back(l, r);
        return;
    }
    if (l + 1 == r) {
        cout << "-1\n";
        exit(0);
    } else {
        vector<segment> lp, rp;
        ll mid = (l + r) / 2;
        for(auto &seg : segs) {
            if (seg.l < mid) {
                lp.push_back(seg);
            }
            if (seg.r > mid) {
                rp.push_back(seg);
            }
        }
        segs.clear();
        segs.shrink_to_fit();
        solve(l, mid, lp);
        solve(mid, r, rp);
    }
}

void solve() {
    int n; cin >> n;
    vector<segment> segs(n);
    range(i, n) {
        string s; cin >> s;
        if (s[0] == '+') {
            segs[i].to = 1;
        } else {
            segs[i].to = 0;
        }
        ll num = 0;
        int e = 1;
        range(_, 4) {
            ll cur = 0;
            while(e < (int)s.size() && s[e] != '.' && s[e] != '/') {
                cur *= 10;
                cur += s[e] - '0';
                e++;
            }
            num *= 256;
            num += cur;
            e++;
        }
        ll r = num;
        if (e < (int)s.size()) {
            ll cur = 0;
            while(e < (int)s.size()) {
                cur *= 10;
                cur += s[e] - '0';
                e++;
            }
            r += 1ll << (32 - cur);
            r--;
        }
        segs[i].l = num;
        segs[i].r = r + 1;
    }
    ll N = 1ll << 32ll;
    solve(0, N, segs);
    cout << result.size() << '\n';
    for(auto &[l, r] : result) {
        vector<ll> kek;
        ll x = l;
        range(_, 4) {
            kek.push_back(x % 256);
            x /= 256;
        }
        ll need = r - l;
        ll w = 32;
        ll to = 1;
        while(to != need) {
            w--;
            to *= 2;
        }
        reverse(all(kek));
        range(i, 3) cout << kek[i] << '.';
        cout << kek[3] << '/' << w << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}