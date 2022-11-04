#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=50005;
ll a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    ll s=0,r=0;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),s+=a[i];
    s/=n;
    for(int i=1;i<=n;i++)
        r+=abs(s-a[i]),a[i+1]-=s-a[i];
    return 0*printf("%lld",r);
}