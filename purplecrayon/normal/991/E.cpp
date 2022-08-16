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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 998244353, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

ll fact[21], ans=0;
int a[10], p[10];

void rec(int c=0) {
    if (c == 10) {
        int tot=accumulate(p, p+10, 0);
        ll cv = fact[tot];
        for (int i = 0; i < 10; i++) cv /= fact[p[i]];
        ans += cv;

        if (p[0]) {
            cv = fact[tot-1] / fact[p[0]-1];
            for (int i = 1; i < 10; i++) cv /= fact[p[i]];
            ans -= cv;
        }
        return;
    }
    if (a[c]) {
        for (int i = 1; i <= a[c]; i++) {
            p[c] = i;
            rec(c+1);
        }
    } else {
        p[c] = 0;
        rec(c+1);
    }
}
void solve(){
    fact[0] = 1;
    for (int i = 1; i < 20; i++) fact[i] = fact[i-1]*i;

    ll n; cin >> n;
    memset(a, 0, sizeof(a));
    for (char c : to_string(n)) a[c-'0']++;


    rec();
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}