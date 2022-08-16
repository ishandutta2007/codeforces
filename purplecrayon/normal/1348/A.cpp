#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

void solve(){
    ll n; cin >> n;
    ll a = (1ll << n), b = 0;
    int p, amt;
    for (amt=0, p = n-1; amt < n/2; amt++, p--){
        b += (1ll << p);
    }
    while (p) a += (1 << p), p--;
    cout << a-b << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}