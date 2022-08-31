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
const int MAXN = 1e6+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 1e9+7, MAXK = 17,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

int n, k, l[MAXN], r[MAXN];
ar<ll, 2> a[MAXN];
ll tot[MAXN];
bool hit[MAXN];

void solve(){
    cin >> n >> k, --k;
    for (int i = 1; i <= n; i++) tot[i] = (tot[i-1]+(i-1)/k)%MOD;
    for (int i = 0; i < n; i++) cin >> a[i][0], a[i][1] = i;
    sort(a, a+n);
    ll ans=0;
    for (int i = 0; i < n; i++) {
        int c = a[i][1];

        hit[c] = 1;
        ll cl=0, cr=0;
        if (c && hit[c-1]) cl += c-l[c-1];
        if (c<n-1 && hit[c+1]) cr += r[c+1]-c;
        r[c-cl] = c+cr;
        l[c+cr] = c-cl;

        ll cur = tot[cl+cr+1]-tot[cl]-tot[cr];
        cur = ((cur%MOD)+MOD)%MOD;
        ans += a[i][0]*cur%MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}