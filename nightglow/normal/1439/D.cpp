#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=1e6+100;
int n,m,M,f[505],g[505],dp[505][505][2],C[505][505],ans;
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
int ask(int x,int y){return dp[x][y][0];}
int main(){
    cin >> n >> m >> M;
    for (int i=0;i<=n;i++){
        C[i][0]=C[i][i]=1;
        for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
    }
    f[0]=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=i-1;j++) {
            add(f[i],1ll*f[j]*f[i-1-j]%M*(i+1)%M*C[i-1][j]%M);
            add(g[i],1ll*f[j]*g[i-1-j]%M*(i+1)%M*C[i-1][j]%M);
            add(g[i],1ll*g[j]*f[i-1-j]%M*(i+1)%M*C[i-1][j]%M);
            add(g[i],1ll*f[j]*f[i-1-j]%M*(j*(j+1)/2+(i-j-1)*(i-j)/2)%M*C[i-1][j]%M);
        }
    }
    dp[0][0][0]=1;
    for (int i=1;i<=n;i++)
    for (int j=0;j<=i;j++){
        dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1])%M;
        for (int k=1;k<=j;k++) add(dp[i][j][1],1ll*dp[i-k][j-k][0]*f[k]%M*C[j][k]%M);
    }
    for (int l=1;l<=n;l++)
    for (int r=l;r<=n;r++){
        int res=m-(r-l+1);
        if (res<0) continue;
        for (int w=0;w<=res;w++) add(ans,1ll*g[r-l+1]*dp[l-1][w][0]%M*dp[n-r][res-w][0]%M*C[m][res]%M*C[res][w]%M);
    }
    cout << ans << endl;
}