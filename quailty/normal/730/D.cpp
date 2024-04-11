#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll l[MAXN],t[MAXN];
vector<ll>res;
int main()
{
    int n;
    ll r,s=0,c=0,d=0;
    scanf("%d%I64d",&n,&r);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&l[i]);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&t[i]);
    for(int i=1;i<=n;i++)
    {
        if(t[i]<l[i])return 0*printf("-1");
        if(c>l[i])
        {
            c-=l[i];
            d+=l[i];
            continue;
        }
        l[i]-=c,t[i]-=c,d+=c;
        if(2*l[i]>t[i])
        {
            ll k=t[i]-l[i];
            d+=2*k;
            ll g=(l[i]-k+r-1)/r;
            c=g*r-(l[i]-k);
            if((s+=g)<=100000)for(int i=0;i<g;i++)
                res.push_back(d+i*r);
            else res.clear();
            d+=l[i]-k;
        }
        else d+=2*l[i],c=0;
    }
    printf("%I64d\n",s);
    if(s<=100000)for(int i=0;i<(int)res.size();i++)
        printf("%I64d ",res[i]);
    return 0;
}