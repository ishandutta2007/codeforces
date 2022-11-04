#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll x[200005],pre[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&x[i]);
    sort(x+1,x+n+1);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+x[i];
    ll len=0,loc=1,reu=0,red=1;
    for(int i=1;i<=n;i++)
    {
        int l=0,r=min(i-1,n-i);
        while(l<r)
        {
            int m1=(2*l+r)/3;
            int m2=(l+2*r+2)/3;
            ll lu=pre[i]-pre[i-m1-1]+pre[n]-pre[n-m1];
            ll ru=pre[i]-pre[i-m2-1]+pre[n]-pre[n-m2];
            if(lu*(2*m2+1)<ru*(2*m1+1))l=m1+1;
            else r=m2-1;
        }
        ll tu=pre[i]-pre[i-l-1]+pre[n]-pre[n-l];
        ll td=2*l+1;
        tu-=x[i]*td;
        if(tu*red>td*reu)
        {
            len=l;
            loc=i;
            reu=tu;
            red=td;
        }
    }
    printf("%I64d\n",2*len+1);
    for(int i=loc-len;i<=loc;i++)
        printf("%I64d ",x[i]);
    for(int i=n-len+1;i<=n;i++)
        printf("%I64d ",x[i]);
    return 0;
}