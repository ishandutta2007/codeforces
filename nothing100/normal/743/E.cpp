#include<bits/stdc++.h>
#define MAXN 200010
#define inf 1e+15
using namespace std;
int n,a[1010],ans,dp[1010][300],qz[1010][8];
int find(int x,int y,int z){
    int l=x,r=n,ans=-1;
    while (l<=r){
        int mid=(l+r)/2;
        if ((qz[mid][y]-qz[x][y])>=z){
            if ((qz[mid][y]-qz[x][y])==z) ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
int check(int x){
    for (int i=0;i<=n;i++){
        for (int j=1;j<(1<<8);j++) dp[i][j]=-1;
    }
    if (x==1) for (int j=1;j<(1<<8);j++) dp[0][j]=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<8;j++)
            for (int h=x-1;h<=x;h++){
                int tmp=find(i,j,h);
                if (tmp!=-1){
                    for (int k=(1<<8)-1-(1<<j);k;k=(k-1)&((1<<8)-1-(1<<j)))
                    if (dp[i][k]!=-1) dp[tmp][k|(1<<j)]=max(dp[tmp][k|(1<<j)],dp[i][k]+h);
                    dp[tmp][1<<j]=max(dp[tmp][1<<j],h);
                }
        }
        for (int j=1;j<(1<<8);j++) dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
    }
    ans=max(ans,dp[n][(1<<8)-1]);
    if (dp[n][(1<<8)-1]!=-1) return 1;
    return 0;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++){
        for (int j=0;j<8;j++) qz[i][j]=qz[i-1][j];
        qz[i][--a[i]]++;
    }
    int l=1,r=n/8+1;
    while (l<=r){
        int mid=(l+r)/2;
        if (check(mid)) l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",ans);
}