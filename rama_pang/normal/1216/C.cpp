#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define db(v) cout << #v << " is " << v << endl
using namespace std;
using lint = long long;
using pii = pair<int, int>;
using pll = pair<lint, lint>;

void solve() {
    pair<pii, pii> wh, b1, b2;
    cin >> wh.fi.fi >> wh.fi.se >> wh.se.fi >> wh.se.se;
    cin >> b1.fi.fi >> b1.fi.se >> b1.se.fi >> b1.se.se;
    cin >> b2.fi.fi >> b2.fi.se >> b2.se.fi >> b2.se.se;

    wh.fi.fi *= 2;
    wh.fi.se *= 2;
    wh.se.fi *= 2;
    wh.se.se *= 2;

    b1.fi.fi *= 2;
    b1.fi.se *= 2;
    b1.se.fi *= 2;
    b1.se.se *= 2;
    
    b2.fi.fi *= 2;
    b2.fi.se *= 2;
    b2.se.fi *= 2;
    b2.se.se *= 2;

    auto seen = [&] (int x, int y) {
        return
        (x < b1.fi.fi || b1.se.fi < x || y < b1.fi.se || b1.se.se < y) &&
        (x < b2.fi.fi || b2.se.fi < x || y < b2.fi.se || b2.se.se < y);
    };

    for (int i = wh.fi.fi; i <= wh.se.fi; i++) {
        if (seen(i, wh.fi.se) || seen(i, wh.se.se)) {
            cout << "YES\n";
            return;
        }
    } 

    for (int i = wh.fi.se; i <= wh.se.se; i++) {
        if (seen(wh.fi.fi, i) || seen(wh.se.fi, i)) {
            cout << "YES\n";
            return;
        }
    }    
    cout << "NO\n";
}

int main() {
    solve();

    // pair<pii, pii> wh, b1, b2;
    // cin >> wh.fi.fi >> wh.fi.se >> wh.se.fi >> wh.se.se;
    // cin >> b1.fi.fi >> b1.fi.se >> b1.se.fi >> b1.se.se;
    // cin >> b2.fi.fi >> b2.fi.se >> b2.se.fi >> b2.se.se;

    // wh.fi.fi *= 2;
    // wh.fi.se *= 2;
    // wh.se.fi *= 2;
    // wh.se.se *= 2;

    // b1.fi.fi *= 2;
    // b1.fi.se *= 2;
    // b1.se.fi *= 2;
    // b1.se.se *= 2;
    
    // b2.fi.fi *= 2;
    // b2.fi.se *= 2;
    // b2.se.fi *= 2;
    // b2.se.se *= 2;

    // for (int i = 0; i < 100; i++) {

    //     if (b1.fi.fi <= wh.fi.fi && wh.se.fi <= b1.se.fi) {
    //         if (wh.fi.se < b1.se.se && wh.fi.se >= b1.fi.se) wh.fi.se = b1.se.se;
    //         if (wh.se.se > b1.fi.se && wh.fi.se <= b1.fi.se) wh.se.se = b1.fi.se;
    //     }
    //     if (b1.fi.se <= wh.fi.se && wh.se.se <= b1.se.se) {
    //         if (wh.fi.fi < b1.se.fi && wh.fi.fi >= b1.fi.fi) wh.fi.fi = b1.se.fi;
    //         if (wh.se.fi > b1.fi.fi && wh.fi.fi <= b1.fi.fi) wh.se.fi = b1.fi.fi;
    //     }
    //     if (b2.fi.fi <= wh.fi.fi && wh.se.fi <= b2.se.fi) {
    //         if (wh.fi.se < b2.se.se && wh.fi.se >= b2.fi.se) wh.fi.se = b2.se.se;
    //         if (wh.se.se > b2.fi.se && wh.fi.se <= b2.fi.se) wh.se.se = b2.fi.se;
    //     }
    //     if (b2.fi.se <= wh.fi.se && wh.se.se <= b2.se.se) {
    //         if (wh.fi.fi < b2.se.fi && wh.fi.fi >= b2.fi.fi) wh.fi.fi = b2.se.fi;
    //         if (wh.se.fi > b2.fi.fi && wh.fi.fi <= b2.fi.fi) wh.se.fi = b2.fi.fi;
    //     }
        
    // }
    
    // if (wh.fi.fi >= wh.se.fi || wh.fi.se >= wh.se.se) {
    //     cout << "NO\n";
    // } else {
    //     cout << "YES\n";
    // }
}