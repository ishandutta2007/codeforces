#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int p[N];
vector<pii> T[N];
int u[N], v[N];

vector<int> P[N];
bool vis[N];
int num[N];

bool cum[N];

vector<int> sol;

void dfs(int u){
    cum[u]=true;
    for(auto x : P[u]){
        if(!cum[x])
            dfs(x);
    }
    sol.push_back(u);
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        cin >> p[i];
    }
    for(int i = 1; i <= m; i ++ ){
        cin >> u[i] >> v[i];
        T[u[i]].push_back(mp(v[i], i));
        T[v[i]].push_back(mp(u[i], i));
    }
    int node;
    int cnt = 0;
    vector<int> cyc;
    for(int i = 1; i <= n; i ++ ){
        if(vis[i]) continue;
        node = i;
        cnt = 0;
        cyc.clear();
        while(!vis[node]){
            vis[node]=true;
            num[node]=cnt;
            cyc.push_back(node);
            cnt++;
            node=p[node];
        }
        for(auto x : cyc){
            vector<pii> ord;
            for(auto y : T[x]){
                ord.push_back(mp((num[y.fi]-num[x] + cnt) % cnt,y.se));
            }
            sort(ord.begin(), ord.end());
            for(int j = 0; j + 1 < ord.size(); j ++ ){
                P[ord[j].se].push_back(ord[j + 1].se);
            }
        }
    }
    for(int i = 1; i <= m; i ++ ){
        if(!cum[i]){
            dfs(i);
        }
    }
    reverse(sol.begin(), sol.end());
    for(auto q : sol)
        cout << q << " ";
    cout << "\n";
    return 0;
}