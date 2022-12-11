#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
const int LOG = 30;

struct dsu{
    int par[N];
    bool mark[N];
    void init(){
        for(int i = 0 ; i < N ; i ++ ){
            par[i] = i;
        }
    }

    int fin(int x){
        if(par[x] == x) return x;
        return par[x]=fin(par[x]);
    }

    void unite(int u, int v){
        u = fin(u);
        v = fin(v);
        if(u == v) return;
        par[u]=v;
        mark[v] |= mark[u];
    }
};

dsu can[LOG];
dsu can2[LOG];

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < LOG; i ++ ){
        can[i].init();
        can2[i].init();
    }
    int u, v, w;
    for(int i = 1; i <= m; i ++ ){
        cin >> u >> v >> w;
        for(int j = 0 ; j < LOG; j ++ ){
            if((w & (1 << j))){
                can[j].unite(u, v);
            }
            if((j > 0 && (w & (1 << j))) || (w & 1) == 0){
                can2[j].unite(u, v);
                if((w & 1) == 0){
                    can2[j].mark[can2[j].fin(u)] = true;
                }
            }
        }
    }
    int q;
    cin >> q;
    bool can0;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> u >> v;
        can0 = false;
        for(int j = 0 ; j < LOG; j ++ ){
            if(can[j].fin(u) == can[j].fin(v)){
                can0 = true;
            }
        }
        if(can0){
            cout << "0\n";
            continue;
        }
        can0 = false;
        for(int j = 1 ; j < LOG; j ++ ){
            if(can2[j].mark[can2[j].fin(u)] == true) can0 = true;
        }
        if(can0){
            cout << "1\n";
        }
        else{
            cout << "2\n";
        }
    }
    return 0;
}