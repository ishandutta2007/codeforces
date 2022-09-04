#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double dl;
const ll INF = 1e15;
ll n, m, s, f;
struct edge{
    ll a, b, w;
};
vector<vector<pair<ll, ll> > > e, et;
vector<vector<ll> > mine;
ll in[100000], up[100000], nowin = 1, visited[100000];
map<pair<ll, ll>, bool> bridge;
map<pair<ll, ll>, pair<ll, ll> > krat;
void dfs(ll st, ll myparent){
    in[st] = nowin;
    up[st] = in[st];
    nowin++;
    for (ll i = 0; i < mine[st].size(); i++)
        if (in[mine[st][i]] == 0){
            dfs(mine[st][i], st);
            up[st] = min(up[st], up[mine[st][i]]);
            if (up[mine[st][i]] > in[st] && krat[make_pair(st, mine[st][i])].first == 1)
                bridge[make_pair(st, mine[st][i])] = 1;
        }
        else
            if (myparent == -1 || mine[st][i] != myparent)
                up[st] = min(up[st], in[mine[st][i]]);
}
edge edges[100000];
ll ds[100000], dt[100000];
set<pair<ll, ll> > se;
bool fet[100000];
int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> f;
    s--;
    f--;
    e.resize(n);
    et.resize(n);
    mine.resize(n);
    for (ll i = 0; i < m; i++){
        ll a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        if (krat[make_pair(a, b)].second == 0 || krat[make_pair(a, b)].second > w)
            krat[make_pair(a, b)] = make_pair(1, w);
        else
            if (krat[make_pair(a, b)].second == w)
                krat[make_pair(a, b)].first++;
        e[a].push_back(make_pair(b, w));
        et[b].push_back(make_pair(a, w));
        edges[i].a = a;
        edges[i].b = b;
        edges[i].w = w;
    }
    for (ll i = 0; i < n; i++)
        ds[i] = INF, dt[i] = INF;
    ds[s] = 0;
    dt[f] = 0;
    se.insert(make_pair(0, s));
    while (!se.empty()){
        ll v = se.begin()->second;
        se.erase(se.begin());
        for (ll i = 0; i < (ll)e[v].size(); i++)
        if (ds[v] + e[v][i].second < ds[e[v][i].first]){
            se.erase(make_pair(ds[e[v][i].first], e[v][i].first));
            ds[e[v][i].first] = e[v][i].second + ds[v];
            se.insert(make_pair(ds[e[v][i].first], e[v][i].first));
        }
    }
    se.clear();
    se.insert(make_pair(0, f));
    while (!se.empty()){
        ll v = se.begin()->second;
        se.erase(se.begin());
        for (ll i = 0; i < (ll)et[v].size(); i++)
        if (dt[v] + et[v][i].second < dt[et[v][i].first]){
            se.erase(make_pair(dt[et[v][i].first], et[v][i].first));
            dt[et[v][i].first] = et[v][i].second + dt[v];
            se.insert(make_pair(dt[et[v][i].first], et[v][i].first));
        }
    }
    queue<ll> myq;
    myq.push(s);
    while(!myq.empty()){
        ll nowplz = myq.front();
        myq.pop();
        for (ll i = 0; i < e[nowplz].size(); i++)
            if (ds[nowplz] + e[nowplz][i].second + dt[e[nowplz][i].first] == ds[f]){
                if (visited[e[nowplz][i].first] == 0)
                    myq.push(e[nowplz][i].first);
                mine[nowplz].push_back(e[nowplz][i].first), visited[e[nowplz][i].first] = 1, mine[e[nowplz][i].first].push_back(nowplz);
            }
    }
    dfs(s, -1);
    for (ll i = 0; i < m; i++)
        if (ds[edges[i].a] + edges[i].w + dt[edges[i].b] == ds[f])
            if (bridge[make_pair(edges[i].a, edges[i].b)])
                cout << "YES" << '\n';
            else
                if (edges[i].w == 1)
                    cout << "NO" << '\n';
                else
                    cout << "CAN " << 1 << '\n';
        else{
            ll x = ds[f] - ds[edges[i].a] - dt[edges[i].b] - 1;
            if (x <= 0)
                cout << "NO" << '\n';
            else
                cout << "CAN " << edges[i].w - x << '\n';
        }
}