#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 97

using namespace std;

const int MAXP = (int) 1e6 + 5;

int pw[MAXP + 1];
int who[MAXP + 1];

pair <ll, ll> solve(int a, int b, int c) {
    if(b == 0) {
        return {c / a, 0};
    }
    pair <ll, ll> aux = solve(b, a % b, c);
    return {aux.second, aux.first - aux.second * (a / b)};
}

inline int lgput(int a, int b, int md) {
    int ans = 1;
    while(b > 0) {
        if(b & 1)
            ans = (1LL * ans * a) % md;
        b >>= 1;
        a = (1LL * a * a) % md;
    }
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int a, b, p, i;
    ll x;
    ios::sync_with_stdio(false);
    cin >> a >> b >> p >> x;
    if(a % p == 0) {
        if(b != 0)
            cout << 0;
        else
            cout << x;
        return 0;
    }
    if(p == 2) {
        if(b == 0)
            cout << x / 2;
        else
            cout << (x + 1) / 2;
        return 0;
    }
    memset(who, -1, sizeof(who));
    pw[0] = 1;
    who[1] = 0;
    for(i = 1; i < p - 1; i++) {
        pw[i] = (1LL * pw[i - 1] * a) % p;
        if(pw[i] == 1)
            break;
        who[pw[i]] = i;
    }
    int m1 = p, m2 = i;
    ll M = 1LL * m1 * m2;
    ll ans = 0;
    for(int a1 = 0; a1 < p; a1++) {
        int r = (1LL * b * lgput(a1, p - 2, p)) % p;
        int a2 = who[r];
        if(a2 > -1) {
            ll b1 = lgput(m2, m1 - 2, m1), b2 = solve(m1, m2, 1).first;
            if(b2 < 0) {
                b2 = ((-b2 + m2 - 1) / m2) * m2;
            }
            ll val = (1LL * a1 * b1 * m2 + 1LL * a2 * b2 * m1) % M;
            if(val <= x) {
                ans += (x - val) / M + 1;
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}