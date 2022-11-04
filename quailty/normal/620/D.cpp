#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2005;
ll a[MAXN],b[MAXN];
pair<ll,pair<int,int> >pa[MAXN*MAXN/2],pb[MAXN*MAXN/2];
int main()
{
    int n;
    scanf("%d",&n);
    ll suma=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        suma+=a[i];
    }
    int m;
    scanf("%d",&m);
    ll sumb=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%I64d",&b[i]);
        sumb+=b[i];
    }
    ll res=abs(suma-sumb);
    int loc=0;
    pair<int,int>sp[2];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(abs(suma-sumb-2*(a[i]-b[j]))<res)
            {
                res=abs(suma-sumb-2*(a[i]-b[j]));
                loc=1;
                sp[0]=make_pair(i,j);
            }
    int tot=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            pa[tot++]=make_pair(a[i]+a[j],make_pair(i,j));
    sort(pa,pa+tot);
    tot=0;
    for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++)
            pb[tot++]=make_pair(b[i]+b[j],make_pair(i,j));
    sort(pb,pb+tot);
    int r=0;
    for(int i=0;i<n*(n-1)/2;i++)
    {
        while(r<m*(m-1)/2 && suma-sumb-2*(pa[i].first-pb[r].first)<0)r++;
        if(r<m*(m-1)/2)
        {
            if(abs(suma-sumb-2*(pa[i].first-pb[r].first))<res)
            {
                res=abs(suma-sumb-2*(pa[i].first-pb[r].first));
                loc=2;
                sp[0]=make_pair(pa[i].second.first,pb[r].second.first);
                sp[1]=make_pair(pa[i].second.second,pb[r].second.second);
            }
        }
        if(r>0)
        {
            if(abs(suma-sumb-2*(pa[i].first-pb[r-1].first))<res)
            {
                res=abs(suma-sumb-2*(pa[i].first-pb[r-1].first));
                loc=2;
                sp[0]=make_pair(pa[i].second.first,pb[r-1].second.first);
                sp[1]=make_pair(pa[i].second.second,pb[r-1].second.second);
            }
        }
    }
    printf("%I64d\n%d\n",res,loc);
    for(int i=0;i<loc;i++)
        printf("%d %d\n",sp[i].first,sp[i].second);
    return 0;
}