#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int opt[N];

struct Edge{
    int ui;
    int vi;
    int state;
    int rev;
    int delet;
};

vector<Edge> save;

int par[N];
int col[N];
int sz[N];


pii fin(int x){
    int cl = col[x];
    while(par[x] != x){
        x = par[x];
        cl ^= col[x];
    }
    return mp(x, cl);
}

int bad = 0;

void unite(int a, int b, int dsh){
    pii ca = fin(a);
    pii cb = fin(b);
    if(ca.fi == cb.fi){
        if(ca.se == cb.se){
            bad ++ ;
            save.push_back({ca.fi, cb.fi, 0, 0, dsh});
        }
    }
    else{
        bool xr = false;
        if(sz[ca.fi] > sz[cb.fi]) swap(ca, cb);
        if(ca.se == cb.se){
            col[ca.fi] ^= 1;
            xr = true;
        }
        par[ca.fi]=cb.fi;
        sz[cb.fi] += sz[ca.fi];
        save.push_back({ca.fi, cb.fi, 1, xr, dsh});
    }
}

void roll(int idx){
    while(!save.empty() && save.back().delet == idx){
        if(save.back().state == 0){
            bad -- ;
        }
        else{
            sz[save.back().vi] -= sz[save.back().ui];
            col[save.back().ui] ^= save.back().rev;
            par[save.back().ui] = save.back().ui;
        }
        save.pop_back();
    }
}

int u[N], v[N];

void compute(int l, int r, int optl, int optr){
    if(l > r) return;
    int mid = (l + r) / 2;
    opt[mid]=optr;
    for(int j = l ; j <= mid; j ++ ){
        if(j)
            unite(u[j], v[j], mid);
    }
    while(bad == 0 && opt[mid] > 0){
        opt[mid] -- ;
        if(opt[mid] > 0)
            unite(u[opt[mid]], v[opt[mid]], mid);
    }


    roll(mid);
    for(int j = optr - 1; j >= opt[mid]; j -- ){
        unite(u[j], v[j], mid);
    }
    compute(l, mid - 1, optl, opt[mid]);
    roll(mid);
    for(int j = l; j <= mid ; j ++ ){
        if(j)
            unite(u[j], v[j], mid);
    }
    compute(mid+1, r, opt[mid], optr);
    roll(mid);
}


int main(){
    fastIO;
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i ++ ){
        par[i] = i;
        sz[i]=1;
    }
    for(int i = 1; i <= m; i ++ ){
        cin >> u[i] >> v[i];
    }
    compute(0, m, 0, m + 1);
    int cl, cr;
    for(int i = 1; i <= q; i ++ ){
        cin >> cl >> cr;
        if(opt[cl - 1] > cr){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}