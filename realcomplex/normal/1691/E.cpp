#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;

set<int> add[N];
set<int> del[N];
int col[N];
int li[N];
int ri[N];

int par[N];

int fin(int yy){
    if(yy==par[yy]) return yy;
    return par[yy]=fin(par[yy]);
}

int active[2][N];

set<int> aa[2];

void unite(int x, int y){
    x=fin(x);
    y=fin(y);
    if(x==y) return;
    par[x]=y;
    active[0][y]+=active[0][x];
    active[1][y]+=active[1][x];
}

void addd(int node){
    int cur = col[node];
    int rev = 1 - col[node];
    if(aa[rev].size() > 0){
        for(auto x : aa[rev]){
            unite(node, x);
        }
        aa[rev].clear();
        aa[rev].insert(fin(node));
        aa[cur].clear();
        aa[cur].insert(fin(node));
    }
    else{
        aa[cur].insert(fin(node));
    }
    active[cur][fin(node)] ++ ;
}

void dell(int node){
    int cur = fin(node);
    active[col[node]][cur] -- ;
    if(active[col[node]][cur] == 0){
        aa[col[node]].erase(cur);
    }

}

void solve(){
    int n;
    cin >> n;
    vector<int> qq;
    for(int i = 1; i <= n; i ++ ){
        cin >> col[i] >> li[i] >> ri[i];
        qq.push_back(li[i]);
        qq.push_back(ri[i]);
        par[i] = i;
        active[0][i] = active[1][i] = 0;
    }
    aa[0].clear();
    aa[1].clear();
    sort(qq.begin(), qq.end());
    qq.resize(unique(qq.begin(), qq.end()) - qq.begin());
    for(int i = 1; i <= n; i ++ ){
        li[i] = lower_bound(qq.begin(), qq.end(), li[i]) - qq.begin();
        ri[i] = lower_bound(qq.begin(), qq.end(), ri[i]) - qq.begin();
        add[li[i]].insert(i);
        del[ri[i]].insert(i);
    }
    int m = qq.size();
    for(int i = 0 ; i < m ; i ++ ){
        for(auto x : add[i]){
            addd(x);
        }
        for(auto x : del[i]){
            dell(x);
        }
        add[i].clear();
        del[i].clear();
    }
    int outp = 0;
    for(int i = 1; i <= n; i ++ ){
        if(par[i] == i) outp ++ ;
    }
    cout << outp << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++) {
        solve();
    }
    return 0;
}