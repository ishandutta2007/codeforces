#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=500005;
ll a[MAXN],pre[MAXN],rig[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    if(pre[n]%3)return 0*printf("0");
    for(int i=n;i>=1;i--)
    {
        rig[i]=rig[i+1];
        if(pre[n]-pre[i-1]==pre[n]/3)
            rig[i]++;
    }
    ll res=0;
    for(int i=1;i<n-1;i++)
        if(pre[i]==pre[n]/3)
            res+=rig[i+2];
    return 0*printf("%I64d",res);
}