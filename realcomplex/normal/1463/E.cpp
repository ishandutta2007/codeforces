#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
vector<int> T[N];
vector<int> Q[N];
vector<int> Z[N];
int idx[N];
int ins[N];
int pp[N];
bool inq[N];
int cnt = 0;

void dfs(int u, int id){
    idx[u]=id;
    Z[id].push_back(u);
    for(auto x : Q[u]){
        if(idx[x] == 0){
            dfs(x,id);
            cnt ++ ;
        }

    }
}

vector<int> R[N];

void dfs1(int u){
    for(auto x : T[u]){
        if(idx[u] != idx[x]){
            R[idx[u]].push_back(idx[x]);
        }
        dfs1(x);
    }
}

int vis[N];

bool cycle = false;
vector<int> en;

void topo(int u){
    vis[u]=1;
    for(auto x : R[u]){
        if(vis[x]==1){
            cycle=true;
        }
        else if(vis[x] == 0){
            topo(x);
        }
    }
    vis[u]=2;
    en.push_back(u);
}

int main(){
    fastIO;
    int n, k;
    cin >> n >> k;
    int p;
    int root = -1;
    inq[0]=true;
    for(int i = 1; i <= n; i ++ ){
        cin >> p;
        pp[i]=p;
        if(p == 0) root = i;
        else T[p].push_back(i);
    }
    int xi, yi;
    for(int i = 1; i <= k ; i ++ ){
        cin >> xi >> yi;
        Q[xi].push_back(yi);
        ins[yi]++;
    }
    int id = 1;
    for(int i = 1; i <= n ; i ++ ){
        if(ins[i] == 0){
            dfs(i,id);
            id++;
        }
    }
    if(cnt != k){
        cout << 0 << endl;
        return 0;
    }
    dfs1(root);
    for(int i = 1; i <= id; i ++ ){
        if(vis[i]==0){
            topo(i);
        }
    }
    reverse(en.begin(), en.end());
    vector<int> soln;
    for(auto x : en){
        for(auto y : Z[x]){
            soln.push_back(y);
        }
    }
    for(auto r : soln){
        if(!inq[pp[r]]){
            cout << "0\n";
            exit(0);
        }
        inq[r]=true;
    }
    for(auto r : soln)
        cout << r << " ";
    return 0;
}