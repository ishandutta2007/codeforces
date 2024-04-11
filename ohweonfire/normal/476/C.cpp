#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const LL mod=1000000007;
LL sum;
int a,b;
int main()
{
    scanf("%d%d",&a,&b);
    for(int y=1;y<b;y++)
    {
        LL calc=(a*1ll*(a+1)/2)%mod;
        calc=((calc*b)%mod)*y%mod;
        calc+=(a*1ll*y)%mod;
        sum=(sum+calc)%mod;
    }
    printf("%I64d\n",sum);
    return 0;
}