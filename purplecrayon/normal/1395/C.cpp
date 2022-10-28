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
    int n, m; cin >> n >> m;
    vector<int> a, b;
    for (int i = 0; i < n; i++){
        int aa; cin >> aa; a.push_back(aa);
    }
    for (int i = 0; i < m; i++){
        int bb; cin >> bb; b.push_back(bb);
    }
    int ans=INF;
    for (int mask = 0; mask < (1<<9); mask++){
        bool finalWorked = true;
        for (int i = 0; i < n; i++){
            bool worked = false;
            for (int j = 0; j < m; j++){
                int val = a[i]&b[j]; bool ok = true;
                // if (i == 1 && j == 0) cout << val << "\n";
                for (int bit = 0; bit < 9; bit++){
                    if ((val&(1<<bit)) && (!(mask&(1<<bit)))){
                        ok = false; break;
                    }
                }
                if (ok){
                    // cout << "PAIRED: " << i << " " << j << endl;
                    worked = true;
                    break;
                }
            }
            if (!worked){
                finalWorked = false; break;
            }
        }
        if (finalWorked) ans = min(ans, mask);
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;// cin >> t;
    while (t--) solve();
}