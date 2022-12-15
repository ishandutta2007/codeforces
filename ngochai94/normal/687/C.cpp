#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,k,coin, dp[555][555], ans;

int main() {
    cin>>n>>k;
    dp[0][0]=1;
    For(i,0,n) {
        cin>>coin;
        for(int i=k-coin;i>=0;i--) for(int j=i;j>=0;j--) if(dp[i][j]) {
            dp[i+coin][j+coin] = 1;
            dp[i+coin][j] = 1;
        }
    }
    For(i,0,1+k) if(dp[k][i]) ans++;
    cout<<ans<<endl;
    For(i,0,k+1) if(dp[k][i]) cout<<i<<' ';
}