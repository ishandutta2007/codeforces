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
    int n;
    scanf("%d",&n);
    ll res1=12,res2=9;
    for(int i=1;i<=n-3;i++)
    {
        res1*=4;
        res2*=4;
    }
    printf("%I64d\n",res1*2+res2*(n-3));
    return 0;
}