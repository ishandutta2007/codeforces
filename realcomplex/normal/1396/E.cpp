#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll N = (ll)1e5 + 100;
vector<ll> T[N];
ll sub[N];

void dfs(ll u, ll par){
    sub[u]=1;
    for(auto x : T[u]){
        if(x==par) continue;
        dfs(x,u);
        sub[u]+=sub[x];
    }
}


set<ll> nx[N];
set<pii> lca[N];
ll tin[N];
ll tout[N];
ll dep[N];
ll ti;
ll e[N];
ll pa[N];
ll match[N];

void dfs1(ll u, ll par, ll rt){
    pa[u]=par;
    sub[u]=1;
    tin[u]=++ti;
    e[u]=rt;
    ll ni;
    for(auto x : T[u]){
        if(x==par) continue;
        nx[u].insert(x);
        dep[x]=dep[u]+1;
        ni=rt;
        if(ni == -1) ni = x;
        dfs1(x, u, ni);
        sub[u] += sub[x];
    }
    tout[u]=ti;
}

set<pii> leaf;
ll root;

bool valid(ll node){
    if(node==root) return true;
    if(nx[node].size() == 0) return false;
    return true;
}

void del(ll node){
    nx[pa[node]].erase(node);
    if(nx[node].size() == 1){
        ll ro = *nx[node].begin();
        nx[pa[node]].insert(ro);
        pa[ro]=node;
        lca[e[node]].erase(mp(dep[node], node));
    }
    else
        leaf.erase(mp(tin[node], node));
    if(pa[node] != root && nx[pa[node]].size() == 0){
        leaf.insert(mp(tin[pa[node]], pa[node]));
    }
    nx[node].clear();
    if(pa[node] != root){
        if(nx[pa[node]].size() == 0){
            lca[e[node]].erase(mp(dep[pa[node]], pa[node]));
        }
    }

}

vector<ll> un[N];

int main(){
    fastIO;
    ll n;
    ll k;
    cin >> n >> k;
    ll u, v;
    for(ll i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(1, 1);
    root = 1;
    bool go = true;
    ll pp = -1;
    while(go){
        go = false;
        for(auto x : T[root]){
            if(x == pp) continue;
            if(sub[x] > n/2){
                pp = root;
                root = x;
                go = true;
                break;
            }
        }
    }
    dfs1(root, root, -1);
    ll low = 0, high = 0;
    for(ll i = 1; i <= n; i ++ ){
        if(i != root){
            low += sub[i] % 2;
            high += sub[i];
        }
    }
    if(k < low || k > high || k%2 != high%2){
        cout << "NO\n";
        return 0;
    }
    priority_queue<pii> szs;
    for(auto p : nx[root]){
        szs.push(mp(sub[p], p));
    }
    ll remv = (high-k)/2ll;
    for(ll i = 1; i <= n; i ++ ){
        if(nx[i].size() == 0){
            leaf.insert(mp(tin[i], i));
        }
    }
    for(ll i = 1; i <= n; i ++ ){
        if(i == root) continue;
        if(valid(i)){
            lca[e[i]].insert(mp(dep[i], i));
        }
    }
    ll idx;
    ll siz;
    ll dep, node, node2;
    ll du = 0;
    while(remv > 0){
        du ++ ;

        idx = szs.top().se;
        siz = szs.top().fi;
        szs.pop();
        auto it = lca[idx].lower_bound(mp(remv+1, -1));
        it -- ; // it always exists
        dep = it->fi;
        node = it->se;
        if(nx[node].size() == 1){
            auto nig = leaf.lower_bound(mp(tin[node], node));
            node2 = nig->se;
            del(node2);
            del(node);
            match[node]=node2;
            match[node2]=node;
        }
        else{
            auto nig = nx[node].begin();
            vector<ll> pp;
            for(ll i = 0 ; i < 2; i ++ ){
                auto ss = leaf.lower_bound(mp(tin[*nig], -1));
                pp.push_back(ss->se);
                nig ++ ;
            }
            del(pp[0]);
            del(pp[1]);
            match[pp[0]] = pp[1];
            match[pp[1]] = pp[0];
        }
        remv -= dep;
        siz -= 2;
        sub[idx] -= 2;
        szs.push(mp(siz, idx));
    }
    for(ll i = 1; i <= n; i ++ ){
        if(i == root) continue;
        if(match[i] == 0){
            un[e[i]].push_back(i);
        }
    }
    priority_queue<pii> mats;
    for(ll i = 1; i <= n; i ++ ){
        if(un[i].size() > 0){
            mats.push(mp(un[i].size(), i));
        }
    }
    ll p, q;
    ll la, lb;
    while(mats.size() > 1){
        p = mats.top().se;
        mats.pop();
        q = mats.top().se;
        mats.pop();
        la = un[p].back();
        lb = un[q].back();
        un[p].pop_back();
        un[q].pop_back();
        match[la]=lb;
        match[lb]=la;
        if(un[p].size() > 0)mats.push(mp(un[p].size(), p));
        if(un[q].size() > 0)mats.push(mp(un[q].size(), q));
    }
    for(ll i = 1; i <= n; i ++ ){
        if(i != root && match[i] == 0){
            match[i]=root;
            match[root]=i;
        }
    }
    cout << "YES\n";
    for(ll i = 1; i <= n; i ++ ){
        if(i < match[i])
            cout << i << " " << match[i] << "\n";
    }
    return 0;
}