#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

void solve(){
    int n; cin >> n;
    vector<ll> a(n); for (auto& it : a) cin >> it;

    int ans = 0;
    for (auto c : a) if (c == 0) ans++;
    ans = max(ans, 2);

    unordered_map<ll, int> mp;
    for (auto x : a) mp[x]++;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if ((a[i] != 0 || a[j] != 0) && i != j) {
            vector<ll> seq{a[i], a[j]};
            unordered_map<ll, int> cnt;
            
            mp[a[i]]--;
            while (mp[seq.back()]--) {
                int len = sz(seq);
                seq.push_back(seq[len-1]+seq[len-2]);
            }

            for (auto c : seq) mp[c]++;
            seq.pop_back();

            ans = max(ans, sz(seq));
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}