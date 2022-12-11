#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 10;
int d[3][N];

pii par[3][N];

vector<pii> reset;

pii fin(pii X){
    while(par[X.fi][X.se] != X) X = par[X.fi][X.se];
    return X;
}

int unite(pii A, pii B){
    A = fin(A);
    B = fin(B);
    if(A == B) return 0;
    reset.push_back(A);
    par[A.fi][A.se] = B;
    return 1;
}

struct Node{
    int lef;
    int rig;
    pii l[3];
    pii r[3];
    int sum;
};

Node T[N * 4 + 512];

Node unite(Node A, Node B){
    Node res;
    res.lef = A.lef;
    res.rig = B.rig;
    res.sum = A.sum + B.sum;
    for(int i = 0 ; i < 3; i ++ ){
        if(A.l[i].fi != -1) par[i][A.lef] = A.l[i];

        if(A.r[i].fi != -1) par[i][A.rig] = A.r[i];
        if(B.l[i].fi != -1) par[i][B.lef] = B.l[i];
        if(B.r[i].fi != -1) par[i][B.rig] = B.r[i];
    }
    for(int i = 0 ; i < 3; i ++ ){
        if(A.r[i].fi != -1 && B.l[i].fi != -1){
            res.sum -= unite(mp(i, A.rig), mp(i, B.lef));
        }
    }
    for(int i = 0 ; i < 3; i ++ ){
        if(A.l[i].fi != -1) res.l[i] = fin(mp(i, A.lef));
        else res.l[i] = mp(-1,-1);
        if(B.r[i].fi != -1) res.r[i] = fin(mp(i, B.rig));
        else res.r[i] = mp(-1,-1);
    }
    for(int i = 0 ; i < 3; i ++ ){
        par[i][A.lef] = mp(i, A.lef);
        par[i][A.rig] = mp(i, A.rig);
        par[i][B.lef] = mp(i, B.lef);
        par[i][B.rig] = mp(i, B.rig);
    }
    for(auto x : reset){
        par[x.fi][x.se] = x;
    }
    reset.clear();
    return res;
}

void build(int node, int cl, int cr){
    if(cl == cr){
        T[node].lef = T[node].rig = cl;
        for(int i = 0 ; i < 3; i ++ ){
            if(d[i][cl] == 0){
                T[node].l[i] = mp(-1, -1);
                T[node].r[i] = mp(-1, -1);
            }
            else{
                T[node].sum ++ ;
                T[node].r[i] = mp(i, cl);
                T[node].l[i] = mp(i, cl);
                if(i > 0 && d[i-1][cl] == 1){
                    T[node].sum -- ;
                    T[node].r[i] = T[node].r[i-1];
                    T[node].l[i] = T[node].l[i-1];
                }
            }
        }
        return;
    }
    int mid = (cl + cr) / 2;
    build(node * 2, cl, mid);
    build(node * 2 + 1, mid + 1, cr);
    T[node] = unite(T[node * 2], T[node * 2 + 1]);
}

Node cc;
int has;

void get(int node, int cl, int cr, int tl, int tr){
    if(node == 1){
        has = 0;
    }
    if(cr < tl || cl > tr) return;
    if(cl >= tl && cr <= tr){
        if(has == 0){
            has = 1;
            cc = T[node];
        }
        else cc = unite(cc, T[node]);
        return;
    }
    int mid = (cl + cr) / 2;
    get(node * 2, cl, mid, tl, tr);
    get(node * 2 + 1, mid + 1, cr, tl, tr);
}


int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    char f;
    for(int i = 0 ; i < 3; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            cin >> f;
            d[i][j] = f - '0';
            par[i][j] = mp(i, j);
        }
    }
    build(1, 1, n);
    int q;
    cin >> q;
    int cl, cr;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> cl >> cr;
        get(1, 1, n, cl, cr);
        cout << cc.sum << "\n";
    }
    return 0;
}