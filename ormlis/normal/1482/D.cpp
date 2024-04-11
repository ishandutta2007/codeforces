#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;
typedef long double ld;

using namespace std;

const int maxN = 605;
const int INFi = 2e9;
const ll INF = 1e18;
const int md = 1e9 + 7;


void solve() {
    ll cur = 1;
    ll L = 0;
    ll R = 1e14 + 1;
    int cnt = 0;
    function<ll(ll, ll)> need = [&] (ll L, ll R) {
        if (L + 1 == R) return 0ll;
        ll mid = (L + R) / 2;
        return need(L, mid) + mid;
    };
    auto ask = [&](ll X) {
        cnt++;
        //assert(cnt < 106);
        cout << "? " << X << endl;
        string res; cin >> res;
        if (res[0] == 'L') {
            cur += X;
            L = max(L, X);
        } else if (res[0] == 'F') {
            cur -= X;
            R = min(R, X);
        } else {
            assert(0);
        }
    };
    while (R - L > 1) {
        ll mid;
        if (need(L, R) <= cur) mid = (L + R) / 2;
        else mid = (2 * L + R) / 3;
        if (cur < mid) mid = cur;
        mid = max(mid, L);
        mid = min(mid, R - 1);
        ask(mid);
    }
    cout << "! " << L << endl;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}