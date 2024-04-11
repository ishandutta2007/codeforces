#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int X;

struct edge{
    int uu;
    int vv;
    int weight;
    bool operator< (const edge &ee){
        return abs(weight-X) < abs(ee.weight-X);
    }
};

const int N = 55;
int par[N];

int fin(int x){
    if(par[x] == x) return x;
    return par[x]=fin(par[x]);
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    vector<edge> init(m);
    for(int i = 0 ; i < m ; i ++ ){
        cin >> init[i].uu >> init[i].vv >> init[i].weight;
    }
    sort(init.begin(), init.end());
    vector<int> pp;
    for(int i = 0 ; i < m ; i ++ ){
        for(int j = i + 1 ; j < m ; j ++ ){
            if(init[i].weight != init[j].weight){
                pp.push_back((init[i].weight + init[j].weight)/2+1);
            }
        }
    }
    pp.push_back(0);
    sort(pp.begin(), pp.end());
    vector<vector<ll>> P;
    vector<vector<ll>> S;
    ll cum;
    pp.resize(unique(pp.begin(), pp.end()) - pp.begin());
    for(auto x : pp){
        X = x;
        sort(init.begin(), init.end());
        for(int i = 1; i <= n; i ++ ) par[i] = i;
        P.push_back({});
        S.push_back({});
        for(auto y : init){
            if(fin(y.uu) != fin(y.vv)){
                par[fin(y.uu)] = fin(y.vv);
                P.back().push_back(y.weight);
            }
        }
        sort(P.back().begin(), P.back().end());
        cum = 0;
        for(auto x : P.back()){
            cum += x;
            S.back().push_back(cum);
        }
    }
    int p, k;
    cin >> p >> k;
    int a, b, c;
    cin >> a >> b >> c;
    ll q = 0;
    int id;
    int pre;
    ll soln = 0;
    ll xr = 0;
    ll comp;
    for(int i = 1; i <= k ; i ++ ){
        if(i <= p){
            cin >> q;
        }
        else{
            q = (q * 1ll * a + b) % c;
        }

        id = upper_bound(pp.begin(), pp.end(), q) - pp.begin();
        id--;
        pre = lower_bound(P[id].begin(), P[id].end(), q) - P[id].begin();
        soln = 0;
        if(pre > 0){
            cum = S[id][pre - 1];
            soln += q * 1ll * pre - cum;
        }
        if(pre < P[id].size()){
            cum = S[id].back();
            if(pre > 0) cum -= S[id][pre - 1];
            soln += cum - q * 1ll * (P[id].size() - pre);
        }
        xr ^= soln;
    }
    cout << xr << "\n";
    return 0;
}