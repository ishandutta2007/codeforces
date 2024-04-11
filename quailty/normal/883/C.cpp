#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=(1LL<<60)-1;
int main()
{
    ll f,T,t0;
    scanf("%lld%lld%lld",&f,&T,&t0);
    ll a[3],t[3],p[3];
    for(int i=1;i<=2;i++)
        scanf("%lld%lld%lld",&a[i],&t[i],&p[i]);
    ll res=INF;
    for(ll b1=0;b1<=10000000;b1++)
    {
        ll gap=(f*t0-T)-b1*(t0-t[1]);
        ll b2=((t0>t[2] && gap>0) ? (gap+(t0-t[2])-1)/(t0-t[2]) : 0);
        if(b1+b2<=f && b1*(t0-t[1])+b2*(t0-t[2])>=f*t0-T)
            res=min(res,(b1+a[1]-1)/a[1]*p[1]+(b2+a[2]-1)/a[2]*p[2]);
    }
    printf("%lld\n",(res<INF ? res : -1));
    return 0;
}