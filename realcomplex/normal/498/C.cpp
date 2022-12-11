#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<int> factor(int p){
    vector<int> res;
    for(int j = 2; j * j <= p ; j ++ ){
        while(p % j == 0){
            res.push_back(j);
            p/=j;
        }
    }
    if(p != 1)
        res.push_back(p);
    return res;
}

const int N = 105;
const int MAX = (int)1e4 + 3;

vector<int> X, Y;
int xl[N];
int xr[N];
int yl[N];
int yr[N];

vector<int> T[MAX];
int match[MAX];
bool use[MAX];
bool vis[MAX];
int dist[MAX];

bool dfs(int u){
    vis[u] = true;
    for(auto p : T[u]){
        if(match[p] == -1 || (!vis[match[p]] && dist[match[p]] == dist[u] + 1 && dfs(match[p]))){
            match[p] = u;
            use[u] = true;
            return true;
        }
    }
    return false;
}

int fin(){
    for(int i = 0 ; i < MAX; i ++ )
        match[i] = -1, use[i] = false;
    int res = 0;
    int f = 0;
    int cur;
    while(1){
        for(int j = 0 ; j < MAX;j ++ )
            dist[j] = -1;
        queue<int> ff;
        for(int j = 0 ; j < MAX;j  ++ ){
            if(use[j] == false){
                ff.push(j);
                dist[j] = 0;
            }
        }
        while(!ff.empty()){
            cur = ff.front();
            ff.pop();
            for(auto p : T[cur]){
                if(match[p] != -1 && dist[match[p]] == -1){
                    dist[match[p]] = dist[cur] + 1;
                    ff.push(match[p]);
                }
            }
        }
        for(int j = 0 ; j < MAX; j ++ ) vis[j] = false;
        f = 0;
        for(int j = 0 ; j < MAX;j ++ ){
            if(!use[j]){
                f += dfs(j);
            }
        }
        if(!f)
            return res;
        res += f;
    }
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    vector<int> ff[n];
    int a;
    for(int i = 0 ;i  < n; i ++ ){
        cin >> a;
        ff[i] = factor(a);
        if(i % 2 == 0) {
            xl[i] = (int)X.size();
            for(auto p : ff[i]) X.push_back(p);
            xr[i] = (int)X.size();
        }
        else{
            yl[i] = (int)Y.size();
            for(auto p : ff[i]) Y.push_back(p);
            yr[i] = (int)Y.size();
        }
    }
    int p, q;
    int vi, vj;
    for(int i = 0 ; i < m; i ++ ){
        cin >> p >> q;
        --p;
        --q;
        if(q % 2 == 0)
            swap(p, q);
        vi = xl[p];
        vj = yl[q];

        for(int v = vi ; v < xr[p] ; v ++ ){
            for(int z = vj ; z < yr[q]; z ++ ){
                if(X[v] == Y[z]){
                    T[v].push_back(z);
                }
            }
        }
    }
    cout << fin();
    return 0;
}