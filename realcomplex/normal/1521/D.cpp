#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;

vector<pii> delet;
vector<int> T[N];
int lef[N];
int rig[N];

vector<pii> segm;
bool en[N];

int dfs(int u, int pp){
    int cur = 2;
    int gg;
    lef[u] = u;
    rig[u] = u;
    en[u]=true;
    for(auto x : T[u]){
        if(x == pp) continue;
        gg = dfs(x, u);
        if(gg > 0 && cur > 0){
            en[x]=false;
            if(cur == 2){
                lef[u] = lef[x];
            }
            else if(cur == 1){
                rig[u] = lef[x];
            }
            cur -- ;
        }
        else{
            delet.push_back(mp(u, x));
        }
    }
    return cur;
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        delet.clear();
        segm.clear();
        for(int i = 1; i <= n; i ++ ){
            T[i].clear();
            en[i]=false;
        }
        int u, v;
        for(int i = 1; i < n; i ++ ){
            cin >> u >> v;
            T[u].push_back(v);
            T[v].push_back(u);
        }
        dfs(1, -1);
        for(int i = 1; i <= n; i ++ ){
            if(en[i])
                segm.push_back(mp(lef[i], rig[i]));
        }
        cout << delet.size() << "\n";
        for(int i = 0 ; i < delet.size(); i ++ ){
            cout << delet[i].fi << " " << delet[i].se << " " << segm[i].se << " " << segm[i+1].fi << "\n";
        }
    }
    return 0;
}