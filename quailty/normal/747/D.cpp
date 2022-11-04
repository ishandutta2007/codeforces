#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[200005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int la=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        if(t<0)
        {
            if(la)a[cnt++]=i-la-1;
            la=i,k--;
        }
    }
    if(!la)return 0*printf("0");
    if(k<0)return 0*printf("-1");
    int res=2*(cnt+1);
    sort(a,a+cnt);
    for(int i=0;i<cnt;i++)
        if(k>=a[i])res-=2,k-=a[i];
    res-=(k>=n-la);
    return 0*printf("%d",res);
}