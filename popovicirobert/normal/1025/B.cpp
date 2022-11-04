#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

inline ll gcd(ll a, ll b) {
    ll r;
    while(b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

inline void get(int a, ll ans) {
    int d = 2;
    while(1LL * d * d <= a) {
        if(a % d == 0) {
            while(a % d == 0) {
                a /= d;
            }
            if(ans % d == 0) {
                cout << d;
                exit(0);
            }
        }
        d++;
    }
    if(a > 1 && ans % a == 0) {
        cout << a;
        exit(0);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, a, b;
    ios::sync_with_stdio(false);
    cin >> n;
    ll ans = 0;
    for(i = 1; i <= n; i++) {
        cin >> a >> b;
        ll aux = 1LL * a * (b / gcd(a, b));
        ans = gcd(ans, aux);
    }
    if(ans == 1) {
        cout << -1;
        return 0;
    }
    get(a, ans);
    get(b, ans);
    cout << -1;
    //cin.close();
    //cout.close();
    return 0;
}