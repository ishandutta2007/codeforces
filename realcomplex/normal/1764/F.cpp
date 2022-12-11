#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2010;
ll F[N][N];
ll D[N][N];

struct edge{
    ll weight;
    int ui;
    int vi;
    bool operator< (const edge &E) const {
        return weight < E.weight;
    }
};

int par[N];

int fin(int u){
    if(par[u] == u) return u;
    return par[u]=fin(par[u]);
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= i ; j ++ ){
            cin >> F[i][j];
            if(i != j) F[j][i] = F[i][j];
        }
        par[i] = i;
    }
    vector<edge> E;
    for(int i = 1; i <= n; i ++ ){
        for(int j = i + 1; j <= n; j ++ ){
            D[i][j] = (F[i][i] + F[j][j] - 2ll * F[i][j]) / (ll)n;
            E.push_back({D[i][j], i, j});
        }
    }
    sort(E.begin(), E.end());
    for(auto ee : E){
        if(fin(ee.ui) != fin(ee.vi)){
            par[fin(ee.ui)] = fin(ee.vi);
            cout << ee.ui << " " << ee.vi << " " << ee.weight << "\n";
        }
    }
    return 0;
}