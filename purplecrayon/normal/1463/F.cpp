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
const int MAXN = 22, MAXM = 5e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 110, INF = 1e9+10, MAXA = 62, MAXB = 24, MAXBB = (1<<MAXB), MOD2=MOD-1;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, x, y, a[2*MAXN];
int prv[1<<MAXN], cur[1<<MAXN];

void solve(){
    cin >> n >> x >> y;
    for (int i = 1; i <= x+y; i++) a[i] = n/(x+y) + (i <= n%(x+y));

    const int v=max(x, y), ALL=(1<<v)-1, V=1<<v;

    fill(prv, prv+V, -2e9), fill(cur, cur+V, -2e9);
    prv[0] = 0;
    for (int i = 1; i <= x+y; i++){
        for (int j = 0; j < (1<<v); j++){
            int nj = j<<1;
            cur[nj&ALL] = max(cur[nj&ALL], prv[j]);
            if ((nj&(1<<x))||(nj&(1<<y))) continue;
            cur[(nj&ALL)^1] = max(cur[(nj&ALL)^1], prv[j]+a[i]);
        }
        //for (int j = 0; j < (1<<v); j++) if (cur[j] > 0) cerr << i << ' ' << j << ' ' << cur[j] << '\n';
        //cerr << i << ' ' << *max_element(cur.begin(), cur.end()) << '\n';
        memcpy(prv, cur, sizeof(prv)); fill(cur, cur+V, -2e9);
    }
    cout << *max_element(prv, prv+V) << '\n';

}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}