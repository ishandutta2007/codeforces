#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int pref[40005];

int calc(int l, int per) {
    int n = l / per;
    return n * pref[per - 1] + pref[l % per];
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int a, b, q;
        cin >> a >> b >> q;
        int per = a * b / __gcd(a, b);
        pref[0] = 0;
        for (int i = 1; i < per; i++) {
            pref[i] = pref[i - 1] + (i % a % b != i % b % a);
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << calc(r, per) - calc(l - 1, per) << ' ';
        }
        cout << '\n';
    }
    return 0;
}