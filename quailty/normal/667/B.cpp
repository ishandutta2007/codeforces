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
    ll res=0,mx=0;
    for(int i=0;i<n;i++)
    {
        ll l;
        scanf("%I64d",&l);
        res+=l;
        mx=max(mx,l);
    }
    printf("%I64d\n",2*mx-res+1);
    return 0;
}