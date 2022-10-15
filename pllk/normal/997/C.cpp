#include <iostream>

using namespace std;

#define N 1000000
#define M 998244353

typedef long long ll;

ll fac[N+1];
ll inv[N+1];

ll pot(int a, int b) {
    if (b == 0) return 1;
    ll u = pot(a,b/2);
    u = (u*u)%M;
    if (b%2 == 1) u = (u*a)%M;
    return u;
}

ll ncr(int a, int b) {
    return fac[a]*inv[b]%M*inv[a-b]%M;
}

int n;

ll lol1() {
    ll total = 0;
    for (int b = 1; b <= n; b++) {
        ll y = pot(3,n-b);
        ll x = y-1;
        ll z = x*pot(y,M-2)%M;
        ll u = pot(y,n-1)*(pot(z,n)-1)%M*pot(z-1,M-2)%M;
        u = ncr(n,b)*u%M;
        if (b%2 == 1) total += u;
        else total -= u;
        total %= M;
    }
    return total*3%M;
}

pair<ll,ll> lol2() {
    ll d[8] = {0}, u[8] = {0};
    d[0] = 1;
    ll p3n = pot(3,n)-3;;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 8; k++) u[k] = 0;
        for (int k = 0; k < 8; k++) {
            for (int h = 0; h < 3; h++) {
                if ((k&(1<<h)) == 0) continue;
                u[k] += d[k^(1<<h)]+d[k];
                u[k] %= M;
            }
            u[k] += d[k]*p3n;
            u[k] %= M;
        }
        for (int k = 0; k < 8; k++) d[k] = u[k];
    }
    ll total1 = 2*(d[1]+d[2]+d[4]);
    ll total2 = 2*(d[3]+d[5]+d[6]+d[7]);
    return {total1%M,total2%M};
}

int main() {
    fac[0] = 1;
    for (int i = 1; i <= N; i++) fac[i] = (fac[i-1]*i)%M;
    inv[N] = pot(fac[N],M-2);
    for (int i = N-1; i >= 0; i--) inv[i] = (inv[i+1]*(i+1))%M;
    cin >> n;
    ll a = lol1();
    auto l2 = lol2();
    ll c = l2.second;
    ll b = (l2.first-a*2);
    ll u = a+b+c;
    u %= M;
    if (u < 0) u += M;
    cout << u << "\n";
}