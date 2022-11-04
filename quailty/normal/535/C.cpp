#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
ll A,B,n,t,m;
ll h(int x)
{
    return A+(x-1)*B;
}
bool judge(ll lef,ll loc)
{
    ll hl=h(loc);
    ll temp=(ll)((loc+lef)*(loc-lef+1)/2*B+(loc-lef+1)*(A-B));
    ll k=min(m,loc-lef+1);
    if(temp%k==0)temp=temp/k;
    else temp=temp/k+1;
    if(t>=max(h(loc),temp))return 1;
    else return 0;
}
int main()
{
    scanf("%I64d%I64d%I64d",&A,&B,&n);
    for(int i=1;i<=n;i++)
    {
        ll l;
        scanf("%I64d%I64d%I64d",&l,&t,&m);
        ll lef=l,rig=3000005;
        while(lef<rig)
        {
            ll mid=(rig+lef+1)/2;
            if(judge(l,mid))lef=mid;
            else rig=mid-1;
        }
        if(!judge(l,lef))printf("-1\n");
        else printf("%d\n",lef);
    }
    return 0;
}