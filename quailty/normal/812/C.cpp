#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
typedef long long ll;
int a[MAXN];
ll t[MAXN];
ll cal(int n,int k)
{
    for(int i=1;i<=n;i++)
        t[i]=a[i]+1LL*i*k;
    sort(t+1,t+n+1);
    ll sum=0;
    for(int i=1;i<=k;i++)
        sum+=t[i];
    return sum;
}
int main()
{
    int n,S;
    scanf("%d%d",&n,&S);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=0,r=n;
    while(l<r)
    {
        int m=(l+r+1)/2;
        if(cal(n,m)<=S)l=m;
        else r=m-1;
    }
    return 0*printf("%d %lld",l,cal(n,l));
}