#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500005;
ll a[MAXN],now[MAXN],tmp[MAXN],add[MAXN];
bool check(int n,int r,ll m,ll k)
{
    for(int i=1;i<=n;i++)
        tmp[i]=now[i]-m,add[i]=0;
    ll sum=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(i>2*r+1)sum-=add[i-(2*r+1)];
        if(tmp[i]+sum<0)
        {
            add[i]=-(tmp[i]+sum);
            cnt+=add[i];
            sum+=add[i];
        }
        if(cnt>k)return 0;
    }
    return 1;
}
int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    ll k;
    scanf("%lld",&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    {
        now[max(i-r,1)]+=a[i];
        now[min(i+r,n)+1]-=a[i];
    }
    for(int i=1;i<=n;i++)
        now[i]+=now[i-1];
    ll ql=0,qr=(1LL<<61)-1;
    while(ql<qr)
    {
        ll qm=(ql+qr+1)/2;
        if(check(n,r,qm,k))ql=qm;
        else qr=qm-1;
    }
    printf("%lld\n",ql);
    return 0;
}