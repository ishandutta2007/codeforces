#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
vector<int> T[N];
int subt[N];
int dep[N];

struct Tree{
    int n;
    vector<int> tree;
    void upd(int id, int x){
        id += n;
        while(id > 0){
            tree[id] += x;
            id /= 2;
        }
    }
    int query(int l, int r){
        l += n;
        r += n;
        int sum = 0;
        while(l <= r){
            if(l % 2 == 1) sum += tree[l ++ ];
            if(r % 2 == 0) sum += tree[r -- ];
            l /= 2;
            r /= 2;
        }
        return sum;
    }


    void Init(int nn){
        n = nn;
        for(int i = 0 ; i < nn * 2; i ++ )
            tree.push_back(0);
    }
};

int pos[N];

void dfs(int u, int par, int di){
    dep[u] = dep[par] + 1;
    subt[u] = 1;
    pos[u] = di;
    for(auto x : T[u]){
        if(x==par)
            continue;
        dfs(x, u, di);
        subt[u] += subt[x];
    }
}

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    int u, v;
    for(int i = 1 ; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    Tree root;
    root.Init(n);
    int chains = T[1].size();
    Tree chain[chains];
    for(int j = 0 ; j < T[1].size(); j ++ ){
        dfs(T[1][j], 1, j);
    }
    for(int i = 0 ; i < chains ; i ++ ){
        chain[i].Init(subt[T[1][i]] + 1);
    }
    int typ;
    int dis;
    int ver;
    int add;
    int L, R;
    int answ;
    int t_sz;
    for(int qr = 0; qr < q; qr ++ ){
        cin >> typ;
        if(typ == 0){
            cin >> ver >> add >> dis;
            if(ver == 1){
                root.upd(dis, add);
            }
            else{
                if(dis >= dep[ver]){

                    root.upd(dis - dep[ver], add);
                    chain[pos[ver]].upd(min(dis - dep[ver], chain[pos[ver]].n - 1), -add);
                    R = min(dep[ver] + dis, chain[pos[ver]].n - 1);
                    chain[pos[ver]].upd(R, add);

                }
                else{
                    L = dep[ver] - dis;
                    R = dep[ver] + dis;
                    R = min(R, chain[pos[ver]].n - 1);
                    chain[pos[ver]].upd(R,add);
                    chain[pos[ver]].upd(L-1, -add);
                }
            }
        }
        else{
            cin >> ver;
            t_sz = chain[pos[ver]].n;
            answ = 0;
            answ += chain[pos[ver]].query(dep[ver], t_sz-1);
            answ += root.query(dep[ver], n-1);
            cout << answ << "\n";
        }
    }
    return 0;
}