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

const int nax = 2e5 + 5;
vector<int> adj[nax];
int n;
int a[nax];
bool big[nax];

int sz[nax];
bool sciezka[nax];

void dfs(int v, int p){
    sz[v] = big[v];
    for(int x : adj[v]){
        if(x != p){
            dfs(x, v);
            sz[v] += sz[x];
        }
    }
}
int all = 0;
void dfs2(int v, int p){
    if(sz[v] > 0 && sz[v] < all) sciezka[v] = true;
    int cnt = 0;
    for(int x : adj[v]){
        if(x != p && sz[x] > 0) cnt += 1;
    }
    if(cnt >= 2) sciezka[v] = true;
    if(big[v]) sciezka[v] = true;
    for(int x : adj[v]){
        if(x != p) dfs2(x, v);
    }
}

bool vis[nax];

pll calc(int v, int p){
    vis[v] = true;
    pll res = mp(0, 0);
    for(int x : adj[v]){
        if(x != p && !sciezka[x]){
            auto cur = calc(x, v);
            res.st += cur.st;
            res.nd = max(res.nd, cur.nd);
        }
    }
    if(a[v] > res.nd){
        ll dif = a[v] - res.nd;
        res.st += dif;
        res.nd += dif;
    }
    return res;
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<n;i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int mx = a[1];
    for(int i=1;i<=n;i++) mx = max(mx, a[i]);
    for(int i=1;i<=n;i++){
        if(a[i] == mx) big[i] = true;
    }
    for(int i=1;i<=n;i++) all += (a[i] == mx);
    dfs(1,1);
    dfs2(1,1);
    ll ans = 0;
    bool flag = (all == 1);
    for(int i=1;i<=n;i++){
        if(sciezka[i]){
            vector<ll> summ, maxes;
            for(int x : adj[i]){
                if(!vis[x] && !sciezka[x]){
                    auto cur = calc(x, i);
                    summ.pb(cur.st);
                    maxes.pb(cur.nd);
                }
            }
            sort(summ.begin(), summ.end());
            sort(maxes.begin(), maxes.end());
            //cout << "WA" << i << " " << sum << " " << maxi << endl;
            int ile = 0;
            for(int x : adj[i]){
                if(sciezka[x]) ile += 1;
            }
            if(flag){
                ll sumka = 0;
                for(auto cur : summ) sumka += cur;
                sumka += mx * 2;
                if(maxes.size() >= 1) sumka -= maxes.back();
                if(maxes.size() >= 2) sumka -= maxes[(int)maxes.size() - 2];
                ans += sumka;
            }
            else{
                ll sumka = 0;
                for(auto cur : summ) sumka += cur;
                if(ile == 1){
                    ll place = mx;
                    sumka += place;
                    if(maxes.size()){
                        sumka -= maxes.back();
                    }
                }
                ans += sumka;
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}