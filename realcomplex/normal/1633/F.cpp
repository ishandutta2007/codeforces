#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair

const int N = (int)2e5 + 15;

int subt[N];
vector<pii> T[N];
int dep[N];

void dfs(int u, int par){
    subt[u]=1;
    for(auto x : T[u]){
        if(x.fi==par) continue;
        dep[x.fi] = dep[u] + 1;
        dfs(x.fi, u);
        subt[u] += subt[x.fi];
    }
}

int up[N];
int link[N];
int E[N];

int to[N]; // from a light edge

ll total_sum;

int odd;
int big;

struct chain{
    int en = 0;
    vector<int> ord;
    vector<ll> EE;
    set<int> taken;
    int send_out;
    void clear_ends(){
        if(en == 0) return;
        if(taken.empty()){
            total_sum -= EE[en - 1];
        }
        else{
            auto it = taken.end();
            it -- ;
            if((en - *it - 1) % 2 == 1){
                odd -- ;
            }
            else{
                total_sum -= EE[en - 1] - EE[*it];
            }
            it = taken.begin();
            if(*it > 0){
                total_sum -= EE[*it - 1];
            }

        }
    }
    void add_ends(){
        if(taken.empty()){
            total_sum += EE[en - 1];
            if(en % 2 == 1){
                send_out = 1;
            }
            else{
                send_out = 0;
            }
        }
        else{
            auto it = taken.end();
            it -- ;
            if((en - *it - 1) % 2 == 1){
                odd ++ ;
            }
            else{
                total_sum += EE[en - 1] - EE[*it];
            }
            it = taken.begin();

            if(*it % 2 == 0){
                send_out = 0;
            }
            else{
                send_out = 1;
            }
            if(*it > 0){
                total_sum += EE[*it - 1];
            }
        }
    }
    void extend(){
        clear_ends();
        en ++ ;
        add_ends();
    }
    void add_segm(int cl, int cr, int v){
        if((cr - cl - 1) % 2 == 1){
            odd += v;
        }
        else{
            total_sum += (EE[cr - 1] - EE[cl]) * v;
        }
    }
    void change(int id, int iv){
        clear_ends();
        if(to[ord[id]] > 1) big -- ;
        to[ord[id]] += iv;
        if(iv == +1){
            if(to[ord[id]] == 1){
                auto it = taken.lower_bound(id);
                auto pv = it;
                bool ash = true;
                if(it != taken.end()){
                    add_segm(id, *it, +1);
                }
                else{
                    ash = false;
                }
                if(pv != taken.begin()){
                    pv -- ;
                    add_segm(*pv, id, +1);
                }
                else{
                    ash = false;
                }
                if(ash){
                    add_segm(*pv, *it, -1);
                }
                taken.insert(id);
            }
        }
        else{
            if(to[ord[id]] == 0){
                auto it = taken.lower_bound(id);
                auto nx = it;
                auto pv = it;
                nx ++ ;
                bool ash = true;
                if(nx != taken.end()){
                    add_segm(id, *nx, -1);
                }
                else{
                    ash = false;
                }
                if(pv != taken.begin()){
                    pv -- ;
                    add_segm(*pv, id, -1);
                }
                else{
                    ash = false;
                }
                if(ash){
                    add_segm(*pv, *nx, +1);
                }
                taken.erase(it);
            }
        }
        if(to[ord[id]] > 1) big ++ ;
        add_ends();
    }
};

chain cha[N];

void hld(int u, int par){
    up[u]=par;
    if(link[u] == u){
        cha[u].en = 0;
        cha[u].EE.push_back(0);
    }
    else{
        cha[link[u]].EE.push_back(E[u]);

        if(cha[link[u]].EE.size() > 2){
            cha[link[u]].EE.back() += cha[link[u]].EE[cha[link[u]].EE.size() - 3];
        }

    }
    cha[link[u]].ord.push_back(u);
    for(auto x : T[u]){
        if(x.fi == par) continue;
        E[x.fi] = x.se;
        if(subt[x.fi] * 2ll >= subt[u]){
            link[x.fi] = link[u];
            //cout << "heavy: " << u << " " << x.fi << "\n";
        }
        else{
            link[x.fi] = x.fi;
        }
        hld(x.fi, u);

    }
}

void enable(int node){
    int pv = cha[link[node]].send_out;
    cha[link[node]].extend();
    int nw;
    int nex;
    int pp;
    while(1){
        node=link[node];
        nw=cha[node].send_out;
        if(node == 1) break;
        nex = up[node];
        total_sum += (nw-pv)*1ll*E[node];
        nw -= pv;
        pv = cha[link[nex]].send_out;
        if(nw != 0)cha[link[nex]].change(dep[nex]-dep[link[nex]], nw);
        node = nex;
    }
}

vector<int> soln;
bool has;

bool mark[N];

int trivial(int node, int par){
    int total = 0;
    for(auto x : T[node]){
        if(x.fi == par) continue;
        if(mark[x.fi] == false) continue;
        total += trivial(x.fi, node);
    }
    if(total > 1) has = false;
    if(total == 1) return 0;
    soln.push_back(E[node]);
    return 1;
}

int main(){
    //freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(mp(v,i));
        T[v].push_back(mp(u,i));
    }
    dfs(1,-1);
    link[1]=1;
    hld(1,1);
    cha[1].extend();
    int type;
    int node;
    ll res;
    int qq;
    mark[1]=true;
    int sa = 0;
    int sb;
    while(1){
        cin >> type;
        if(type == 3) break;
        if(type == 1){
            cin >> node;
            mark[node]=true;
            enable(node);


            if(cha[1].send_out == 1 || odd > 0 || big > 0){
                sb = 0;
                cout << "0\n";
            }
            else{
                sb = total_sum;
                cout << total_sum << "\n";
            }
        }
        else{
            soln.clear();
            has=true;
            qq=trivial(1,-1);
            if(sb == 0){
                cout << 0 << "\n";
            }
            else{
                sort(soln.begin(), soln.end());
                cout << soln.size() << " ";
                for(auto x : soln)
                    cout << x << " ";
                cout << "\n";
            }
        }
        fflush(stdout);
    }
    return 0;
}