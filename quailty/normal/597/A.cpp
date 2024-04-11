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
    ll k,a,b;
    scanf("%I64d%I64d%I64d",&k,&a,&b);
    ll ta=k*(a/k),tb=k*(b/k);
    while(ta<a)ta+=k;
    while(tb<=b)tb+=k;
    printf("%I64d\n",(tb-ta)/k);
    return 0;
}