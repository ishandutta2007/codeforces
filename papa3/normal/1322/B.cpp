#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

//#define int long long
//#define double long double

//const int INF = 1000000000000000000LL;
const int mod = 1000000007;

struct Drzewo {
    int dl;
    vector<bool> v;
    
    Drzewo(int _dl) : dl(_dl), v(1 << (dl + 2)) {}
    
    void dodaj(int co) {
        int gdzie = 1;
        for (int i = dl - 1; i >= 0; i--) {
            gdzie <<= 1;
            if (co & (1 << i)) {
                gdzie++;
            }
            v[gdzie] = 1 - v[gdzie];
        }
        v[gdzie << 1] = 1 - v[gdzie << 1];
    }
    
    bool czytaj(int co) {
        int gdzie = 2;
        if (co & (1 << (dl - 1))) {
            gdzie++;
        }
        int res = 0;
        for (int i = dl - 2; i >= 0; i--) {
            gdzie <<= 1;
            if (!(co & (1 << i))) {
                gdzie++;
            } else {
                res += v[gdzie + 1];
            }
        }
        
        gdzie = 2;
        if (!(co & (1 << (dl - 1)))) {
            gdzie++;
        }
        int res2 = 0;
        for (int i = dl - 2; i >= 0; i--) {
            gdzie <<= 1;
            if (!(co & (1 << i))) {
                res2 += v[gdzie];
                gdzie++;
            }
        }
        res2 += v[gdzie << 1];
        
        cerr << dl << "  " << res << " " << res2 << endl;
        return (res + res2) % 2;
    }
};

vector<Drzewo> d;
int tab[1000010];
const int baza = 25;

void brut(int n) {
    if (debug) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                res ^= tab[i] + tab[j];
            }
        }
        cout << res << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i <= baza; i++) {
        d.push_back({i});
    }
    
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> tab[i];
        
        for (int j = 1; j <= baza; j++) {
            if (d[j].czytaj(tab[i])) {
                res ^= (1 << (j - 1));
            }
        }
        
        cerr << res << endl;
        
        for (int j = 1; j <= baza; j++) {
            d[j].dodaj(tab[i]);
        }
    }
    
    brut(n);
    cout << res;
    
    
    return 0;
}/*

*/