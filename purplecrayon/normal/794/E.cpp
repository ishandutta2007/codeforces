#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;


struct RMQ {
    static constexpr int L = 19;
    vector<int> lg;
    vector<vector<int>> t;
    RMQ(const vector<int>& a) {
        t.resize(L);
        lg.resize(sz(a) + 1);

        t[0] = a;
        lg[1] = 0;
        for (int i = 2; i <= sz(a); i++) lg[i] = lg[i / 2] + 1;
        for (int i = 1; i < L; i++) {
            t[i].resize(sz(a));
            for (int j = 0; j + (1 << i) <= sz(a); j++) {
                t[i][j] = max(t[i-1][j], t[i-1][j + (1 << (i - 1))]);
            }
        }
    }
    int qry(int l, int r) {
        int k = lg[r - l + 1], K = 1 << k;
        int ans = max(t[k][l], t[k][r - K + 1]);
        return ans;
        /*
        int x = -1;
        for (int i = l; i <= r; i++) x = max(x, t[i]);
        return x;
        */
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    if (n == 1) {
        cout << a[0] << '\n';
        return;
    }
    vector<int> ev(n-1), odd(n);
    for (int i = 0; i < n; i++) {
        if (i < n-1) ev[i] = max(a[i], a[i+1]);
        if (i == 0 || i == n-1) {
            odd[i] = a[i];
        } else {
            odd[i] = min(a[i], max(a[i-1], a[i+1]));
        }
    }
    RMQ oddQry(odd), evQry(ev);
    for (int k = 0; k < n; k++) {
        if (k == n-1) {
            cout << *std::max_element(a.begin(), a.end()) << ' ';
            break;
        }
        bool par = (n - k) % 2;
        if (par) {
            if (n % 2 == 0) {
                // after k you can have 2 * k - 1
                int len = k + 1;
                int L = n / 2 - len / 2;
                int R = n / 2 + len / 2 - 1;
                // cerr << k << ' ' << L << ' ' << R << endl;
                cout << oddQry.qry(L, R) << ' ';
            } else {
                int L = n / 2 - k / 2;
                int R = n / 2 + k / 2;
                // cerr << k << ' ' << L << ' ' << R << endl;
                cout << oddQry.qry(L, R) << ' ';
            }
        } else {
            if (n % 2 == 0) {
                int L = n / 2 - 1 - k / 2, R = n / 2 + k / 2; R--;
                cout << evQry.qry(L, R) << ' ';
            } else {
                int L = n / 2, R = n / 2;
                L -= (k + 1) / 2; R += k / 2;
                cout << evQry.qry(L, R) << ' ';
            }
        }
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

// first maximizes
// binary search on answer, you have 0's and 1's (1 means >= x)
// first wins iff
//  n % 2 == 0: at least one middle numbers -> max(two middle numbers)
//  n % 2 == 1: middle number is 1 and n > 1 ? some other number > 1 -> min(middle, max(one left, one right)) 
//  n == 1: original number
//
//
//  x x x _ x
//  _ _ _ _
//  _ _ _ _ _
//
//
//  _ _ _ _ _ _ _