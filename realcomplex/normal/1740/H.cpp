#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Node{
    int chk;
    int v[2];
    int sum[2];
};

const int N = (int)3e5 + 10;

Node tr[N * 4 + 512];

Node unite(Node A, Node B){
    Node res;
    res.chk = A.chk;
    for(int i = 0 ; i < 2; i ++ ){
        res.sum[i] = A.sum[i];
        if(A.v[i] == B.chk) {
            res.v[i] = B.v[0];
            res.sum[i] += B.sum[0];
        }
        else{
            res.v[i] = B.v[1];
            res.sum[i] += B.sum[1];
        }
    }
    return res;
}

void update(int node, int cl, int cr, int id, int m0, int m1){
    if(cl == cr){
        tr[node].chk = m0;
        tr[node].v[0] = tr[node].sum[0] = m1;
        tr[node].v[1] = tr[node].sum[1] = m0;
        return;
    }
    int mid = (cl + cr) / 2;
    if(mid >= id){
        update(node * 2, cl, mid, id, m0, m1);
    }
    else{
        update(node * 2 + 1, mid + 1, cr, id, m0, m1);
    }
    tr[node] = unite(tr[node * 2], tr[node * 2 + 1]);
}

Node gg;
bool take;

void get(int node, int cl, int cr, int lf, int rf){
    if(node == 1) take = false;
    if(cr < lf || cl > rf) return;
    if(cl >= lf && cr <= rf){
        if(!take){
            gg = tr[node];
            take=true;
        }
        else{
            gg = unite(gg, tr[node]);
        }
        return;
    }
    int mid = (cl + cr) / 2;
    get(node * 2, cl, mid, lf, rf);
    get(node * 2 + 1, mid + 1, cr, lf, rf);
}

vector<int> T[N];
int par[N];
int sub[N];
void dfs(int u){
    sub[u]=1;
    for(auto x : T[u]){
        dfs(x);
        sub[u] += sub[x];
    }
}

int id[N];
int link[N];
int low[N];
int idx;

void heavy(int u){

    if(link[u] == 0){
        link[u]=u;
    }

    int big = -1;
    for(auto x : T[u]){
        if(big == -1 || sub[x] > sub[big]){
            big = x;
        }
    }
    for(auto x : T[u]){
        if(x != big){
            heavy(x);
        }
    }
    if(big == -1){
        idx ++ ;
        id[u] = idx;
    }
    else{
        link[big]=link[u];
        heavy(big);
        idx ++ ;
        id[u] = idx;
    }
}

const int M = 22;
int cnt[N][M];
int fmex[N];
bool on[N];


int total;

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    n ++ ;
    par[1] = 0;
    for(int i = 2; i <= n; i ++ ){
        cin >> par[i];
        T[par[i]].push_back(i);
    }
    dfs(1);
    heavy(1);
    for(int i = 1; i <= n; i ++ ){
        fmex[i] = -1;
    }
    low[1] = 1;
    update(1, 1, n, id[1], 0, 1);
    int go;
    int mex0, mex1;
    int en;
    int st;
    int ff;
    bool kan;
    for(int ii = 2; ii <= n; ii ++ ){
        go = ii;
        while(go != 0){
            mex0 = mex1 = -1;
            for(int i = 0 ; i < M; i ++ ){
                if(cnt[go][i] == 0){
                    if(mex0 == -1){
                        mex0 = i;
                    }
                    else{
                        mex1 = i;
                        break;
                    }
                }
            }
            en = link[go];
            st = low[en];
            if(en != ii){
                get(1, 1, n, id[st], id[en]);
                total -= gg.sum[1];
                cnt[par[en]][gg.v[1]] -- ;
            }
            if(go == ii){
                low[link[go]] = ii;
                st = ii;
            }
            update(1, 1, n, id[go], mex0, mex1);
            if(on[go]){
                fmex[go] = mex0;
            }
            get(1, 1, n, id[st], id[en]);
            total += gg.sum[1];
            cnt[par[en]][gg.v[1]] ++ ;
            go = par[en];
            on[go]=true;
        }
        cout << total << "\n";
    }
    return 0;
}