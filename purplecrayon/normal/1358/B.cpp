#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()

typedef vector<int> vi;
typedef long long ll;
const int MAXN = 3e5+10, MAXM = 3e5+10, MAXL = 21;
const string yes = "YES\n", no = "NO\n";

void solve(){
    int n; cin >> n;
    vector<int> a(n, 0);
    for (auto& it : a) cin >> it;
    sort(a.begin(), a.end());
    int ans = 1, numTaken = n;
    for (int i = n-1; i >= 0; i--){
        if (a[i] > numTaken) numTaken--;
        else ans++;
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}