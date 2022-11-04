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
    printf("%d",(n%2 ? 1 : 2));
    return 0;
}