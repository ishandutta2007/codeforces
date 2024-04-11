#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int sgn(ll x)
{
    if(x>0)return 1;
    if(x<0)return -1;
    return 0;
}
int main()
{
    ll x_1,x_2,y_1,y_2;
    scanf("%I64d%I64d%I64d%I64d",&x_1,&y_1,&x_2,&y_2);
    int n;
    scanf("%d",&n);
    ll a,b,c;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        if(sgn(a*x_1+b*y_1+c)*sgn(a*x_2+b*y_2+c)<0)ans++;
    }
    printf("%d\n",ans);
    return 0;
}