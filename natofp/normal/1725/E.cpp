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
#define mt make_tuple

using namespace std;

const int nax = 2e5 + 5;
const int mod = 998244353;
bool prime[nax];
vector<int> adj[nax];
int depth[nax];
int pre[nax];
int post[nax];
int a[nax];
const int LOG = 20;
int up[LOG][nax];
int timer = 0;

void dfs(int v, int p, int lv){
    depth[v] = lv;
    up[0][v] = p;
    pre[v] = ++timer;
    for(int i=1;i<LOG;i++){
        int go = up[i - 1][v];
        up[i][v] = up[i - 1][go];
    }
    for(int x : adj[v]){
        if(x != p) dfs(x, v, lv + 1);
    }
    post[v] = ++timer;
}

bool is_anc(int u, int v){
    return (pre[u] <= pre[v] && post[u] >= post[v]);
}

int lca(int x, int y){
    if(is_anc(x, y)) return x;
    if(is_anc(y, x)) return y;
    for(int i=LOG-1;i>=0;i--){
        if(!is_anc(up[i][x], y)) x = up[i][x];
    }
    return up[0][x];
}

void prep(){
    for(int i=2;i<nax;i++) prime[i] = true;
    for(int i=2;i<nax;i++){
        if(prime[i]){
            for(int j=i*2;j<nax;j+=i) prime[j] = false;
        }
    }
}

int n;
vector<int> kto[nax];

bool cmp(int x, int y){
    return pre[x] < pre[y];
}

ll comb(ll n){
    return ((n * (n - 1)) / 2) % mod;
}

int rozmiar[nax];

int wazne[nax];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        kto[a[i]].pb(i);
    }
    for(int i=1;i<n;i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 1, 0);
    ll ans = 0;

    for(int i=2;i<nax;i++){
        if(!prime[i]) continue;
        vector<int> zywe;
        for(int j=i;j<nax;j+=i){
            for(int x : kto[j]) zywe.pb(x);
        }
        if(zywe.empty()) continue;
        sort(zywe.begin(), zywe.end(), cmp);
        for(int x : zywe) wazne[x] = true;
        vector<int> musze = zywe;
        for(int j=1;j<(int)zywe.size();j++){
            int v1 = zywe[j - 1];
            int v2 = zywe[j];
            musze.pb(lca(v1, v2));
        }
        sort(musze.begin(), musze.end(), cmp);
        musze.erase( unique( musze.begin(), musze.end() ), musze.end() );
        /*cout << "A" << endl;
        for(int x : zywe) cout << x << " ";
        cout << endl;
        for(int x : musze) cout << x << " ";
        cout << endl;
        cout << "B" << endl;
*/
        vector<pii> alive;
        alive.pb(mp(musze[0], 0));
        rozmiar[musze[0]] = wazne[musze[0]];
        for(int i=1;i<(int)musze.size();i++){
            //cout << "XDDDDDDD" << endl;
            bool wracam = false;
            if(i + 1 == (int)musze.size() || !is_anc(musze[i], musze[i + 1])) wracam = true;
            rozmiar[musze[i]] = wazne[musze[i]];
            if(!wracam){
                alive.pb(mp(musze[i], i));
                continue;
            }
            // wracam
            alive.pb(mp(musze[i], i));
            while(1){
                pii xd = alive.back();
                int cur = xd.st;
                //cout << "ES" << cur << endl;
                ll sz1 = rozmiar[cur];
                ll sz2 = (int)zywe.size() - sz1;
                alive.pop_back();
                int nxt = alive.back().st;
                ll dlugosc = abs(depth[cur] - depth[nxt]);
                ll sposoby = (comb(sz1) * sz2) + (comb(sz2) * sz1);
                sposoby %= mod;
                ans += sposoby * dlugosc;
                ans %= mod;

                rozmiar[nxt] += rozmiar[cur];
                if(nxt == musze[0] && (i + 1 == (int)musze.size())) break;
                if(i + 1 < (int)musze.size() && is_anc(nxt, musze[i + 1])) break;
            }
        }
        for(int x : musze) rozmiar[x] = 0;
        for(int x : musze) wazne[x] = false;
        //if(i == 2) break;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    prep();
    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}