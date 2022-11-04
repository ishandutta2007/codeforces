#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        ll l,r;
        scanf("%I64d%I64d",&l,&r);
        int loc=0;
        while((l|1LL<<loc)<=r)l|=(1LL<<loc++);
        printf("%I64d\n",l);
    }
    return 0;
}