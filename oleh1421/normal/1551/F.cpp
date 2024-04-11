#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 120;
const ll mod=1000000007;
vector<int>g[N];
int MX=0;
int dfs(int v,int pr,int cur){
    cur--;
    if (cur==0) return 1;
    int sum=0;
    for (int to:g[v]){
        if (to!=pr){
            sum+=dfs(to,v,cur-1);
        }
    }
    return sum;
}
ll dp[N][N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=0;i<=n;i++) g[i].clear();
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if (k==1){
        cout<<n<<endl;
        return;
    }
    if (k==2){
        cout<<n*(n-1)/2<<endl;
        return;
    }
    ll res=0ll;
    for (int mid=1;mid<=n;mid++){
        for (int depth=1;depth<n;depth++){
            vector<int>u;
            for (int to:g[mid]){
                u.push_back(dfs(to,mid,depth));
            }
            int m=u.size();
            for (int i=0;i<=m;i++){
                for (int j=0;j<=m;j++){
                    dp[i][j]=0;
                }
            }
            dp[0][0]=1;
            for (int i=0;i<m;i++){
                for (int j=0;j<=i;j++){
                    dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
                    dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*(u[i]*1ll))%mod;
                }
            }
            res+=(dp[m][k]);
            res%=mod;
        }
    }
    cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}