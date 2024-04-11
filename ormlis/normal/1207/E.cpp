#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;
using namespace std;


void solve() {
    cout << "? ";
    for(int i = 1; i <= 100; ++i) {
        cout << (i << 7) << ' ';
    }
    cout << endl;
    int x; cin >> x;
    cout << "? ";
    for(int i = 1; i <= 100; ++i) {
        cout << i << ' ';
    }
    cout << endl;
    int y; cin >> y;
    cout << "! ";
    cout << ((x & ((1 << 7) - 1)) | (y & (~((1 << 7) - 1))));
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }

    //print((__int128)1e10);
    return 0;
}