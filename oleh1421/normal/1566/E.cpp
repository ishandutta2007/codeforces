#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=300010;
const ll mod=998244353;
vector<int>g[N];
bool leaf[N];
int p[N];
void dfs(int v,int pr){
    leaf[v]=true;
    p[v]=pr;
    for (int to:g[v]){
        if (to==pr) continue;
        dfs(to,v);
        if (leaf[to]) leaf[v]=false;
    }
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) g[i].clear(),leaf[i]=false;
    for (int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
//    for (int i=1;i<=n;i++) cout<<leaf[i]<<" ";
//    cout<<endl;
    int res=1;
    for (int v=1;v<=n;v++){
        int cur=-1;
        for (int to:g[v]){
            if (to==p[v]) continue;
            if (leaf[to]) cur++;
        }
        res+=max(0,cur);
    }
    cout<<res<<endl;


}
int32_t main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}