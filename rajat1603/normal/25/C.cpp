#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a[301][301]={0},k,x,y,z,sum=0;
    scanf("%I64d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;scanf("%I64d",&a[i][j++]));
    scanf("%I64d",&k);
    while(k--){
        scanf("%I64d%I64d%I64d",&x,&y,&z);
        sum=0;
        if(a[x][y]>z)
            for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=min(min(a[i][x]+z+a[y][j],a[i][y]+z+a[x][j]),a[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<i;sum+=a[i][j++]);
        printf("%I64d\n",sum);
    } 
}