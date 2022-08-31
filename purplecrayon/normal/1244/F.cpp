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
    int n; ll k; cin >> n >> k;
    string s; cin >> s;
    vector<bool> block(n);
    for (int i = 0; i < n; i++){
        int pre=(i-1+n)%n, nxt=(i+1)%n;
        block[i] = s[pre] != s[i] && s[i] != s[nxt];
    }
    //find min dist to a !block
    vector<ll> dist(n, INF);
    queue<int> q; for (int i = 0; i < n; i++) if (!block[i]) q.push(i), dist[i] = 0;
    while (sz(q)){
        int c = q.front(); q.pop();
        int pre=(c-1+n)%n, nxt=(c+1)%n; vector<int> adj{pre, nxt};
        for (auto it : adj) if (dist[it] >= INF) dist[it] = dist[c]+1, q.push(it);
    }
    string res=s;
    for (int i = 0; i < n; i++){
        bool flipped=min(dist[i], k)&1;
        if (flipped) res[i] = (res[i]=='W'?'B':'W');
    }
    cout << res;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}