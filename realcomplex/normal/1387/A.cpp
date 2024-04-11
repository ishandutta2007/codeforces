#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
const ld EPS = 1e-9;
bool vis[N];
ld a[N], b[N];
ld sol[N];
vector<int> nds;
vector<pair<int,ld>> T[N];

void dfs(int node){
    nds.push_back(node);
    vis[node]=true;
    for(auto x : T[node]){
        if(vis[x.fi]) continue;
        a[x.fi]=-a[node];
        b[x.fi]=x.se-b[node];
        dfs(x.fi);
    }
}

ld compute(ld x){
    ld sum = 0;
    for(auto t : nds){
        sum += abs(a[t] * x + b[t]);
    }
    return sum;
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int u, v;
    ld c;
    for(int i = 1; i <= m ; i ++ ){
        cin >> u >> v >> c;
        T[u].push_back(mp(v, c));
        T[v].push_back(mp(u, c));
    }
    ld pl;
    for(int i = 1; i <= n; i ++ ){
        if(vis[i]) continue;
        nds.clear();
        a[i]=1;
        b[i]=0;
        dfs(i);
        set<ld> cand;
        for(auto x : nds){
            for(auto fk : T[x]){
                u = x;
                v = fk.fi;
                ld y = fk.se - (b[u] + b[v]);
                ld f = (a[u] + a[v]);
                if(f == 0){
                    if(y != 0){
                        cand.insert(0);
                        cand.insert(1);
                    }
                }
                else{
                    cand.insert((ld)(y/f));
                }
            }
        }
        if(cand.size() > 1){
            cout << "NO\n";
            return 0;
        }
        if(cand.size() == 1){
            auto it = cand.begin();
            pl = *it;
        }
        else{
            ld li = -(ld)1e9, ri = (ld)1e9;
            ld f1, f2;
            while(ri - li > EPS){
                f1 = (li + li + ri) / 3.0;
                f2 = (li + ri + ri) / 3.0;
                if(compute(f1) > compute(f2)) // cant be to left of f1
                    li = f1;
                else
                    ri = f2;
             }
             pl = li;
        }
        for(auto x : nds){
            sol[x] = pl * a[x] + b[x];
        }
    }
    cout << "YES\n";
    for(int q = 1 ; q <= n; q ++ ){
        cout << fixed << setprecision(6) << sol[q] << "\n";
    }
    return 0;
}