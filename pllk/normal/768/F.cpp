#include <iostream>

using namespace std;

typedef long long ll;

#define M 1000000007

#define Z 450000

ll fac[Z+1];
ll inf[Z+1];

ll pot(int a, int b) {
    if (b == 0) return 1;
    ll u = pot(a,b/2);
    u *= u;
    u %= M;
    if (b%2 == 1) u *= a;
    u %= M;
    return u;
}

ll inv(int x) {
    return pot(x,M-2);
}

ll ncr(int a, int b) {
    if (b > a) return 0;
    ll u = 1;
    u *= fac[a];
    u %= M;
    u *= inf[b];
    u %= M;
    u *= inf[a-b];
    u %= M;
    return u;
}

ll lol(int n, int k) {
    return ncr(k+n-1,k);
}

int f, w, h;

ll calc(int p, int r) {
    int uf = f;
    int uw = w;
    int cf = 0;
    int cw = 0;
    ll rr = 0;
    for (int i = 0; ; i++) {
        if (i%2 == p) {
            if (uw < r) break;
            uw -= r;
            cw++;
        } else {
            if (uf < 1) break;
            uf--;
            cf++;
        }
        ll uu = 1;
        if (uw > 0 && cw > 0) {
            uu *= lol(cw,uw);
        }
        if (uf > 0 && cf > 0) {
            uu *= lol(cf,uf);
        }
        if (uw > 0 && cw == 0) uu = 0;
        if (uf > 0 && cf == 0) uu = 0;
        rr += uu;
        rr %= M;
    }
    return rr;
}

int main() {
    fac[0] = 1;
    for (int i = 1; i <= Z; i++) {
        fac[i] = (fac[i-1]*i)%M;
    }
    inf[Z] = inv(fac[Z]);
    for (int i = Z-1; i >= 0; i--) {
        inf[i] = (inf[i+1]*(i+1))%M;
    }
    cin >> f >> w >> h;
    
    ll pp = calc(0,h+1)+calc(1,h+1);
    ll qq = calc(0,1)+calc(1,1);

    pp %= M;
    qq %= M;
    cout << (pp*inv(qq))%M << "\n";
}