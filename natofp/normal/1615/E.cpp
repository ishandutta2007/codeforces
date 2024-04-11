#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

const int roz = (1 << 20);

int tree[roz];
int lazy[roz];
bool marked[roz];

void push(int v){
    if(marked[v]){
        for(int i=v*2;i<=v*2+1;i++){
            marked[i] = true;
            tree[i] += lazy[v];
            lazy[i] += lazy[v];
        }
        marked[v] = false;
        lazy[v] = 0;
    }
}

void add(int lo, int hi, int u, int a, int b, int v){
    if(lo == a && b == hi){
        tree[u] += v;
        lazy[u] += v;
        marked[u] = true;
        return;
    }
    if(b <= a) return;
    push(u);
    int mid = (lo + hi) / 2;
    add(lo, mid, u * 2, a, min(b, mid), v);
    add(mid, hi, u * 2 + 1, max(a,mid), b, v);
    tree[u] = max(tree[u * 2], tree[u * 2 + 1]);
}

pll ask(int u){
    while(u < roz / 2){
        push(u);
        if(tree[u * 2] >= tree[u * 2 + 1]){
            u *= 2;
        }
        else{
            u *= 2;
            u += 1;
        }
    }
    return mp(u - roz / 2, tree[u]);
}

int n, k;
const int nax = 4e5 + 5;
vector<int> adj[nax];
int pre[nax];
int pos[nax];
int par[nax];
int timer = 0;
int who[nax];

void dfs(int v, int p, int lv){
    pre[v] = ++timer;
    who[pre[v]] = v;
    par[v] = p;
    for(int x : adj[v]){
        if(x != p) dfs(x, v, lv + 1);
    }
    pos[v] = ++timer;
    if(v != 1 && adj[v].size() == 1) add(0,roz/2,1,pre[v],pos[v]+1,lv);
}

void solve(){
    cin >> n >> k;
    for(int i=1;i<n;i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int cnt = 0;
    for(int i=2;i<=n;i++){
        if(adj[i].size() == 1) cnt += 1;
    }
    if(cnt <= k){
        ll w = n / 2;
        ll w2 = n - w;
        k = min(k, n - cnt);
        if(k < n / 2){
            w = k;
            w2 = n - k;
        }
        cout << w * w2 << "\n";
        return;
    }
    dfs(1, 1, 1);
    ll s = 0;
    ll ans = -1e18;
    for(int i=0;i<k;i++){
        auto res = ask(1);
        if(res.nd <= 0) break;
        int v = who[res.st];
        s += res.nd;
        add(0,roz/2, 1, pre[v], pos[v] + 1, -res.nd);
        int cur = res.nd;

        while(cur--){
            int p = par[v];
            add(0,roz/2,1,pre[p], pos[p] + 1, -cur);
            add(0,roz/2,1,pre[v], pos[v] + 1, cur);

            v = p;
        }

        ll taken = s;
        ll canBlue = n - taken;
        ll red = i + 1;
        if(canBlue <= red){
            ll wi = n - canBlue - red;
            ans = max(ans, wi * (red - canBlue));
        }
        else{
            ll cp = canBlue - red;
            ll wi = n - red * 2;
            cp = min(cp, wi / 2);
            ll cp1 = cp;
            ll cp2 = wi - cp1;
            ans = max(ans, cp1 * cp2 * -1);
        }

    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}