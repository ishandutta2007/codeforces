#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 100;

struct Node{
    int dist[2];
    int flip;
};

struct segment_tree{
    Node T[N * 4 + 512];
    ll val[N];
    int bit[N];
    void build(int node, int cl, int cr){
        if(cl == cr){
            T[node].flip = 0;
            T[node].dist[bit[cl]] = val[cl];
            return ;
        }
        int mid = (cl + cr) / 2;
        build(node * 2, cl, mid);
        build(node * 2 + 1, mid + 1, cr);
        for(int q = 0 ; q < 2; q ++ ){
            T[node].dist[q] = max(T[node * 2].dist[q], T[node * 2 + 1].dist[q]);
        }
    }
    void push(int node, int cl, int cr){
        if(T[node].flip){
            swap(T[node].dist[0], T[node].dist[1]);
            if(cl != cr){
                T[node*2].flip ^= 1;
                T[node*2+1].flip ^= 1;
            }
            T[node].flip = 0;
        }
    }

    void update(int node, int cl, int cr, int tl, int tr){
        push(node, cl, cr);
        if(cr < tl || cl > tr) return;
        if(cl >= tl && cr <= tr){
            T[node].flip = 1;
            push(node, cl, cr);
            return;
        }
        int mid = (cl + cr) / 2;
        update(node * 2, cl, mid, tl, tr);
        update(node * 2 + 1, mid + 1, cr, tl, tr);
        T[node].dist[0] = max(T[node * 2].dist[0], T[node * 2 + 1].dist[0]);
        T[node].dist[1] = max(T[node * 2].dist[1], T[node * 2 + 1].dist[1]);
    }

};

vector<pii> E[N];

int dis[N];
int pap[N];
int tin[N];
int tout[N];
int cc;

int ta[N];
int tb[N];
int uu[N];
int vv[N];

int dfs(int node, int pp){
    int best = node;
    int nex;
    cc ++ ;
    tin[node] = cc;
    for(auto x : E[node]){
        if(x.fi == pp) continue;
        dis[x.fi] = dis[node] + 1;
        pap[x.fi] = (pap[node] ^ x.se);
        nex = dfs(x.fi, node);
        if(dis[nex] > dis[best]){
            best = nex;
        }
    }
    tout[node] = cc;
    return best;
}

segment_tree n1, n2;

int main(){
    fastIO;
    int n;
    cin >> n;
    int u, v, d;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v >> d;
        uu[i] = u;
        vv[i] = v;
        E[u].push_back(mp(v, d));
        E[v].push_back(mp(u, d));
    }
    int A = dfs(1, -1);
    dis[A] = 0;
    pap[A] = 0;
    cc = 0;
    int B = dfs(A, -1);
    for(int i = 1; i <= n; i ++ ){
        n1.val[tin[i]] = dis[i];
        n1.bit[tin[i]] = pap[i];
        ta[i] = tin[i];
        tb[i] = tout[i];
    }
    n1.build(1, 1, n);
    dis[B] = 0;
    pap[B] = 0;
    cc = 0;
    dfs(B, -1);

    for(int i = 1; i <= n; i ++ ){
        n2.val[tin[i]] = dis[i];
        n2.bit[tin[i]] = pap[i];
    }
    n2.build(1, 1, n);
    int q;
    cin >> q;
    int iq;
    int goal;
    for(int it = 1; it <= q; it ++ ){
        cin >> iq;
        if(ta[vv[iq]] < ta[uu[iq]]){
            goal = uu[iq];
        }
        else{
            goal = vv[iq];
        }
        n1.update(1, 1, n, ta[goal], tb[goal]);
        if(tin[vv[iq]] < tin[uu[iq]]){
            goal = uu[iq];
        }
        else{
            goal = vv[iq];
        }
        n2.update(1, 1, n, tin[goal], tout[goal]);
        cout << max(n1.T[1].dist[0], n2.T[1].dist[0]) << "\n";
    }
    return 0;
}