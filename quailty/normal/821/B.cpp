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
    int m,b;
    scanf("%d%d",&m,&b);
    ll res=0;
    for(int y=0;y<=b;y++)
    {
        int x=(b-y)*m;
        ll tmp=1LL*x*(x+1)/2*(y+1)+1LL*y*(y+1)/2*(x+1);
        res=max(res,tmp);
    }
    printf("%lld\n",res);
    return 0;
}