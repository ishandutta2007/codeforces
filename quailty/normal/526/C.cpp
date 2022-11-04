#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll C,Hr,Hb,Wr,Wb;
ll f(ll y)
{
    return ((C-y*Wb)/Wr)*Hr+y*Hb;
}
int main()
{
    scanf("%I64d%I64d%I64d%I64d%I64d",&C,&Hr,&Hb,&Wr,&Wb);
    if(Wr>Wb)
    {
        swap(Wr,Wb);
        swap(Hr,Hb);
    }
    ll ans=0;
    for(int i=0;i<=min(C/Wb,1000000LL);i++)
    {
        ans=max(ans,f(i));
    }
    for(int i=C/Wb;i>=max(0LL,C/Wb-1000000LL);i--)
    {
        ans=max(ans,f(i));
    }
    printf("%I64d\n",ans);
    return 0;
}