#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int sum[510][510];
int in[510][510];
inline int s(int l,int r,int u,int d){
//   printf("   %d %d %d %d %d\n",l,r,u,d,sum[r][d]+sum[l][u]-sum[l][d]-sum[r][u]);
    return sum[r][d]+sum[l-1][u-1]-sum[l-1][d]-sum[r][u-1];
}
int main(){
    int n,m,i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)for(j=1;j<=m;j++){
        scanf("%d",&in[i][j]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+in[i][j];
        }
    }
    int ms=-2147483647;
    for(i=1;i<=n;i++)for(j=1;j<=m;j++){
        int q=0;
        for(k=1;i>k&&i<=n-k&&j>k&&j<=m-k;k+=2){
            if(k==1)q=s(i-1,i+1,j+1,j+1)+s(i-1,i-1,j-1,j)+s(i+1,i+1,j-1,j);
            else{
                q+=in[i-(k-2)][j-(k-1)]+s(i-(k-2),i+k,j-k,j-k)+s(i+k,i+k,j-(k-1),j+k)+s(i-k,i+(k-1),j+k,j+k)+s(i-k,i-k,j-k,j+(k-1));
            }
            if(q>ms)ms=q;
        }
    }
    for(i=1;i<=n;i++)for(j=1;j<=m;j++){
        int q=in[i][j];
        for(k=2;i>k&&i<=n-k&&j>k&&j<=m-k;k+=2){
            q+=in[i-(k-2)][j-(k-1)]+s(i-(k-2),i+k,j-k,j-k)+s(i+k,i+k,j-(k-1),j+k)+s(i-k,i+(k-1),j+k,j+k)+s(i-k,i-k,j-k,j+(k-1));
            if(q>ms)ms=q;
        }
    }
    printf("%d\n",ms);
}