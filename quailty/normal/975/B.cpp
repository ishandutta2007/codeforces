#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[14],b[14];
int main()
{
    for(int i=0;i<14;i++)
        scanf("%lld",&a[i]);
    ll res=0;
    for(int i=0;i<14;i++)
    {
        memcpy(b,a,sizeof(b));
        ll t=a[i];
        b[i]=0;
        for(int j=0;j<14;j++)
            b[j]+=t/14;
        t%=14;
        for(int j=(i+1)%14;t>0;j=(j+1)%14,t--)
            b[j]++;
        ll now=0;
        for(int j=0;j<14;j++)
            if(~b[j]&1)now+=b[j];
        res=max(res,now);
    }
    printf("%lld\n",res);
    return 0;
}