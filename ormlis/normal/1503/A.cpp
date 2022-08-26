#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;

const int INFi = 2e9 + 5;
const int maxN = 3e5 + 100;
const int md = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int b1 = 0;
    int b2 = 0;
    string a;
    string b;
    int c11 = 0, c21 = 0;
    int ost = 0;
    for(auto &x : s) if (x == '0') ost++;
    for(auto &x : s) {
        if (x == '1') {
            if (c11 + c21 + ost + 2 > n) {
                a += ')';
                b += ')';
                b1--;
                b2--;
            } else {
                c11++;
                c21++;
                b1++;
                b2++;
                a += '(';
                b += '(';
            }
        } else {
            if (b1 < b2) {
                a += '(';
                b += ')';
                b1++;
                b2--;
            } else {
                b += '(';
                a += ')';
                b1--;
                b2++;
            }
        }
        if (b1 < 0 || b2 < 0) {
            cout << "NO\n";
            return;
        }
    }
    if (b1 != 0 || b2 != 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n" << a << "\n" << b << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}