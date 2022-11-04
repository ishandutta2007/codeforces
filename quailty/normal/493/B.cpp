#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll a[MAXN],b[MAXN];
int main()
{
    int n,la=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        ll x;
        scanf("%I64d",&x);
        if(x>0)a[++a[0]]=x,la=0;
        else b[++b[0]]=-x,la=1;
    }
    a[a[0]+1]=b[b[0]+1]=-1;
    ll sum[2]={0,0};
    for(int i=1;i<=a[0];i++)
        sum[0]+=a[i];
    for(int i=1;i<=b[0];i++)
        sum[1]+=b[i];
    if(sum[0]>sum[1])printf("first");
    else if(sum[0]<sum[1])printf("second");
    else
    {
        for(int i=1;i<=min(a[0],b[0])+1;i++)
        {
            if(a[i]>b[i])return 0*printf("first");
            if(a[i]<b[i])return 0*printf("second");
        }
        printf("%s",(la ? "second" : "first"));
    }
    return 0;
}