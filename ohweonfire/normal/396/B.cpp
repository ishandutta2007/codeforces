#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int t,n;
ll m,nn,d,q,p;
bool prime(ll x)
{
     for(int i=2;i<=sqrt(x);i++)
             if(x%i==0)return false;
     return true;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d",&n);
              nn=n;
              for(m=n;!prime(m);m--);
              for(n++;!prime(n);n++);
              p=n*m+2LL*(nn-n-m+1LL);
              q=2LL*n*m;
              d=__gcd(p,q);
              p/=d;
              q/=d;
              printf("%I64d/%I64d\n",p,q);
    }
    return 0;
}