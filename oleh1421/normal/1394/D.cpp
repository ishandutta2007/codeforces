//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
const ll inf=10000000000001;
ll t[N],h[N];
vector<int>g[N];
ll dp[N][2];
void dfs(int v,int pr){
    for (int to:g[v]){
        if (to==pr) continue;
        dfs(to,v);
    }
    dp[v][0]=dp[v][1]=inf;
    if (pr){
        if (h[v]>=h[pr]){
            ///calc dp[v][0]
    //        dp[v][0]=t[v];
            int A=0,B=0,C=0;
            ll sum=0ll;
            vector<ll>u;
            for (int to:g[v]){
                if (to==pr) continue;
                if (h[to]<h[v]) A++,sum+=dp[to][1];
                else if (h[to]==h[v]) B++,sum+=dp[to][0],u.push_back(dp[to][1]-dp[to][0]);
                else C++,sum+=dp[to][0];
            }
            sort(u.begin(),u.end());
            for (int i=0;i<=B;i++){
                dp[v][0]=min(dp[v][0],sum+t[v]*(max(A+i+1,C+B-i)*1ll));
                if (i<B) sum+=u[i];
            }

        }
        if (h[v]<=h[pr]){
            ///calc dp[v][1]
    //        dp[v][0]=t[v];
            int A=0,B=0,C=0;
            ll sum=0ll;
            vector<ll>u;
            for (int to:g[v]){
                if (to==pr) continue;
                if (h[to]<h[v]) A++,sum+=dp[to][1];
                else if (h[to]==h[v]) B++,sum+=dp[to][0],u.push_back(dp[to][1]-dp[to][0]);
                else C++,sum+=dp[to][0];
            }
            sort(u.begin(),u.end());
            for (int i=0;i<=B;i++){
                dp[v][1]=min(dp[v][1],sum+t[v]*(max(A+i,C+B-i+1)*1ll));
                if (i<B) sum+=u[i];
            }

        }
    } else {
        int A=0,B=0,C=0;
        ll sum=0ll;
        vector<ll>u;
        for (int to:g[v]){
            if (to==pr) continue;
            if (h[to]<h[v]) A++,sum+=dp[to][1];
            else if (h[to]==h[v]) B++,sum+=dp[to][0],u.push_back(dp[to][1]-dp[to][0]);
            else C++,sum+=dp[to][0];
        }
        sort(u.begin(),u.end());
        for (int i=0;i<=B;i++){
            dp[v][0]=min(dp[v][0],sum+t[v]*(max(A+i,C+B-i)*1ll));
            if (i<B) sum+=u[i];
        }
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>t[i];
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    cout<<dp[1][0]<<endl;
    return 0;
}
//NNNNNNNNNNNN
//123456789012