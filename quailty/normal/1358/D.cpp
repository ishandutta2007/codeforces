#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=400005;
ll d[MAXN],s[MAXN],sd[MAXN],ss[MAXN];
int main()
{
    int n;
    ll x;
    scanf("%d%lld",&n,&x);
    for(int i=1;i<=n;i++)
        scanf("%lld",&d[i]);
    for(int i=1;i<=n;i++)
        d[i+n]=d[i];
    for(int i=1;i<=2*n;i++)
    {
        s[i]=d[i]*(d[i]+1)/2;
        sd[i]=sd[i-1]+d[i];
        ss[i]=ss[i-1]+s[i];
    }
    ll res=0;
    for(int l=1,r=n+1;r<=2*n;r++)
    {
        while(sd[r]-sd[l]>x)l++;
        ll lef=x-(sd[r]-sd[l]);
        ll add=s[l]-(d[l]-lef)*(d[l]-lef+1)/2;
        res=max(res,ss[r]-ss[l]+add);
    }
    return 0*printf("%lld\n",res);
}