#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
int h[MAXN];
int main()
{
    int n,A,R,M;
    scanf("%d%d%d%d",&n,&A,&R,&M);
    M=min(M,A+R);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    auto f=[&](int t)->ll
    {
        ll cnt_a=0,cnt_r=0;
        for(int i=1;i<=n;i++)
        {
            if(h[i]<t)cnt_a+=t-h[i];
            else cnt_r+=h[i]-t;
        }
        ll cnt_m=min(cnt_a,cnt_r);
        cnt_a-=cnt_m,cnt_r-=cnt_m;
        return A*cnt_a+R*cnt_r+M*cnt_m;
    };
    int tl=0,tr=1000000000;
    while(tl<tr)
    {
        int tm1=tl+(tr-tl)/3;
        int tm2=tl+(2*tr-2*tl+2)/3;
        if(f(tm1)>f(tm2))tl=tm1+1;
        else tr=tm2-1;
    }
    return 0*printf("%lld\n",f(tl));
}