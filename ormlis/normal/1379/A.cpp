#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;


const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string x = "abacaba";

    auto check = [&] (int j, int e) {
        if (j + x.size() > n) return false;
        for(int i = j; i < j + x.size(); ++i) {
            if (i - e >= 0 && i - e < x.size()) {
                if (x[i-e] != x[i-j]) return false;
            } else {
                if (s[i] != x[i - j]) return false;
            }
        }
        return true;
    };

    range(i, n - x.size() + 1) {
        bool bad = false;
        for(int e = i; e < i + x.size(); ++e) {
            if (s[e] != '?' && s[e] != x[e-i]) bad = true;
        }
        if (bad) continue;
        int cnt = 0;
        range(j, n - x.size() + 1) {
            if (check(j, i)) cnt++;
            if (cnt > 1) break;
        }
        if (cnt == 1) {
            cout << "Yes\n";
            range(e, x.size()) s[i+e] = x[e];
            range(e, n) if (s[e] == '?') s[e] = 'z';
            cout << s << "\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}