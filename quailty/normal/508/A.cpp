#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
bool ma[1005][1005];
bool judge(int i,int j)
{
    if(ma[i-1][j]&&ma[i][j-1]&&ma[i-1][j-1])return 1;
    if(ma[i+1][j]&&ma[i][j-1]&&ma[i+1][j-1])return 1;
    if(ma[i-1][j]&&ma[i][j+1]&&ma[i-1][j+1])return 1;
    if(ma[i+1][j]&&ma[i][j+1]&&ma[i+1][j+1])return 1;
    return 0;
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int a,b;
    int ans=0;
    bool flag=1;
    for(int i=1;i<=k;i++){
        scanf("%d%d",&a,&b);
        ma[a][b]=1;
        if(flag&&judge(a,b)){
            ans=i;
            flag=0;
        }
    }
    printf("%d",ans);
    return 0;
}