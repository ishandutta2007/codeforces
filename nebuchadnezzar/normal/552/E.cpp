#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;

string s;
vector <int> ve;
vector <ll> vv;
vector <ll> ssum;

ll get_ssum(int l, int r) {
    return ssum[r + 1] - ssum[l];
}   

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> s;

    int prev = 0;
    ll prod = 1;
    for (int i = 0; i < szof(s); i += 2) {
        prod *= s[i] - '0';
        if (i == szof(s) - 1 || s[i + 1] == '+') {
            ve.puba(prev / 2);
            vv.puba(prod);
            prev = i + 2;
            prod = 1;
        }
    }

    ssum.puba(0);
    for (int i = 0; i < szof(vv); ++i) {
        //cerr << ve[i] << " " << vv[i] << endl;
        ssum.puba(ssum[i] + vv[i]);
    }

    int n = (szof(s) + 1) / 2;
    ll ans = 0;

    //cerr << n << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            //cerr << i << " " << j << endl;
            ll now = 0;
            ll pl = s[i * 2] - '0';
            int inb = 0;
            int en = i;
            for (int k = i; k < j && s[k * 2 + 1] == '*'; ++k) {
                pl *= s[k * 2 + 2] - '0';
                ++en;
            }
            ll pr = s[j * 2] - '0';
            for (int k = j; k > i && s[k * 2 - 1] == '*'; --k) {
                pr *= s[k * 2 - 2] - '0';
            }
            //cerr << pl << " " << pr << endl;
            if (en < j) {
                inb += pl + pr;
            } else {
                inb += pl;
            }
            int lg = upper_bound(bend(ve), i) - ve.begin();
            int rg = upper_bound(bend(ve), j) - ve.begin() - 2;
            //cerr << lg << " " << rg << endl;
            if (lg <= rg) {
                inb += get_ssum(lg, rg);
            }
            now = inb;
            for (int k = i; k > 0 && s[k * 2 - 1] == '*'; --k) {
                now *= s[k * 2 - 2] - '0';
            }
            for (int k = j; k < n - 1 && s[k * 2 + 1] == '*'; ++k) {
                now *= s[k * 2 + 2] - '0';
            }            
            //cerr << now << endl;
            /*
            for (int k = 0; k < szof(ve); ++k) {
                cerr << ve[k] << " ";
            }
            cerr << endl;*/
            lg = upper_bound(bend(ve), i) - ve.begin() - 2;
            rg = lower_bound(bend(ve), j + 1) - ve.begin();
            //cerr << lg << " " << rg << endl;
            if (lg >= 0) {
                now += get_ssum(0, lg);
            }
            //cerr << now << endl;
            if (rg <= szof(vv) - 1) {
                now += get_ssum(rg, szof(vv) - 1);
            }
            ans = max(ans, now);
            //cerr << i << " " << j << " " << inb << " " << now << endl;
        }
    }

    cout << ans << endl;

    return 0;
}