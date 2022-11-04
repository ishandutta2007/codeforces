#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef double db;
ll a[200005];
int main()
{
    int n;
    ll w;
    scanf("%d%I64d",&n,&w);
    for(int i=1;i<=2*n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    sort(a+1,a+2*n+1,greater<ll>());
    db b=a[n],g=a[2*n];
    db ans=min(b/2.0,g);
    ans=min(ans,(w+0.0)/(3*n));
    printf("%.10f\n",ans*3*n);
    return 0;
}