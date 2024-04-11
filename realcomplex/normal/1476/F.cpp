#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 100;
int dp[N];
int las[N];
int p[N];

int segt[N * 2 + 512];
int lim;

void upd(int id, int v){
    id += lim;
    segt[id]=v;
    id /= 2;
    while(id > 0){
        segt[id]=max(segt[id*2],segt[id*2+1]);
        id /= 2;
    }
}

int get(int li, int ri){
    li += lim;
    ri += lim;
    int sol = 0;
    while(li <= ri){
        if(li % 2 == 1) sol = max(sol, segt[li ++ ]);
        if(ri % 2 == 0) sol = max(sol, segt[ri -- ]);
        li /= 2;
        ri /= 2;
    }
    return sol;
}

void upd_dp(int idx, int vl, int q){
    if(vl <= dp[idx]) return ;
    dp[idx]=vl;
    las[idx]=q;
}

char out[N];

int best[N * 4 + 512];

void build(int node, int cl, int cr){
    best[node]=-(int)1e9;
    if(cl==cr) return;
    int mid = (cl + cr) / 2;
    build(node * 2, cl, mid);
    build(node * 2 + 1, mid + 1, cr);
}

void setv(int node, int cl, int cr, int id, int vv){
    if(cl == cr){
        best[node]=vv;
        return;
    }
    int mid = (cl + cr) / 2;
    if(mid >= id)
        setv(node*2,cl,mid,id,vv);
    else
        setv(node*2+1,mid+1,cr,id,vv);
    best[node]=max(best[node*2],best[node*2+1]);
}

int get(int node, int cl, int cr, int f){
    // find first value >= f
    if(best[node] < f) return -1;
    if(cl == cr)
        return cl;
    int mid = (cl + cr) / 2;
    if(best[node * 2] >= f)
        return get(node * 2, cl, mid, f);
    else
        return get(node * 2 + 1, mid + 1, cr, f);
}


void solve(){
    int n;
    cin >> n;
    lim = n + 1;
    for(int j = 0 ; j < lim * 2; j ++ ){
        segt[j]=0;
    }
    for(int i = 1 ; i <= n; i ++ ){
        las[i]=-2;
        dp[i]=-1;
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> p[i];
        upd(i, i + p[i]);
    }
    build(1, 0, n);
    setv(1, 0, n, 0, 1);
    int nx;
    int j;
    for(int i = 1; i <= n; i ++ ){
        if(dp[i-1] >= i){
            upd_dp(i, max(dp[i-1],i+p[i]), -1);
        }
        if(p[i] > 0){
            j = get(1, 0, n, i - p[i]);
            if(j != -1){
                nx = get(j + 1, i - 1);
                upd_dp(i, max({dp[j], nx, i - 1}), j);
            }
        }
        setv(1, 0, n, i, dp[i] + 1);
    }
    if(dp[n] >= n){
        cout << "YES\n";
        int id = n;
        while(id > 0){
            if(las[id] == -1){
                out[id] = 'R';
                id -- ;
            }
            else{
                out[id] = 'L';
                for(int j = las[id] + 1; j < id; j ++ ){
                    out[j] = 'R';
                }
                id = las[id];
            }
        }
        for(int i = 1; i <= n; i ++ ){
            cout << out[i];
        }
        cout << "\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int it = 1; it <= tc; it ++ ){
        solve();
    }
    return 0;
}