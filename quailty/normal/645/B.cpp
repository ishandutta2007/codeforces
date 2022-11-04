#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    ll res=0,now=2;
    while(k-- && now<=n)
    {
        res+=2*(n-now)+1;
        now+=2;
    }
    printf("%I64d\n",res);
    return 0;
}