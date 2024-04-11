#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
const int MAXP=10005;
int p[MAXP],np[MAXP];
void build()
{
    for(int i=2;i<MAXP;i++)if(!np[i])
    {
        p[++p[0]]=i;
        for(int j=i+i;j<MAXP;j+=i)np[j]=1;
    }
}
int a[MAXN],x[MAXN],cnt[MAXN],res[MAXN];
int main()
{
    build();
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]!=0)for(int j=1;j<=p[0];j++)
        {
            int t=p[j]*p[j];
            while(a[i]%t==0)a[i]/=t;
        }
        x[i]=a[i];
    }
    sort(x+1,x+n+1);
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(x+1,x+n+1,a[i])-x;
    int zero=0;
    for(int i=n;i>=1;i--)
        if(x[i]==0)zero=i;
    for(int i=1;i<=n;i++)
    {
        int now=0;
        for(int j=i;j<=n;j++)
        {
            if((cnt[a[j]]++)==0)now++;
            res[now-(now>1 && cnt[zero]>0)]++;
        }
        for(int j=i;j<=n;j++)
            cnt[a[j]]--;
    }
    for(int i=1;i<=n;i++)
        printf("%d%c",res[i]," \n"[i==n]);
    return 0;
}