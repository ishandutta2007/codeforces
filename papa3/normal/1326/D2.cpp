#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1000000000000000000LL;
const int mod = 1000000007;

struct Manacher {
    vector<int> par, npar;
    int pocz, kon;
    string in;
    int n;
    
    Manacher() {
        cin >> in;
        in = ' ' + in;
        
        int orig_n = in.size() - 1;
        string s = " #";
        for (int i = 1; i <= orig_n; i++) {
            s += in[i];
            s += '#';
        }
        s += '$';
        int new_n = s.size() - 2;
        npar.resize(new_n + 2);
        int furth_beg = 0;
        int furth_end = 0;
        for (int i = 1; i <= new_n; i++) {
            if (furth_end < i ) {
                furth_beg = i;
                furth_end = i;
            }
            int corr_npar = furth_beg + furth_end - i;
            if (furth_end > i + npar[corr_npar]) {
                npar[i] = npar[corr_npar];
            } else {
                npar[i] = furth_end - i;
                furth_beg = i - npar[i];
                while (s[furth_beg - 1] == s[furth_end + 1]) {
                    furth_beg--;
                    furth_end++;
                    npar[i]++;
                }
            }
        }
        par.resize(orig_n + 2);
        for (int i = 1; i <= orig_n; i++) {
            if (i < orig_n) {
                par[i] = npar[2 * i + 1] / 2;
            }
            npar[i] = npar[2 * i] / 2;
        }
        npar.resize(orig_n + 2);
        
        
        
        n = in.size() - 1;
        //cout << in << endl;
        pocz = 1;
        kon = n;
        while (pocz < kon && in[pocz] == in[kon]) {
            pocz++;
            kon--;
        }
        pocz--;
        kon++;
        cerr << pocz << " " << kon << endl;
        
        int res = pocz * 2;
        for (int i = 1; i <= n; i++) {
            res = max(res, fun(i - par[i] + 1, i + par[i]));
            res = max(res, fun(i - npar[i], i + npar[i]));
            cerr << i << " " << par[i] << " " << npar[i] << endl;
        }
        cerr << "#" << res << endl;
        if (res == pocz * 2) {
            for (int i = 1; i <= pocz; i++) {
                cout << in[i];
            }
            for (int i = kon; i <= n; i++) {
                cout << in[i];
            }
            cout << "\n";
        } else {
            for (int i = 1; i <= n; i++) {
                if (res == fun(i - par[i] + 1, i + par[i], res)) {
                    return;
                }
                if (res == fun(i - npar[i], i + npar[i], res)) {
                    return;
                }
            }
        }
    }
    
    int fun(int l, int r, int ww = -INF) {
        int x = max(pocz - l + 1, r - kon + 1);
        cerr << pocz - l - 1 << " " << r - kon  -1 << endl;
        if (x < 0) {
            return -1;
        }
        
        l += x;
        r -= x;
        if (l > r) {
            return -1;
        }
        int wyn = pocz * 2 + (r - l + 1);
        if (wyn == ww) {
            for (int i = 1; i <= pocz; i++) {
                cout << in[i];
            }
            for (int i = l; i <= r; i++) {
                cout << in[i];
            }
            for (int i = kon; i <= n; i++) {
                cout << in[i];
            }
            cout << "\n";
        }
        
        return wyn;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        Manacher p;
    }
    
    return 0;
}/*

*/