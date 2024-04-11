#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

ll ten[20], f[10], F[10];
ll C(ll n) { return n * (n + 1) / 2; }
int main() {
    ten[0] = 1;
    rep(i, 1, 9) {
        ll nw = ten[i - 1] * 9;
        ten[i] = ten[i - 1] + nw;
        f[i] = f[i - 1] + nw * i;
        F[i] = F[i - 1] + nw * f[i - 1] + C(nw) * i;
    }
    int T;
    for(cin >> T; T--;) {
        ll n; cin >> n;
        int k = 0;
        while(n > F[k + 1]) k++;
        n -= F[k++];
        ll su = 0;
        per(i, k - 1, 0) rep(j, 0, 9) {
            ll t = ten[i] * f[k - 1] + k * (2 * su + ten[i] + 1) * ten[i] / 2;
            if(n > t) n -= t, su += ten[i];
            else break;
        }
        for(k = 0; n > f[k + 1]; k++);
        n -= f[k++];
        ll t = (n - 1) / k + ten[k - 1];
        rep(i, 1, k - 1 - (n - 1) % k) t /= 10;
        cout << t % 10 << '\n';
    }
}