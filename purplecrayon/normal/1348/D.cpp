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
    ll sm = 0, c = 0;
    vector<ll> a;
    while (sm+(1<<c) < n) sm += (1<<c), a.push_back(1<<c), c++;
    if (sm < n) a.push_back(n-sm);
    sort(a.begin(), a.end());
    cout << sz(a)-1 << "\n";
    for (int i = 1; i < sz(a); i++) cout << a[i]-a[i-1] << " ";
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}