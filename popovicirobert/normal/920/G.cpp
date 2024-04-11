#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 113

using namespace std;

const int MAXVAL = (int) 1e6;

int prim[MAXVAL + 1];

inline void prec() {
    for(int i = 2; i <= MAXVAL; i++) {
        if(prim[i] == 0) {
            for(int j = i; j <= MAXVAL; j += i)
                prim[j] = i;
        }
    }
}

vector <int> divi;

inline ll get(ll val, int p) {
    int sz = divi.size();
    ll ans = 0;
    for(int conf = 1; conf < (1 << sz); conf++) {
        ll prod = 1;
        int cnt = 0;
        for(int j = 0; j < sz; j++) {
            if(conf & (1 << j)) {
                prod *= divi[j];
                cnt++;
            }
        }
        if(cnt % 2)
            ans += val / prod;
        else
            ans -= val / prod;
    }
    return val - ans;
}

inline ll check(int x, int p, ll val) {
    return get(val, p) - get(x, p);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, x, p, k, t;
    ios::sync_with_stdio(false);
    cin >> t;
    prec();
    while(t > 0) {
        t--;
        cin >> x >> p >> k;
        divi.clear();
        while(p > 1) {
            int aux = prim[p];
            while(aux == prim[p]) {
                p /= aux;
            }
            divi.push_back(aux);
        }
        ll rez = 0;
        for(ll pas = 1LL << 30; pas; pas >>= 1) {
            if(check(x, p, rez + pas) < k)
                rez += pas;
        }
        cout << rez + 1 << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}