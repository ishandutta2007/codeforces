#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 4e3+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

void solve(){
    ll n, k; cin >> n >> k;
    if ((n/k)&1) cout << yes;
    else cout << no;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    // cin >> t; 
    while (t--) solve();
}