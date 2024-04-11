#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5+10, MAXM = 1e5+10, ALP = 26, INF = 1e9+10, MOD = 1e9+7;
const int hA[4] = {1, 0, -1, 0}, kA[4] = {1, 0, -1, 0};
// const ll INF = 1e18+10;

void solve(){
    int n; cin >> n;
    vector<int> a(n, 0), b(n, 0), ans(n, 0), loc(n, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i], --a[i];
        loc[a[i]] = i;
    }
    for (int i = 0; i < n; i++){
        cin >> b[i], --b[i];
        int l = loc[b[i]], amt = (i-l+n)%n;
        ans[amt]++;
    }
    int ret = 0;
    for (auto it : ans) ret = max(ret, it);
    cout << ret << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    // cin >> t; 
    while (t--) solve();
}