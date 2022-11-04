#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        b++;
        int len=-1;
        while(b)b/=10,len++;
        printf("%lld\n",1LL*a*len);
    }
    return 0;
}