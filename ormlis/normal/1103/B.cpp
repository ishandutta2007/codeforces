#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;
using namespace std;


void solve() {
    string s;
    cin >> s;
    if (s == "mistake" || s == "end") {
        exit(0);
    }
    auto check = [&](int a, int b) {
        cout << "? " << a << " " << b << endl;
        char t;
        cin >> t;
        return t == 'x';
    };
    if (check(0, 1)) {
        cout << "! 1" << endl;
        return;
    }
    int l, r;
    for (int i = 0; i < 30; ++i) {
        if (check(1 << i, 1 << (i + 1))) {
            l = 1 << i;
            r = (l << 1) + 1;
            break;
        }
    }
    r = min(r, (int)1e9 + 1);
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid, mid * 2)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << "! " << l << endl;

}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int tests = 1;
    // cin >> tests;
    while (true) {
        solve();
    }

    //print((__int128)1e10);
    return 0;
}