#include<cstdio>
using namespace std;
int n,t,i,nn,p[2000010],tmp,x;
long long ans;
int main()
{
    scanf("%d",&n);nn=n;
    while(n>=0)
    {
        for(t=0;n>>t;t++);t--;x=(1<<t+1)-1;
        for(i=1<<t;i<=n;i++)p[i]=x-i,p[x-i]=i;n=x-n-1;
    }for(i=0;i<=nn;i++)ans+=i^p[i];printf("%I64d\n",ans);
    for(i=0;i<=nn;i++)printf("%d ",p[i]);
}