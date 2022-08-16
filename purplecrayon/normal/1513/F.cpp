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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 998244353, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

int n;
ll mx[2];
ar<ll, 3> a[MAXN];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i][0];
    for (int i = 0; i < n; i++) cin >> a[i][1];
    for (int i = 0; i < n; i++) if (a[i][1] < a[i][0]) swap(a[i][0], a[i][1]), a[i][2] = true;

    sort(a, a+n);
    ll ans=0;
    for (int i = 0; i < n; i++) 
        ans += a[i][1]-a[i][0];

    ll cur=0;
    for (int i = 0; i < n; i++) {
        cur = max(cur, min(a[i][1], mx[!a[i][2]])-a[i][0]);
        mx[a[i][2]] = max(mx[a[i][2]], a[i][1]);
    }
    cur *= -2;
    ans += cur;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}