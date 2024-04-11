#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 5e5+10, MAXM = 2e5+10, MAXL = 17, ALP = 26, MOD = 998244353, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    
    auto er = [&](map<int, int>& mp, int x){
        mp[x]--;
        if (!mp[x]) mp.erase(mp.find(x));
    };
    
    map<int, int> mp, freqs; int ans=1;
    for (int i = 0; i < n; i++){
        int c; cin >> c; 
        {
            if (mp.count(c)) {
                er(freqs, mp[c]);
            }
            mp[c]++;
            freqs[mp[c]]++;
        }
        //either remove smth with frequency one, or remove the last element
        if (sz(freqs) == 1){
            if (freqs.begin()->first == 1 || freqs.begin()->second == 1) ans = i+1;
        } else if (sz(freqs) == 2) {
            if (freqs.begin()->first == 1 && freqs.begin()->second == 1) ans = i+1;
            if (freqs.rbegin()->second == 1 && freqs.count(freqs.rbegin()->first - 1)) ans = i+1;
        }
        // cout << i << "\n";
        // for (auto& it : freqs) cout << it.first << ' ' << it.second << '\n';
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}