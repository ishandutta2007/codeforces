#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=300010;
const ll mod=998244353;
int dp[N];
vector<int>g[N];
int mn[N];
int p[N];
void dfs(int v,int pr){
    mn[v]=v;
    p[v]=pr;
    for (int to:g[v]){
        if (to!=pr){
            dfs(to,v);
            mn[v]=min(mn[v],mn[to]);
        }
    }
    dp[v]=0;
    for (int to:g[v]){
        if (to!=pr){
//            if (mn[to]>k)
            dp[v]^=dp[to]+1;
//            else dp[v]^=(dp[to]^1);
        }
    }
}
bool used[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    string ans="";
    int res=(dp[1]);
    if (res) ans+="1";
    else ans="2";
    used[1]=true;
//    cout<<res<<endl;
    for (int i=2;i<=n;i++){
        if (!used[i]){
            int v=i;
            vector<int>u;
            while (!used[v]){
                u.push_back(v);
                used[v]=true;
                v=p[v];
            }
            reverse(u.begin(),u.end());
            res^=dp[u[0]]+1;
            for (int i=1;i<u.size();i++){
                dp[u[i-1]]^=dp[u[i]]+1;
            }
            for (int i=(int)u.size()-2;i>=0;i--){
                dp[u[i]]^=(dp[u[i+1]]^1);
            }
            res^=(dp[u[0]]^1);
        }
        if (res) ans+="1";
        else ans+="2";
//        cout<<i<<" "<<dp[1]<<" "<<res<<endl;
    }
    cout<<ans<<endl;
}
int32_t main()
{

    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
//5
//1 2
//2 3
//2 4
//4 5
/**
6 5
1 3 6
2 6 4
2 4 2
5 4 3
2 5 2
0
**/