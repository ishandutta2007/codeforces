#include <iostream>

using namespace std;
typedef long long ll;
const int N = 2e5;

ll c[N], first[N], plus0[N], plus1[N];

int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 1; i < N; i++) {
        plus0[i] = plus0[i - 1] + i / 2;
        plus1[i] = plus1[i - 1] + (i + 1) / 2;
    }
    string s;
    cin >> s;
    int n = s.length(), cnt = 0, last = '$';
    for (int i = 0; i < n; i++) {
        if (s[i] != last) last = s[i], cnt++, first[cnt] = i;
        c[cnt]++;
    }
    ll ans0 = 0, ans1 = 0, c0, c1;
    c0 = c1 = 0;
    for (int i = 1; i <= cnt; i += 2) {
        ans0 += plus0[c[i]], ans1 += plus1[c[i]];
        ll k0, k1;
        if (first[i] % 2) k0 = c[i] / 2, k1 = (c[i] + 1) / 2; else k0 = (c[i] + 1) / 2, k1 = c[i] / 2;
        ans0 += k1 * c0 + k0 * c1;
        ans1 += k1 * c1 + k0 * c0;
        c0 += k0;
        c1 += k1;
    }
    c0 = c1 = 0;
    for (int i = 2; i <= cnt; i += 2) {
        ans0 += plus0[c[i]], ans1 += plus1[c[i]];
        ll k0, k1;
        if (first[i] % 2) k0 = c[i] / 2, k1 = (c[i] + 1) / 2; else k0 = (c[i] + 1) / 2, k1 = c[i] / 2;
        ans0 += k1 * c0 + k0 * c1;
        ans1 += k1 * c1 + k0 * c0;
        c0 += k0;
        c1 += k1;
    }
    cout << ans0 << " " << ans1 << "\n";
    return 0;
}