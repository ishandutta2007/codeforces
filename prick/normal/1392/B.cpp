#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

vector<int> process(vector<int> a) {
    int d = *max_element(a.begin(), a.end());
    for (int i = 0; i < sz(a); ++i) {
        a[i] = d - a[i];
    }
    return a;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a = process(a);
    vector<int> b = process(a);
    if (k % 2 == 1) {
        b = a;
    }
    for (auto i: b) {
        cout << i << ' ';
    }
    cout << '\n';
}

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    cerr << T << endl;
    for (int i = 0; i < T; ++i) {
        solve();
    }
}