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

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 24, MOD = 998244353, MAXK = 2e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, m, k, a[MAXK], d[MAXN], nm[MAXN];
vector<int> adj[MAXN], badj[MAXN];

void init(){
    for (int i = 0; i < n; i++) d[i] = 1e9;
    d[a[k-1]] = 0;
    queue<int> q; q.push(a[k-1]);
    while (q.size()){
        int c = q.front(); q.pop();
        // cout << c << ' ' << d[c] << '\n';
        for (auto nxt : badj[c]) if (d[nxt] >= 1e9){
            d[nxt] = d[c]+1;
            q.push(nxt);
        }
    }
}
int one(){ //min rebuilds
    //check if new vertex is on shortest path
    int ans=0;
    for (int i = 0; i < k-1; i++) ans += (d[a[i+1]]+1 != d[a[i]]);
    return ans;
}
int two(){ //max rebuilds
    //check if there is a shortest path that isn't vertex v
    memset(nm, 0, sizeof(nm));
    for (int i = 0; i < n; i++) for (auto nxt : adj[i]) nm[i] += d[nxt]==d[i]-1;
    int ans=0;
    for (int i = 0; i < k-1; i++){
        if (d[a[i+1]]+1 != d[a[i]] || nm[a[i]] > 1) ans++;
    }
    return ans;
}
void solve(){
    fsc(n), fsc(m);
    for (int i = 0; i < m; i++){
        int a, b; fsc(a), fsc(b); --a, --b;
        adj[a].push_back(b), badj[b].push_back(a);
    }
    fsc(k); for (int i = 0; i < k; i++) fsc(a[i]), --a[i];
    init();
    cout << one() << ' ' << two() << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}