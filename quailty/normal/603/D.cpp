#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y)
{
    return y==0 ? x : gcd(y,x%y);
}
const int MAXN=2005;
ll a[MAXN],b[MAXN],c[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    int zr=0;
    for(int i=0;i<n;i++)
    {
        scanf("%I64d%I64d%I64d",&a[i],&b[i],&c[i]);
        if(c[i]==0)zr++;
    }
    int res=(zr==2 ? n-2 : 0);
    vector<pair<ll,ll> >v;
    for(int i=0;i<n;i++)
    {
        if(c[i]==0)continue;
        v.clear();
        ll px=a[i]*a[i]+b[i]*b[i];
        ll qx=a[i]*c[i];
        ll py=a[i]*a[i]+b[i]*b[i];
        ll qy=b[i]*c[i];
        for(int j=0;j<i;j++)
        {
            if(c[j]==0)continue;
            ll px2=a[j]*a[j]+b[j]*b[j];
            ll qx2=a[j]*c[j];
            ll py2=a[j]*a[j]+b[j]*b[j];
            ll qy2=b[j]*c[j];
            ll sx=qx*px2-px*qx2;
            ll sy=qy*py2-py*qy2;
            ll g=gcd(abs(sx),abs(sy));
            sx/=g;
            sy/=g;
            if(sx<0 || (sx==0 && sy<0))
            {
                sx=-sx;
                sy=-sy;
            }
            v.push_back(make_pair(sx,sy));
        }
        sort(v.begin(),v.end());
        int tn=(int)v.size();
        int la=0;
        for(int i=0;i<tn;i++)
            if(v[i]!=v[la])
            {
                res+=(i-la)*(i-la-1)/2;
                la=i;
            }
        res+=(tn-la)*(tn-la-1)/2;
    }
    printf("%d\n",res);
    return 0;
}