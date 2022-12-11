#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
const int M = (int)2e5 + 4;
const int K = 450;
const int P = 90;
const int MOD = (int)1e9 + 7;
int low[M];

vector<int> g;

struct Node{
    vector<int> mx;
};

Node T[N * 4 + 10];

void upd(int node, int cl, int cr, int pos, vector<int> S){
    if(cl == cr){
        T[node].mx = S;
        return;
    }
    int mid = (cl + cr) / 2;
    if(mid >= pos)
        upd(node * 2, cl, mid, pos, S);
    else
        upd(node * 2 + 1, mid + 1, cr, pos, S);
    T[node].mx.resize(P);
    for(int k = 0 ; k < P ; k ++ ){
        T[node].mx[k] = 0;
        if(!T[node*2].mx.empty())
            T[node].mx[k] = max(T[node].mx[k], T[node*2].mx[k]);
        if(!T[node*2+1].mx.empty())
            T[node].mx[k] = max(T[node].mx[k], T[node*2+1].mx[k]);
    }
}

vector<int> def(P);

Node get(int node, int cl, int cr, int tl, int tr){
    if(cr < tl || cl > tr){
        return {def};
    }
    if(cl >= tl && cr <= tr)
        return T[node];
    int mid = (cl + cr) / 2;
    Node lef = get(node * 2, cl, mid, tl, tr);
    Node rig = get(node * 2 + 1, mid + 1, cr, tl, tr);
    for(int i = 0 ; i < P; i ++ )
        lef.mx[i] = max(lef.mx[i], rig.mx[i]);
    return lef;
}

ll answ[N];
int pos[M];

struct nds{
    int mult;
    int id_l;
    int id_r;
};


const int MAX = (int)1e7;
nds pers[MAX];

int cnt = 0;

int newnode(int id){
    cnt ++ ;
    if(id == -1)
        pers[cnt] = {1, -1, -1};
    else
        pers[cnt] = pers[id];
    return cnt;
}

int update(int node, int cl, int cr, int pos, int x){
    node = newnode(node);
    if(cl == cr){
        pers[node].mult = x;
        return node;
    }
    int mid = (cl + cr) / 2;
    if(mid >= pos){
        int tx = update(pers[node].id_l, cl, mid, pos, x);
        pers[node].id_l = tx;
    }
    else{
        int tx = update(pers[node].id_r, mid+1, cr, pos, x);
        pers[node].id_r = tx;
    }
    pers[node].mult = 1;
    if(pers[node].id_l != -1)
        pers[node].mult = (pers[node].mult * 1ll * pers[pers[node].id_l].mult) % MOD;
    if(pers[node].id_r != -1)
        pers[node].mult = (pers[node].mult * 1ll * pers[pers[node].id_r].mult) % MOD;
    return node;
}

int query(int node, int cl, int cr, int tl, int tr){
    if(node == -1 ) return 1;
    if(cr < tl || cl > tr) return 1;
    if(cl >= tl && cr <= tr){
        return pers[node].mult;
    }
    int mid = (cl + cr) / 2;
    return (query(pers[node].id_l, cl, mid, tl, tr) * 1ll * query(pers[node].id_r, mid + 1, cr, tl, tr)) % MOD;
}
int root[N];


int main(){
    fastIO;
    low[1] = 1;
    for(int i = 2; i < M; i ++ ){
        if(low[i] == 0){
            for(int j = i ; j < M; j += i){
                if(low[j] == 0)
                    low[j]=i;
            }
        }
    }
    for(int i = 0 ; i < M ; i ++ )
        pos[i]=-1;
    int n;
    cin >> n;
    int sol = 0;
    for(int i = 2; i < K ; i ++ ){
        if(low[i] == i)
            g.push_back(i);
    }
    int a;
    vector<int> R(P);
    pers[0] = {1, -1, -1};
    for(int i = 0 ; i < n; i ++ ){
        cin >> a;
        for(int j = 0;  j < g.size(); j ++ ){
            R[j] = 0;
            while(a % g[j] == 0){
                a /= g[j];
                R[j] ++ ;
            }
        }
        upd(1, 0, n - 1, i, R);

        if(i == 0) root[i] = 0;
        else root[i] = root[i - 1];
        root[i] = update(root[i], 0, n - 1, i, a);
        if(pos[a] != -1)
            root[i] = update(root[i], 0, n - 1, pos[a], 1);
        pos[a]=i;

    }
    int q;
    cin >> q;
    int res = 0;
    int lf, rf;
    for(int i = 0 ; i < q; i ++ ){
        cin >> lf >> rf;
        lf = (lf + res) % n + 1;
        rf = (rf + res) % n + 1;
        if(lf > rf)
            swap(lf, rf);
        lf -- ;
        rf -- ;
        res = 1;

        R = get(1, 0, n - 1, lf, rf).mx;

        for(int j = 0 ; j < g.size(); j ++ ){
            for(int t = 0; t < R[j] ; t ++ ){
                res = (res * 1ll * g[j]) % MOD;
            }
        }
        res = (res * 1ll * query(root[rf], 0, n - 1, lf, rf)) % MOD;
        cout << res << "\n";

    }
    return 0;
}