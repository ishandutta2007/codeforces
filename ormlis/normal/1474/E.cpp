#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

//using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "1\n";
        cout << "2 1\n";
        cout << "1\n";
        cout << "1 2\n";
        return;
    }
    if (n == 3) {
        cout << "5\n";
        cout << "2 3 1\n";
        cout << "2\n";
        cout << "2 1\n";
        cout << "1 3\n";
        return;
    }
    vector<pair<int, int>> answ;
    vector<int> p(n);
    p[0] = n - 2;
    p[n - 1] = 1;
    int l = 2, r = n - 3;
    ll answer = 1ll * (n - 2) * (n - 2) * 2;
    answ.emplace_back(n - 2, 0);
    answ.emplace_back(1, n - 1);
    range(i, n) {
        if (r - l == -1) {
            p[l - 1] = 0;
            p[r + 1] = n - 1;
            break;
        }
        if (i % 2) {
            p[r + 1] = r;
            answer += 1ll * r * r;
            answ.emplace_back(r, 0);
            r--;
        } else {
            p[l - 1] = l;
            answ.emplace_back(l, n - 1);
            answer += 1ll * (n - 1 - l) * (n - 1 - l);
            l++;
        }
    }
    answer += 1ll * (n - 1) * (n - 1);
    answ.emplace_back(0, n - 1);
    cout << answer << '\n';
    for (auto &i : p) cout << i + 1 << ' ';
    cout << '\n';
    cout << answ.size() << '\n';
    for (auto &[x, y] : answ) cout << x + 1 << ' ' << y + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}