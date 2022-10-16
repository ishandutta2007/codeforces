#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define dec(x, y) fixed << setprecision((y)) << (x)
#define xx first
#define yy second
#define srt(v) sort((v).begin(), (v).end())
#define srtr(v) sort((v).rbegin(), (v).rend())
#define pb push_back
#define popb pop_back
#define sz(a) (int)(a).size()
#define len(a) (int)(a).length()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, siz[100010], cpar[100010], st[800010], in[100010], uda[100010], dub[100010], Time;
bool uzet[100010];
vector<int> graf[100010], eu;
void dfs(int node, int par) {
    siz[node]=1;
    for(auto adj:graf[node]) {
        if(adj!=par && !uzet[adj]) {
            dfs(adj, node);
            siz[node]+=siz[adj];
        }
    }
}
int cent(int node, int par, int s) {
    for(int adj:graf[node]) {
        if(adj!=par && !uzet[adj] && siz[adj]>s/2) return cent(adj, node, s);
    }
    return node;
}
void decomp(int tr, int rod) {
    dfs(tr, -1);
    tr=cent(tr, -1, siz[tr]);
    uzet[tr]=1;
    if(rod!=-1) cpar[tr]=rod;
    for(auto adj:graf[tr]) {
        if(!uzet[adj]) decomp(adj, tr);
    }
}
void tfs(int node, int par, int dep) {
    dub[node]=dep;
    eu.pb(dep);
    in[node]=++Time;
    for(auto adj:graf[node]) {
        if(adj!=par) {
            tfs(adj, node, dep+1);
            eu.pb(dep);
            ++Time;
        }
    }
}
void build(int node, int tl, int tr) {
    if(tl==tr) {
        st[node]=eu[tl-1];
        return;
    }
    int mid=(tl+tr)/2;
    build(2*node, tl, mid);
    build(2*node+1, mid+1, tr);
    st[node]=min(st[2*node], st[2*node+1]);
}
int query(int node, int tl, int tr, int gl, int gr) {
    if(tl>=gl && tr<=gr) return st[node];
    int mid=(tl+tr)/2;
    int mini=2000000000;
    if(mid>=gl) mini=min(mini, query(2*node, tl, mid, gl, gr));
    if(mid+1<=gr) mini=min(mini, query(2*node+1, mid+1, tr, gl, gr));
    return mini;
}
void promeni(int node, int koji) {
    uda[node]=min(uda[node], dub[koji]+dub[node]-2*query(1, 1, sz(eu), min(in[koji], in[node]), max(in[koji], in[node])));
    if(cpar[node]==0) return;
    promeni(cpar[node], koji);
}
int najm(int node, int koji) {
	int q=query(1, 1, sz(eu), min(in[koji], in[node]), max(in[koji], in[node]));
	int d=uda[node]+dub[koji]+dub[node]-2*q;
    return min(d, (cpar[node]==0?2000000000:najm(cpar[node], koji)));
}
int main() {
    ios;
    cin >> n >> m;
    for(int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;
        graf[u].pb(v);
        graf[v].pb(u);
        uda[i]=2000000000;
    }
    uda[n]=2000000000;
    eu.reserve(2*n+10);
    tfs(1, -1, 0);
    build(1, 1, sz(eu));
    decomp(1, -1);
    promeni(1, 1);
    while(m--) {
        int t, x; cin >> t >> x;
        if(t==1) {
            promeni(x, x);
        }
        else {
            cout << najm(x, x) << "\n";
        }
    }
}