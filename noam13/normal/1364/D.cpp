#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e18, MOD = 1e9+7;

int n,m,k;
vvi g;
vi d,iset;
vb check;

int dfs(int cur, int p=-1, int dp=1){
    //cout<<"VISIT: "<<cur<<endl;
    d[cur] = dp;
    for(auto nei:g[cur]) if(nei!=p) {
        //cout<<"DEB: "<<cur<<" "<<nei<<" "<<d[nei]<<endl;
        if (d[nei]==-1){
            int v = dfs(nei, cur, dp+1);
            if (v==cur){
                cout<<cur+1<<endl;
                exit(0);
            }
            if (v!=-1) {
                cout<<cur+1<<" ";
                return v;
            }
        }
        else if (d[nei]>d[cur]) continue;
        else if (d[cur]-d[nei]+1<=k){
            cout<<2<<endl;
            cout<<(d[cur]-d[nei]+1)<<endl;
            cout<<cur+1<<" ";
            return nei;
        }
    }
    if (!check[cur]){
        iset.pb(cur);
        for(auto nei:g[cur]) check[nei]=1;
    }
    return -1;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    g.resize(n); d.resize(n,-1); check.resize(n,0);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--,b--;
        g[a].pb(b); g[b].pb(a);
    }
    dfs(0);
    cout<<1<<endl;
    loop(i,0,(k+1)/2) cout<<iset[i]+1<<" ";
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ EhabCorollary.cpp -o a & a
4 4 3
1 2
2 3
3 4
4 1



 
 
 
 
 
*/