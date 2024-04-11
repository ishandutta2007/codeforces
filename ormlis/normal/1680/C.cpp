#include <bits/stdc++.h>


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = (1 << 20) + 1;
const int LG = 30;

void solve() {
    string s;
    cin >> s;
    auto check = [&](int x) {
        int L = 0;
        int cnt0 = 0;
        int cnt1 = 0;
        for (auto &c : s) if (c == '1') cnt1++;
        for (int R = 0; R < (int) s.size(); ++R) {
            if (s[R] == '0') cnt0++;
            else cnt1--;
            while (cnt0 > x) {
                if (s[L] == '0') {
                    cnt0--;
                } else {
                    cnt1++;
                }
                L++;
            }
            if (cnt1 <= x) return true;
        }
        return false;
    };
    int L = -1, R = s.size();
    while(R - L > 1) {
        int mid = (R + L) / 2;
        if (check(mid)) {
            R = mid;
        } else {
            L = mid;
        }
    }
    cout << R << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}