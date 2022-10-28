#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 510, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

int getMEX(vector<int>& a, int n){
    vector<bool> vis(n+1, false);
    for (auto it : a) vis[it] = true;
    for (int i = 0; i <= n; i++) if (!vis[i]) return i;
    return n;
}
void solve(){
    int n; cin >> n;
    set<int> bad;
    vector<int> a(n, 0); for (auto& it : a) cin >> it;
    for (int i = 0; i < n; i++) if (a[i] != i) bad.insert(i);
    vector<int> ans;
    while (bad.size()) {
        int mex = getMEX(a, n);
        if (mex == n){
            int c = *bad.begin();
            a[c] = mex; ans.push_back(c);
        }
        mex = getMEX(a, n);
        a[mex] = mex; ans.push_back(mex); bad.erase(bad.find(mex));
    }
    cout << sz(ans) << "\n";
    for (auto it : ans) cout << it+1 << " ";
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    cin >> t; 
    while (t--) solve();
}