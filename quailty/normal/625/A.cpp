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
    ll n,a,b,c;
    scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c);
    ll res=0;
    if(n>=b && b-c<=a)
    {
        res+=(n-b)/(b-c)+1;
        n-=res*(b-c);
    }
    res+=n/a;
    printf("%I64d",res);
    return 0;
}