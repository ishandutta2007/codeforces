#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll a[MAXN];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),a[i]+=a[i-1];
    ll now=0,add=0;
    while(q--)
    {
        ll k;
        scanf("%lld",&k);
        ll nxt=upper_bound(a+1,a+n+1,a[now]+k+add)-a;
        if(nxt>n)now=0,add=0;
        else add=k-(a[nxt-1]-a[now]-add),now=nxt-1;
        printf("%lld\n",n-now);
    }
    return 0;
}