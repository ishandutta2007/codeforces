#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair

#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
ll mx[N];
ll dd[N];
vector<pii> T[N];

ll res = 0;

void dfs(int node, int pp){
    vector<ll> ff = {0ll, 0ll};
    for(auto x : T[node]){
        if(x.fi == pp) continue;
        dfs(x.fi, node);
        mx[node] = max(mx[node], mx[x.fi] + x.se);
        dd[node] = max(dd[node], dd[x.fi]);
        ff.push_back(mx[x.fi] + x.se);
    }
    sort(ff.begin(), ff.end());
    dd[node] = max(dd[node], ff[ff.size() - 1] + ff[ff.size() - 2]);
}

ll total = 0ll;
ll soln = (ll)1e18;

void dfs1(int node, int pp, ll dim, ll in){
    vector<pii> to;
    to.push_back(mp(in, -1));
    to.push_back(mp(0ll, -1));
    vector<pii> da;
    da.push_back(mp(dim, -1));
    da.push_back(mp(0ll, -1));
    for(auto x : T[node]){
        if(x.fi == pp) continue;
        da.push_back(mp(dd[x.fi], x.fi));
        to.push_back(mp(mx[x.fi] + x.se, x.fi));
    }
    sort(da.begin(), da.end());
    sort(to.begin(), to.end());
    reverse(da.begin(), da.end());
    reverse(to.begin(), to.end());
    
    ll dia;
    int cnt = 0;
    ll qq = 0;
    for(auto x : to){
        qq += x.fi;
        cnt ++ ;
        if(cnt == 4) break;
    }
    soln = min(soln, total - qq);
    ll pat;
    ll mm;
    for(auto x : T[node]){
        if(x.fi == pp) continue;   
        dia = 0; 
        for(int i = 0 ; i < da.size(); i ++ ){
            if(da[i].se != x.fi){
                dia = da[i].fi;
                break;
            }
        }
        cnt = 0;
        pat = 0ll;
        mm = 0ll;
        for(int i = 0 ; i < to.size(); i ++ ){
            if(to[i].se != x.fi){
                pat += to[i].fi;
                mm = max(mm, to[i].fi);
                cnt ++ ;
            }
            if(cnt == 2) break;
        }
        dia = max(dia, pat);
        soln = min(soln, total - dia - dd[x.fi] - 2ll * x.se);
        dfs1(x.fi, node, max(dia, mm + x.se), mm + x.se);
    }
}
int main(){
    fastIO;
    int n;
    cin >> n;
    int u, v, w;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v >> w;
        total += 2ll * w;
        T[u].push_back(mp(v, w));
        T[v].push_back(mp(u, w));
    }
    dfs(1, -1);
    soln = total - dd[1];
    dfs1(1, -1, 0ll, 0ll);
    cout << soln << "\n";
    return 0;
}