#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first 
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
vector<pii> T[N];
bool col[N];
bool vis[N];
int ex[N];
int dep[N];
int in[N];
void dfs(int u, int pa){
    vis[u]=true;
    for(auto x : T[u]){
        if(x.fi == pa) continue;
        if(!vis[x.fi]){
            dep[x.fi] = dep[u] + 1;
            in[x.fi] = x.se;
            dfs(x.fi, u);
            col[x.se] = true;
        }
        else{
            ex[u]++;
        }
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n, m;
        cin >> n >> m;
        int u, v;
        for(int i = 1; i <= n; i ++ ) {
            vis[i]=false;
            T[i].clear();
            ex[i]=0;
        }
        for(int i = 1; i <= m ; i ++ ){
            cin >> u >> v;
            T[u].push_back(mp(v, i));
            T[v].push_back(mp(u, i));
            col[i]=false;
        }
        for(int i = 1; i <= m ; i ++ ){
            col[i]=false;
        }
        dfs(1, -1);
        int cc = 0;
        int dd = 1;
        for(int i = 1; i <= n; i ++ ){
            if(ex[i] == 2){
                cc ++ ;
                if(dep[i] > dep[dd]){
                    dd = i;
                }
            }
        }
        if(cc == 3){
            for(auto y : T[dd]){
                if(!col[y.se]){
                    col[y.se]=true;
                    col[in[dd]]=false;
                    break;
                }
            }
        }
        for(int i = 1; i <= m; i ++ )
            cout << col[i];
        cout << "\n";
        
    }
    return 0;
}