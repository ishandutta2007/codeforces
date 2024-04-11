#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define MINX(a,b) if(a>b) a=b;
#define MAXX(a,b) if(a<b) a=b;
typedef long long ll;
using namespace std;
vector<int>g[200001];
int h[200001];
bool used[200001];
void dfs(int v,int cur){
     used[v]=true;
     h[v]=cur;
     for (auto to:g[v]){
         if (!used[to]) dfs(to,cur+1);
     }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        int n,m;cin>>n>>m;
        for (int i=1;i<=n;i++) g[i].clear();
        for (int i=1;i<=n;i++) used[i]=false;
        for (int i=1;i<=n;i++) h[i]=0;
        for (int i=1;i<=m;i++){
            int a,b;cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1,0);
        int cnt0=0;
        int cnt1=0;
        for (int i=1;i<=n;i++){
            if (h[i]%2) cnt1++;
            else cnt0++;
        }
        if (cnt0<cnt1){
            cout<<cnt0<<endl;
            for (int i=1;i<=n;i++) if (h[i]%2==0) cout<<i<<" ";
            cout<<endl;
        } else {
            cout<<cnt1<<endl;
            for (int i=1;i<=n;i++) if (h[i]%2) cout<<i<<" ";
            cout<<endl;
        }
    }

    return 0;
}
//2 6 -2 -6  2