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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

const int MAXV = 7e3+10;
int n, q;
bitset<MAXV> a[MAXN];
bitset<MAXV> di[MAXV], cnt[MAXV];
bool has_sq[MAXV];

void solve(){
    cin >> n >> q;
    for (int i = 0; i < n; i++) a[i] = 0;
    for (int i = 1; i < MAXV; i++) {
        has_sq[i] = 0;

        int c=i;
        for (int j = 2; j*j <= c; j++) if (c%j == 0) {
            int cnt=0;
            while (c%j == 0) cnt++, c/=j;
            if (cnt >= 2) { has_sq[i] = 1; break; }
        }
    }
    for (int i = 1; i < MAXV; i++) {
        di[i] = 0;
        for (int j = 1; j*j <= i; j++) if (i%j == 0) {
            di[i][j]=1;
            di[i][i/j]=1;
        }

        cnt[i] = 0;
        for (int j = i; j < MAXV; j += i) if (!has_sq[j/i]) {
            cnt[i][j] = 1;
        }
    }
    while (q--) {
        int ty; cin >> ty;
        if (ty == 1) {
            int i, x; cin >> i >> x, --i;
            a[i] = di[x];
        } else if (ty == 2) {
            int i, x, y; cin >> i >> x >> y, --i, --x, --y;
            a[i] = a[x]^a[y];
        } else if (ty == 3) {
            int i, x, y; cin >> i >> x >> y, --i, --x, --y;
            a[i] = a[x]&a[y];
        } else if (ty == 4) {
            int i, v; cin >> i >> v, --i;
            int ans=(cnt[v]&a[i]).count()&1;
            cout << ans;
        } else assert(false);
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}