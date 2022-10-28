#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    map<pair<int, int>, vector<int>> mp;
    vector<int> cnt(n);
    vector<ar<int, 3>> v(n-2);
    for (auto& it1 : v){
        for (auto& it2 : it1) cin >> it2, --it2, cnt[it2]++;
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++) if (i != j && j != k && i != k){
            mp[{it1[i], it1[j]}].push_back(it1[k]);
        }
    }
    int st=-1; vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++) if (cnt[i] == 1) { st=i; break; }
    vector<int> ans; ans.reserve(n); ans.push_back(st);  vis[st]=1;
    for (auto& it1 : v) if (it1[0]==st||it1[1]==st||it1[2]==st){
        int nst=-1;
        for (auto& it2 : it1) if (cnt[it2] == 2) nst=it2;
        ans.push_back(nst);
    }
    vis[ans.back()]=1;
    while (sz(ans) < n){
        auto nxt = mp[{ans[sz(ans)-1], ans[sz(ans)-2]}];
        for (auto it : nxt) if (!vis[it]) ans.push_back(it), vis[it]=1;
    }
    for (auto it : ans) cout << (it+1) << ' ';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}