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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

void solve(){
    int n; cin >> n;
    map<int, pair<int, int>> mp;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (mp.count(a[i])) mp[a[i]].second = i;
        else mp[a[i]] = {i, i};
    }
    vector<pair<int, int>> v; for (auto& it : mp) v.push_back(it.second);
    // for (auto it : v) cout << it.first << ' ' << it.second << '\n'; cout << '\n';
    int ans=0;
    for (int i = 0; i < sz(v); ){
        int j = i+1;
        while (j < sz(v) && v[j].first > v[j-1].second) j++;
        ans = max(ans, j-i); //cout << i << ' ' << j  << '\n';
        i = j;
    }
    cout << (sz(v)-ans) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}