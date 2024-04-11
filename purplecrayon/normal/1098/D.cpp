#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 5e5+10, MAXQ = 3e5+10, MAXL = 31, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

void solve(){
    int q; cin >> q;

    ll sm[MAXL]={};
    multiset<ll> s[MAXL];

    int cnt=0;
    while (q--) {
        char c; cin >> c;
        ll x; cin >> x;

        cnt += (c == '+' ? 1 : -1);

        for (int i = 0; i < MAXL; i++) {
            ll lb = 1ll<<i, rb = (1ll<<(i+1))-1;
            if (lb <= x && x <= rb) {
                if (c=='+') s[i].insert(x), sm[i] += x;
                else s[i].erase(s[i].find(x)), sm[i] -= x;

                break;
            }
        }
        if (!cnt){ cout << 0 << '\n'; continue; }

        int ans=cnt;
        ll ps=0;
        for (int i = 0; i < MAXL; i++) {
            if (sz(s[i])) {
                ll c = *s[i].begin();
                if (c > 2*ps) ans--;
            }
            ps += sm[i];
        }
        cout << ans << '\n';

        /*
        if (c == '+') s.insert(x);
        else s.erase(s.find(x));

        int ans=0;
        vector<ll> v(s.begin(), s.end());
        for (int i = 1; i < sz(v); i++) {
            if (2*v[i-1] >= v[i]) ans++;
            v[i] += v[i-1];
        }
        */
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}