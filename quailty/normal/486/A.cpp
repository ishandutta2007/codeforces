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
    ll n;
    scanf("%I64d",&n);
    if(n%2==0)printf("%I64d\n",n/2);
    else printf("%I64d\n",n/2-n);
    return 0;
}