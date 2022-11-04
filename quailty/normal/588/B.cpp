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
    ll n,res=1;
    scanf("%I64d",&n);
    for(ll i=2;i*i<=n;i++)
        if(n%i==0)
        {
            res*=i;
            while(n%i==0)n/=i;
        }
    return 0*printf("%I64d",res*n);
}