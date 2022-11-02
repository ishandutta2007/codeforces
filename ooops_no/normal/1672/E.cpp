#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(51);

const int INF = 1e9;

int ask(int a) {
    cout << "? " << a << endl;
    int p;
    cin >> p;
    return p;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int l = 0, r = INF;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        int val = ask(mid);
        if (val != 1) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int ans = r;
    for (int i = 2; i <= n; i++) {
        int val = ask(ans / i);
        if (val != 0) {
            ans = min(ans, val * (ans / i));
        }
    }
    cout << "! " << ans << endl;
    return 0;
}