#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 60, MAXM = 1e5+10, ALP = 26, INF = 1e9+10, MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

void solve(){
    string s; cin >> s; int n = sz(s);
    vector<int> pre1(n, 0), pre0(n, 0), suff0(n, 0), suff1(n, 0);
    for (int i = 0; i < n; i++) pre1[i] = (i?pre1[i-1]:0)+(s[i]!='1'), pre0[i] = (i?pre0[i-1]:0)+(s[i]!='0');
    for (int i = n-1; i >= 0; i--) suff0[i] = (i<n-1?suff0[i+1]:0)+(s[i]!='0'), suff1[i] = (i<n-1?suff1[i+1]:0)+(s[i]!='1');
    // for (auto it : pre1) cout << it << " "; cout << "\n";
    // for (auto it : pre0) cout << it << " "; cout << "\n";
    // for (auto it : suff0) cout << it << " "; cout << "\n";
    // for (auto it : suff1) cout << it << " "; cout << "\n";
    int ans = min(min(pre1[n-1], pre0[n-1]), min(suff1[0], suff1[0]));
    for (int i = 1; i < n; i++){
        ans = min(ans, min(pre1[i-1], pre0[i-1])+min(suff0[i], suff1[i]));
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    cin >> t; 
    while (t--) solve();
}