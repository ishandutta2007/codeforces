#include<cstdio>
#define mod 1000000007
using namespace std;
int n,k,i;
long long ans;
int main()
{
    scanf("%d%d",&n,&k);ans=1;
    for(i=1;i<k;i++)ans=ans*k%mod;
    for(i=k+1;i<=n;i++)ans=ans*(n-k)%mod;
    printf("%I64d\n",ans);
}