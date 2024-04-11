#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll INF=(1LL<<60)-1;
ll a[MAXN],p[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<n;i++)
        a[i]=abs(a[i]-a[i+1]);
    ll res=-INF,mi[2]={0,INF};
    for(int i=1;i<=n-1;i++)
    {
        if(~i&1)a[i]=-a[i];
        p[i]=a[i]+p[i-1];
        res=max({res,p[i]-mi[0],-p[i]-mi[1]});
        mi[i&1]=min(mi[i&1],(~i&1 ? p[i] : -p[i]));
    }
    return 0*printf("%lld",res);
}