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
    int n, k; cin >> n >> k;
    set<int> s;
    vector<int> a(n, 0); for (auto& it : a) cin >> it, s.insert(it);
    vector<int> v; if (sz(s) > k){ cout << "-1\n"; return; }
    for (auto it : s) v.push_back(it);
    while (sz(v) < k) v.push_back((*s.begin()));
    vector<int> ans;
    for (int i = 0; i < n; i++) for (auto j : v) ans.push_back(j);
    cout << sz(ans) << "\n";
    for (auto it : ans) cout << it << " ";
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}