#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i <= n / 2 - 1 || i == n) ans += (1 << i);
            else ans -= (1 << i);
        }
        cout << ans << '\n';
    }
    return 0;
}