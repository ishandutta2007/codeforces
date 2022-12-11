#include<bits/stdc++.h>
#define PII pair<int,int>
#define mp make_pair
#define lb lower_bound
#define up upper_bound
#define mod 1000000007
#define N 200010
#define M 2000010
using namespace std;
int a1,a2,a3,a4,a5,a6;
long long powmod(long long x,long long y)
{
    long long ans=1;
    for(;y;y>>=1,x=x*x%mod)
        if(y&1)ans=ans*x%mod;
    return ans;
}
int main()
{
    scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6);
    a1+=a2+a6;printf("%d\n",a1*a1-a2*a2-a4*a4-a6*a6);
}