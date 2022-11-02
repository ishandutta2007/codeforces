#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = ((n - 1) / 3) * 2 + 1;
    cout << ans + (int)(n % 3 == 0) << endl;
    if (n % 3 == 0) {
        cout << 1 << ' ' << (ans + 1) / 2 + 1 << endl;
    }
    for (int i = 0; i < (ans + 1) / 2; i++) {
        cout << i + 1 << ' ' << (ans + 1) / 2 - i << endl;
    }
    for (int i = 0; i < ans / 2; i++) {
        cout << n - i << ' ' << n - ans / 2 + i + 1 << endl;
    }
    return 0;
}