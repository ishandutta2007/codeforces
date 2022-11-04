#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll c[3];
    for(int i=0;i<3;i++)
        scanf("%I64d",&c[i]);
    ll t=max({c[0],c[1],c[2]}),res=0;
    for(int i=0;i<3;i++)
        res+=max(0LL,t-c[i]-1);
    return 0*printf("%I64d",res);
}