#include <iostream>

using namespace std;

typedef long long ll;

ll check(ll p, ll f, ll cs, ll cw, ll ws, ll ww, ll x) {
    ll u = x;
    cs -= x;
    p -= x*ws;
    u += p/ww;
    cw -= p/ww;
    u += min(cs,f/ws);
    f -= min(cs,f/ws)*ws;
    u += min(cw,f/ww);
    return u;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll p, f;
        cin >> p >> f;
        ll cs, cw;
        cin >> cs >> cw;
        ll ws, ww;
        cin >> ws >> ww;
        if (ws > ww) {
            swap(cs,cw);
            swap(ws,ww);
        }
        ll t = 0;
        for (int i = 0; i <= cs; i++) {
            if (i*ws > p) break;
            t = max(t,check(p,f,cs,cw,ws,ww,i));
        }
        cout << t << "\n";
    }
}