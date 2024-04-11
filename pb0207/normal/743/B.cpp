#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;
 
LL pow(LL x,LL n)
{
    LL res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = res*x;
        }
        x *= x;
        n >>= 1;
    }
    return res;
}
 
int main()
{
    LL n,k;
    scanf("%I64d%I64d",&n,&k);
    for (int i = 0;;i++)
    {
        LL tmp = pow(2,i);
        if ((k - tmp) % (tmp*2) == 0)
        {
            printf("%d\n",i+1);
            break;
        }  
    }
    return 0;
}