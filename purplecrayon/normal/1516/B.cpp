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
const int MAXN = 7e1+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 998244353, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

void solve(){
    int n; cin >> n;
    vector<int> b;
    int x=0; while (n--){ int a; cin >> a, x ^= a; b.push_back(a); }
    if (!x){ cout << yes; return; }

    n = sz(b);
    vector<int> pre(n);
    int l = n, r = -1;
    for (int i = 0; i < n; i++){
        pre[i] = b[i]^(i?pre[i-1]:0);
        if (pre[i] == x) l = min(l, i);
        if (pre[i] == 0) r = max(r, i);
    }
    if (l < r && l < n && r > 0) cout << yes;
    else cout << no;

}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}