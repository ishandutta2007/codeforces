#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[26];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    sort(a,a+n,greater<ll>());
    ll res=0,mx=a[0]+1;
    for(int i=0;i<n && mx>0;i++)
    {
        res+=min(mx-1,a[i]);
        mx=min(mx-1,a[i]);
    }
    printf("%I64d\n",res);
    return 0;
}