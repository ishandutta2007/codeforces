#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 9e18+10;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n), poss, ed;
    int l = -1;
    for (int i = 0; i < n; i++){
        char c; cin >> c; a[i] = c-'0';
        if (a[i]){
            if (l != -1){
                if (l) poss.push_back(i-l);
                else ed.push_back(i-l);
            }
            l = -1;
        } else if (l == -1) l = i;
    }
    if (l != -1) ed.push_back(n-l);
    if (!sz(poss) && sz(ed)==1 && ed.back()==n){
        cout << 1+(n-1)/(k+1) << "\n"; return;
    }
    int ans = 0;
    for (auto it : poss) ans += (it-k)/(k+1);
    for (auto it : ed) ans += it/(k+1);
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}