#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b,x,y,z;
    scanf("%lld%lld%lld%lld%lld",&a,&b,&x,&y,&z);
    a-=2*x+y,b-=y+3*z;
    printf("%lld\n",max(-a,0LL)+max(-b,0LL));
    return 0;
}