#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        printf("%lld\n",(1LL*a+2LL*b+3LL*c)%2);
    }
    return 0;
}