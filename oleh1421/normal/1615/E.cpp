#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int ll
using namespace std;
const int N=2000100;
const ll mod=998244353;
vector<int>g[N];
int go[N];
int h[N];
int val[N];
void dfs(int v,int pr){
    go[v]=v;
    for (int to:g[v]){
        if (to!=pr){
            h[to]=h[v]+1;
            dfs(to,v);
            if (h[go[to]]>h[go[v]]) go[v]=go[to];
        }
    }
    val[go[v]]++;
}
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) g[i].clear();

    for (int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    h[1]=0;
    dfs(1,0);
    sort(val+1,val+n+1);
    reverse(val+1,val+n+1);
    int w=0;
    for (int i=1;i<=k;i++){
        w+=val[i];
    }
    if (n-w>k){
        ///B
        w=0;
        int r=k;
        for (int i=1;i<=k;i++){
            w+=val[i]-1;
        }
        ll res=0ll;
        for (int b=0;b<=n-r-w;b++){
            res=min(res,1ll*(n-r-b)*(r-b));
        }
        cout<<res<<endl;
    } else {
        ///R
        w=0;
        ll res=0;
        for (int i=1;i<=k;i++){
            w+=val[i]-1;
            res=max(res,1ll*w*(i-(n-w-i)));
        }
        cout<<res<<endl;
    }


}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**

4
3 3
1 2 -1
1 3 -1
1 2 0
1 3 1
2 3 0
2 1
1 2 1
1 2 0
6 5
1 2 -1
1 3 1
4 2 7
6 3 0
2 5 -1
2 3 1
2 5 0
5 6 1
6 1 1
4 5 1
5 3
1 2 -1
1 3 -1
1 4 1
4 5 -1
2 4 0
3 4 1
2 3 1


**/