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

const int nax = 1e5 + 5;
multiset<int> adj[3][nax];
set<pii> added[3];
vector<pair<pii, int>> IP;
int n, m;

vector<int> eulerCycles[3][nax];
vector<int> curCycle;
int eulerCount[3];
bool spec[nax];

void f(int w, int id){
    while(adj[w][id].size()){
        int go = (*adj[w][id].begin());
        adj[w][id].erase(adj[w][id].find(go));
        adj[w][go].erase(adj[w][go].find(id));
        f(w, go);
    }
    curCycle.pb(id);
}

multiset<pii> construction[3];


map<pii, vector<pii> > paths[3];


vector<int> grafReal[nax];
bool vis[nax];

vector<int> comp;

void dfs(int v){
    vis[v] = true;
    comp.pb(v);
    for(int x : grafReal[v]){
        if(!vis[x] && spec[x]) dfs(x);
    }
}

int score[nax];

void solve(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x, y, z; cin >> x >> y >> z;
        IP.pb(mp(mp(x, y), z));
        adj[z][x].insert(y);
        adj[z][y].insert(x);
    }
    set<int> special;
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(adj[1][i].size() & 1){
            ans += 1;
            special.insert(i);
            spec[i] = true;
        }
    }
    cout << ans << "\n";
    for(int w=1;w<=2;w++){
        vector<int> ids;
        for(int i=1;i<=n;i++){
            if(adj[w][i].size() & 1) ids.pb(i);
        }
        for(int i=0;i<ids.size();i+=2){
            int x = ids[i];
            int y = ids[i + 1];
            adj[w][x].insert(y);
            adj[w][y].insert(x);
            if(x > y) swap(x, y);
            added[w].insert(mp(x, y));
        }
    }

    for(int w=1;w<=2;w++){
        for(int i=1;i<=n;i++){
            if(adj[w][i].size()){
                eulerCount[w] += 1;
                curCycle.clear();
                f(w, i);
                curCycle.pop_back();
                eulerCycles[w][eulerCount[w]] = curCycle;
            }
        }
    }


    for(int w=1;w<=2;w++){
        for(int i=1;i<=eulerCount[w];i++){
            auto cur = eulerCycles[w][i];
            int id = -1;
            for(int j=0;j<cur.size();j++){
                int x = cur[j];
                int y = cur[0];
                if(j < cur.size() - 1) y = cur[j + 1];
                if(x > y) swap(x, y);
                if(added[w].count(mp(x, y))){
                    id = 0;
                    if(j < cur.size() - 1) id = j + 1;
                    added[w].erase(mp(x, y));
                    break;
                }
            }
            if(id == -1){
                // doesnt matter
                for(int j=0;j<cur.size();j++){
                    int x = cur[j];
                    int y = cur[0];
                    if(j < cur.size() - 1) y = cur[j + 1];
                    construction[w].insert(mp(x, y));
                }
                continue;
            }

            vector<pii> curPath;
            int sz = cur.size();
            for(int k=0;k<sz-1;k++){
                int id1 = id + k;
                int id2 = id + k + 1;
                if(id1 >= sz) id1 -= sz;
                if(id2 >= sz) id2 -= sz;
                int x = cur[id1];
                int y = cur[id2];
                pii lookFor = mp(min(x, y), max(x, y));
                if(added[w].count(lookFor)){
                    if(curPath.empty()){
                        added[w].erase(lookFor);
                        continue;
                    }
                    int pocz = curPath[0].st;
                    int kon = curPath.back().nd;
                    paths[w][mp(pocz, kon)] = curPath;
                    curPath.clear();
                    added[w].erase(lookFor);
                }
                else{
                    curPath.pb(mp(x, y));
                }
            }
            if(curPath.size()){
                int pocz = curPath[0].st;
                int kon = curPath.back().nd;
                paths[w][mp(pocz, kon)] = curPath;
                curPath.clear();
            }
        }
    }

    for(int w=1;w<=2;w++){
        for(auto p : paths[w]){
            pii cur = p.st;
            grafReal[cur.st].pb(cur.nd);
            grafReal[cur.nd].pb(cur.st);
        }
    }

    for(int i=1;i<=n;i++){
        if(!spec[i]) continue;
        if(vis[i]) continue;
        comp.clear();
        dfs(i);
        int edges = 0;
        for(int x : comp){
            for(int to : grafReal[x]){
                if(spec[to]) edges += 1;
            }
        }
        edges /= 2;
        int start = -1;
        if(edges < comp.size()){

            for(int x : comp){
                int toSpec = 0;
                for(int to : grafReal[x]){
                    if(spec[to]) toSpec += 1;
                }
                if(toSpec != 2){
                    start = x;
                    break;
                }
            }
        }
        else{
            start = comp[0];
        }

        vector<int> order;
        set<int> was;
        was.insert(start);
        order.pb(start);
        while(order.size() < comp.size()){
            int last = order.back();
            int nxt = -1;

            for(int x : grafReal[last]){
                if(spec[x] && was.count(x) == 0) nxt = x;
            }
            order.pb(nxt);
            was.insert(nxt);
        }

        vector<pii> lookFor;
        if(edges == comp.size()){
            for(int i=0;i<order.size();i++){
                int x = order[i];
                int y = order[0];
                if(i < order.size() - 1) y = order[i + 1];
                lookFor.pb(mp(x, y));
            }
        }
        else{
            int f = order[0];

            if(order.size() == 1){
                if(grafReal[f].size() == 0){
                    ;
                }
                else if(grafReal[f].size() == 1){
                    int to = grafReal[f][0];
                    lookFor.pb(mp(f, to));
                }
                else{
                    for(int i=0;i<2;i++){
                        int to = grafReal[f][i];
                        if(i == 0) lookFor.pb(mp(to, f));
                        else lookFor.pb(mp(f, to));
                    }
                }
            }
            else{
                int bef = -1;
                for(int to : grafReal[f]){
                    if(!spec[to]){
                        bef = to;
                    }
                }
                if(bef != -1){
                    lookFor.pb(mp(bef, f));
                }
                int wsk = 1;
                while(wsk < order.size()){
                    int cur = order[wsk];
                    for(int to : grafReal[cur]){
                        if(spec[to] && to == order[wsk - 1]) lookFor.pb(mp(to, cur));
                        if(!spec[to]) lookFor.pb(mp(cur, to));
                    }
                    wsk += 1;
                }
            }
        }

        for(pii cur : lookFor){
            bool found = false;
            for(int w=1;w<=2;w++){
                if(!paths[w][cur].empty()){
                    found = true;
                    auto p = paths[w][cur];
                    paths[w][cur].clear();
                    for(pii edge : p){
                        construction[w].insert(edge);
                    }
                }
                if(found) break;
            }
            if(found) continue;
            for(int w=1;w<=2;w++){
                pii kto = mp(cur.nd, cur.st);
                if(!paths[w][kto].empty()){
                    found = true;
                    auto p = paths[w][kto];
                    paths[w][kto].clear();
                    for(pii edge : p){
                        construction[w].insert(mp(edge.nd, edge.st));
                    }
                }
                if(found) break;
            }
        }
    }

    for(int w=1;w<=2;w++){
        for(auto rest : paths[w]){
            auto p = rest.nd;
            for(pii edge : p){
                construction[w].insert(mp(edge.nd, edge.st));
            }
        }
    }
    for(int w=1;w<=2;w++){
        for(pii cur : construction[w]){
            score[cur.st] -= w;
            score[cur.nd] += w;
        }
    }
    int ac = 0;
    for(int i=1;i<=n;i++){
        ac += (abs(score[i]) == 1);
    }
    assert(ac == ans);
    vector<char> odp;
    for(auto edge : IP){
        int w = edge.nd;
        int x = edge.st.st;
        int y = edge.st.nd;
        if(construction[w].count(mp(x, y))){
            odp.pb('1');
            construction[w].erase(construction[w].find(mp(x, y)));
        }
        else{
            swap(x, y);
            odp.pb('2');
            construction[w].erase(construction[w].find(mp(x, y)));
        }
    }
    vector<int> cnt(nax, 0);
    for(int i=0;i<m;i++){
        char c = odp[i];
        int x = IP[i].st.st;
        int y = IP[i].st.nd;
        int w = IP[i].nd;
        if(c == '2') swap(x,  y);
        cnt[x] -= w;
        cnt[y] += w;
    }
    int ok = 0;
    for(int x : cnt){
        if(abs(x) == 1) ok += 1;
    }
    assert(ok == ans);
    for(char x : odp) cout << x;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}