#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
const int inf=0x3f3f3f3f;
int n,i,a[400005],max_k,k;
int cnt[400005],tot,ans=inf,sum;
inline int read()
{
    int x=0,f=1;char c=getchar();
    for(;c>'9'||c<'0';c=getchar())if(c=='-')f=-1;
    for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
    return x*f;
}
inline void work()
{
    n=read(),i=read(),max_k=8*i/n;
    for(int i=1;i<=n;i++)a[i]=read();
    std::sort(a+1,a+n+1);a[0]=-1;
    for(int i=1;i<=n;i++)
        if(a[i]!=a[i-1])cnt[++tot]=1;
        else cnt[tot]++;
    k=log(tot)/log(2);
    if((1<<k)<tot)k++;
    if(k<=max_k)puts("0");
    else {
        int kk=(1<<max_k);
        for(int i=kk+1;i<=tot;i++)sum+=cnt[i];ans=std::min(ans,sum);
        for(int i=kk+1;i<=tot;i++)
        {
            sum-=cnt[i],sum+=cnt[i-kk];
            ans=std::min(ans,sum);
        }
        printf("%d\n",ans);
    }
}
int main()
{
    work();
    return 0;
}