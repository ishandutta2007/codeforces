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

vector<vector<char> > s;
int n,m;
const int nax = 5e5 + 5;

vector<int> adj[nax];
vector<int> adj_rev[nax];

bool jest[nax];

int dawaj(int r, int c){
    return r * m + c; // 0 INDEXED
}

vector<pii> dir = {mp(0, 1), mp(0, -1), mp(-1, 0), mp(1, 0)};

void go(int r, int c){
    int id = dawaj(r, c);
    while(r < n){
        for(pii cur : dir){
            int tor = r + cur.st;
            int toc = c + cur.nd;
            if(tor >= 0 && tor < n && toc >=0 && toc < m){
                if(s[tor][toc] == '#'){
                    int to = dawaj(tor, toc);
                    adj[id].pb(to);
                }
            }
        }
        r++;
        if(r < n && s[r][c] == '#') return;
    }
}

vector<int> order;
bool used[nax];
void dfs1(int v){
    used[v] = true;
    for(int x : adj[v]){
        if(jest[x] && !used[x]){
            dfs1(x);
        }
    }
    order.pb(v);
}

vector<int> component;

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (jest[u] && !used[u])
            dfs2(u);
}


vector<int> graf[nax];
int kto[nax];

int deg[nax];

int cnt[nax];

int mi[nax];
int ma[nax];

void clc(int v, int pr, bool mini){
    used[v] = true;
    if(mini) mi[v] = pr;
    else ma[v] = pr;
    for(int x : graf[v]){
        if(used[x] == false) clc(x, pr, mini);
    }
}

int pkt[nax];

bool cmp(int x, int y){
    return pkt[x] < pkt[y];
}

bool cmp2(pii x, pii y){
    return x.nd < y.nd;
}

void solve(){
    cin >> n >> m;
    s.resize(n);
    for(int i=0;i<n;i++) s[i].resize(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> s[i][j];
        }
    }
    int x;
    for(int i=0;i<m;i++){
        cin >> cnt[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j] =='#'){
                go(i, j);
                jest[dawaj(i, j)] = true;
            }
        }
    }

    for(int i=0;i<nax;i++){
        for(int to : adj[i]){
            adj_rev[to].pb(i);
        }
    }

    for(int i=0;i<nax;i++){
        if(jest[i] && !used[i]) dfs1(i);
    }
    fill(used, used + nax, false);
    reverse(order.begin(), order.end());
    int done = 0;
    for(auto x : order){
        if(!used[x]){
            component.clear();
            dfs2(x);
            for(int c : component) kto[c] = done;
            for(int c : component){
                int colNumber = c % m;
                pkt[done] = colNumber;
            }
            done++;
        }
    }
    for(int i=0;i<nax;i++){
        for(int to : adj[i]){
            if(kto[i] != kto[to]) graf[kto[i]].pb(kto[to]);
        }
    }
    done--;

    for(int i=0;i<=done;i++){
        for(int to : graf[i]){
            deg[to]++;
        }
    }
    vector<int> spc;
    for(int i=0;i<=done;i++){
        if(deg[i] == 0){
            spc.pb(i);
        }
    }


    fill(used, used + nax, false);
    fill(mi, mi + nax, 1e9);
    fill(ma, ma + nax, -1e9);
    sort(spc.begin(), spc.end(), cmp);
    for(int i=0;i<spc.size();i++){
        int v = spc[i];
        if(used[v] == false) clc(v, i, true);
    }
    reverse(spc.begin(), spc.end());
    fill(used, used + nax, false);
    for(int i=0;i<spc.size();i++){
        int v = spc[i];
        if(used[v] == false) clc(v, spc.size()-1-i, false);
    }
    set<pii> intervals;

    vector<int> need;
    for(int j=0;j<m;j++){
        int cur = cnt[j];
        if(cur == 0) continue;
        for(int i=n-1;i>=0;i--){
            if(s[i][j] == '#') cur -= 1;
            if(cur == 0){
                need.pb(i * m + j);
                break;
            }
        }
    }
    for(int x : need){
        int kt = kto[x];
        intervals.insert(mp(mi[kt], ma[kt]));
    }
    vector<pii> es;
    for(auto cur : intervals) es.pb(cur);
    sort(es.begin(), es.end(), cmp2);
    int ans = 0;
    int last = -1e9;
    for(pii cur : es){
        if(last >= cur.st && last <= cur.nd) continue;
        else{
            ans += 1;
            last = cur.nd;
        }
    }
    cout << ans;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();


    return 0;
}