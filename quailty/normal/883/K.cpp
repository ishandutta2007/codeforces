#include<bits/stdc++.h>
#define sc scanf
#define pr printf
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef double db;
typedef long long ll;

const int N=2e5+5;
int l[N],r[N];
int ans[N];

int main()
{
    int n;
    ll sum=0;
    sc("%d",&n);
    for(int i=1;i<=n;i++)
        sc("%d%d",&l[i],&r[i]),r[i]+=l[i],sum+=l[i];
    for(int i=2;i<=n;i++)
    {
        l[i]=max(l[i],l[i-1]-1);
        r[i]=min(r[i],r[i-1]+1);
    }
    for(int i=n-1;i>0;i--)
    {
        l[i]=max(l[i],l[i+1]-1);
        r[i]=min(r[i],r[i+1]+1);
    }
    ans[0]=r[1];
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        if(l[i]<=ans[i-1]+1 && ans[i-1]+1<=r[i]) ans[i]=ans[i-1]+1;
        else if(l[i]<=ans[i-1] && ans[i-1]<=r[i]) ans[i]=ans[i-1];
        else if(l[i]<=ans[i-1]-1 && ans[i-1]-1<=r[i]) ans[i]=ans[i-1]-1;
        else return 0*puts("-1");
        res+=ans[i];
    }
    pr("%lld\n",res-sum);
    for(int i=1;i<=n;i++) pr("%d ",ans[i]);
    return 0;
}