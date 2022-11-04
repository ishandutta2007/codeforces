#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll ans=0;
void solve(ll a,ll b)
{
    if(a==0 || b==0)return;
    if(a<b)swap(a,b);
    ans+=a/b;
    a-=(a/b)*b;
    solve(a,b);
}
int main()
{
    ll a,b;
    scanf("%I64d%I64d",&a,&b);
    solve(a,b);
    printf("%I64d",ans);
    return 0;
}