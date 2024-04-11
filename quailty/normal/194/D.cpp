#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const long long INF=9223372036854775807;
int n,u,r,a[35],b[35],k[35],p[35];
long long ans;
void dfs(int num,int oper)
{
    if(oper==1){
        for(int i=1;i<=n;i++){
            a[i]^=b[i];
        }
        if((u-num)%2==0){
            long long res=0;
            for(int i=1;i<=n;i++){
                res+=a[i]*k[i];
            }
            ans=max(ans,res);
        }
        if(num<u)dfs(num+1,2);
        for(int i=1;i<=n;i++){
            a[i]^=b[i];
        }
    }
    else if(oper==2){
        int temp[35],ori[35];
        for(int i=1;i<=n;i++){
            ori[i]=a[i];
            temp[i]=a[p[i]]+r;
        }
        for(int i=1;i<=n;i++){
            a[i]=temp[i];
        }
        if((u-num)%2==0){
            long long res=0;
            for(int i=1;i<=n;i++){
                res+=a[i]*k[i];
            }
            ans=max(ans,res);
        }
        if(num<u){
            dfs(num+1,1);
            dfs(num+1,2);
        }
        for(int i=1;i<=n;i++){
            a[i]=ori[i];
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&u,&r);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)scanf("%d",&k[i]);
    for(int i=1;i<=n;i++)scanf("%d",&p[i]);
    if(u%2==0){
        for(int i=1;i<=n;i++){
            ans+=a[i]*k[i];
        }
    }
    else ans=-INF;
    dfs(1,1);
    dfs(1,2);
    printf("%I64d\n",ans);
    return 0;
}