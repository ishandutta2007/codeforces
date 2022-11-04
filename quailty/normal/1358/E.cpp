#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500005;
const ll INF=(1LL<<60)-1;
int a[MAXN];
ll suf[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=(n+1)/2;i++)
        scanf("%d",&a[i]);
    int x;
    scanf("%d",&x);
    for(int i=(n+1)/2+1;i<=n;i++)
        a[i]=x;
    for(int i=n;i>=1;i--)
        suf[i]=suf[i+1]+a[i];
    ll now=INF;
    for(int k=n;k>n/2;k--)
    {
        now=min(now-x,suf[n-k+1]);
        if(now>0)return 0*printf("%d\n",k);
    }
    return 0*printf("%d\n",-1);
}