#include <bits/stdc++.h>
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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n", first = "DA\n", second = "NET\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; string s; cin >> n >> s;
    
    auto getAns = [&](string res){
        vector<int> runs;
        int l=-1;
        for (int i = 0; i < n; i++){
            bool c = (s[i]!=res[i]);
            if (c && l == -1) l = i;
            if (!c && l != -1){
                runs.push_back(i-l);
                l = -1;
            }
        }
        if (l != -1) runs.push_back(n-l);
        int ans=sz(runs);
        // cout << '\n';
        return ans;
    };
    
    string res(n, ' ');
    for (int i = 0; i < n; i++) res[i] = '0'+(i&1);
    int ans = getAns(res);
    for (auto& c : res) c = '1'+'0'-c;
    ans = min(ans, getAns(res));
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}