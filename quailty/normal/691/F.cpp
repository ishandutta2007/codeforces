#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=1000005;
const ll MAXP=3000005;
ll a[MAXN],b[MAXN],c[MAXN],res[MAXP];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(int i=1;i<=n;i++)
        b[i]=a[i];
    sort(b+1,b+n+1);
    int tot=unique(b+1,b+n+1)-(b+1);
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
    for(int i=1;i<=n;i++)
        c[a[i]]++;
    ll all=1LL*n*(n-1);
    n=tot;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            if(b[i]*b[j]<MAXP)res[b[i]*b[j]]+=(1+(i!=j))*c[i]*(c[j]-(i==j));
            else break;
        }
    for(int i=1;i<MAXP;i++)res[i]+=res[i-1];
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        ll p;
        scanf("%I64d",&p);
        printf("%I64d\n",all-res[p-1]);
    }
    return 0;
}