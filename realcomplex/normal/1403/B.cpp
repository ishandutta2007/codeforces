#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
int P[N][N];
int lef[N][N];
int rig[N][N];
int up[N][N];
int down[N][N];
vector<int> xx, yy;
vector<pii> cc;

int par[N];

int fin(int x, int shf){
    if(x == par[x]) return x;
    int res = fin(par[x], shf);
    if(shf) par[x]=res;
    return res;
}

vector<pii> edg;

int cnt = 0;

void unite(int u, int v, bool keep){
    u=fin(u, !keep);
    v=fin(v, !keep);
    if(u == v) return;
    cnt ++ ;
    if(keep)
        edg.push_back(mp(u, v));
    par[u] = v;
}

struct Edge{
    int aa;
    int bb;
    int ww;
};

int main(){
    fastIO;
    int n;
    cin >> n;
    int x, y;
    for(int i = 0 ; i < n; i ++ ){
        cin >> x >> y;
        xx.push_back(x);
        yy.push_back(y);
        cc.push_back(mp(x, y));
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
    yy.resize(unique(yy.begin(), yy.end()) - yy.begin());
    int h = xx.size();
    int w = yy.size();
    for(int i = 0 ; i < N; i ++ ){
        for(int j = 0 ; j < N; j ++ ){
            P[i][j] = -1,lef[i][j]=-1,rig[i][j]=-1,up[i][j]=-1,down[i][j]=-1;
        }
    }
    int id = 0;
    for(auto &p : cc){
        p.fi = lower_bound(xx.begin(), xx.end(), p.fi) - xx.begin();
        p.se = lower_bound(yy.begin(), yy.end(), p.se) - yy.begin();
        P[p.fi][p.se] = id;
        id ++ ;
    }
    for(int i = 0 ; i < h; i ++){
        for(int j = 0 ; j < w; j ++ ){
            if(P[i][j] != -1) lef[i][j] = P[i][j];
            else if(j){
                lef[i][j]=lef[i][j-1];
            }
        }
        for(int j = w - 1; j >= 0 ; j -- ){
            if(P[i][j] != -1) rig[i][j] = P[i][j];
            else{
                rig[i][j]=rig[i][j+1];
            }
        }
    }
    for(int j = 0 ; j < w; j ++ ){
        for(int i = 0 ; i < h; i ++ ){
            if(P[i][j] != -1) up[i][j] = P[i][j];
            else if(i){
                up[i][j]=up[i-1][j];
            }
        }
        for(int i = h-1; i >= 0 ; i -- ){
            if(P[i][j] != -1) down[i][j] = P[i][j];
            else{
                down[i][j] = down[i+1][j];
            }
        }
    }
    ll li = 0, ri = (ll)2e9 + 500;
    ll mid;
    int ci, cj;
    int di, dj;
    bool ok;
    while(li < ri){
        mid = (li + ri) / 2;
        vector<Edge> qq;
        for(int i = 0 ; i <= id; i ++ )
            par[i] = i;
        cnt = 0;
        edg.clear();
        for(int i = 0 ; i < h; i ++ ){
            for(int j = 0 ; j < w; j ++ ){
                if(P[i][j] != -1){
                    ci = P[i][j];
                    di = yy[j];
                    if(j > 0){
                        cj = lef[i][j-1];
                        if(cj != -1){
                            dj = yy[cc[cj].se];
                            if(di - dj <= mid)unite(ci, cj, 0);
                            else{
                                qq.push_back({ci, cj, di - dj});
                            }
                        }

                    }
                    di = xx[i];
                    if(i > 0){
                        cj = up[i-1][j];
                        if(cj != -1){
                            dj = xx[cc[cj].fi];
                            if(di - dj <= mid)unite(ci, cj, 0);
                            else{
                                qq.push_back({ci, cj, di - dj});
                            }
                        }
                    }
                }
            }
        }
        ok = false;
        if(cnt >= id - 1){
            ok = true;
        }
        else{
            for(auto p : qq){
                if((p.ww + 1) / 2 <= mid){
                    unite(p.aa, p. bb, true);
                    if(cnt >= id - 1) ok = true;
                    while(!edg.empty()){
                        par[edg.back().fi] = edg.back().fi;
                        edg.pop_back();
                        cnt -- ;
                    }
                }
            }
            for(int i = 0 ; i < h; i ++ ){
                for(int j = 0 ; j < w; j ++ ){
                    if(P[i][j] != -1) continue;
                    di = xx[i];
                    cj = up[i][j];
                    if(cj != -1){
                        dj = xx[cc[cj].fi];
                        if(di - dj <= mid) unite(id, cj, 1);
                    }
                    cj = down[i][j];
                    if(cj != -1){
                        dj = xx[cc[cj].fi];
                        if(dj - di <= mid) unite(id, cj, 1);
                    }
                    di = yy[j];
                    cj = lef[i][j];
                    if(cj != -1){
                        dj = yy[cc[cj].se];
                        if(di - dj <= mid) unite(id, cj, 1);
                    }
                    cj = rig[i][j];
                    if(cj != -1){
                        dj = yy[cc[cj].se];
                        if(dj - di <= mid) unite(id, cj, 1);
                    }
                    if(cnt >= id) ok = true;
                    while(!edg.empty()){
                        par[edg.back().fi] = edg.back().fi;
                        edg.pop_back();
                        cnt -- ;
                    }
                }
            }
        }
        if(ok)
            ri = mid;
        else
            li = mid + 1;
    }
    if(li > (int)2e9 + 50){
        cout << "-1\n";
    }
    else{
        cout << li << "\n";
    }
    return 0;
}