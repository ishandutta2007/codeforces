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
const int MAXN = 1e6+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

void solve(){
    int a, b, c; cin >> a >> b >> c;

    ll y=1;
    while (sz(to_string(y)) < b) y *= 2;
    ll x=1;
    while (sz(to_string(x)) < c) x *= 2;
    while (sz(to_string(x)) < a) x *= 3;

    cout << x << ' ' << y << '\n';
    assert(sz(to_string(x)) == a && sz(to_string(y)) == b && sz(to_string(gcd(x, y))) == c);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}