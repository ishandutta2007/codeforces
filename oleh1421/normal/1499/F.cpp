//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
const int N=5010;
const ll mod=998244353;
vector<int>g[N];
ll dp[N][N];
int h[N];
int n,k;
ll dp1[N];
void dfs(int v,int pr){
    h[v]=0;
    dp[v][0]=1ll;
    for (int to:g[v]){
        if (to==pr) continue;
        dfs(to,v);
        ll sum=0ll;
        for (int j=0;j<=h[to];j++){
            sum+=dp[to][j];
            sum%=mod;
        }
        for (int i=0;i<=max(h[v],h[to]+1);i++) dp1[i]=0ll;
        for (int i=0;i<=h[v];i++) dp1[i]=(dp[v][i]*sum)%mod;
        for (int i=h[v];i>=0;i--){
            for (int j=0;j<=h[to];j++){
                if (i+j+1<=k){
                    dp1[max(i,j+1)]+=dp[to][j]*dp[v][i];
                    dp1[max(i,j+1)]%=mod;
                }
            }
        }
        for (int i=0;i<=max(h[v],h[to]+1);i++) {
            dp[v][i]=dp1[i];
            dp1[i]=0ll;
        }

        h[v]=max(h[v],h[to]+1);

//        cout<<"OK "<<v<<" "<<to<<" "<<h[v]<<endl;
//        for (int i=0;i<=h[v];i++) cout<<dp[v][i]<<" ";
//        cout<<endl;
    }

}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for (int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    ll res=0ll;
    for (int i=0;i<=h[1];i++) res+=dp[1][i];
    cout<<res%mod<<endl;
    return 0;
}
/**
a
b 2 4 = 8

aa 1 2 =2
b

a  1 2 =2
bb

aa
bb 2 1 =2
**/