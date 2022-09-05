#include<bits/stdc++.h>
using namespace std;

const int B=9;
int n,a[262147],q,x,y;
long long lmax[520][520],rmax[520][520],sum[520][520],ans[520][520],Ans[262147];

int main()
{
    scanf("%d",&n);
    for (int i=0; i<(1<<n); i++) scanf("%d",&a[i]);
    int num=(1<<max(0,n-B));
    for (int i=0; i<num; i++)
    {
        int l=i<<B,r=min((i+1)<<B,1<<n);
        for (int j=0; j<(1<<n)&&j<(1<<B); j++)
        {
            long long nw=0;
            lmax[i][j]=rmax[i][j]=0;
            for (int k=l; k<r; k++) nw+=a[k^j],lmax[i][j]=max(lmax[i][j],nw);
            sum[i][j]=nw,nw=0;
            for (int k=r-1; k>=l; k--) nw+=a[k^j],rmax[i][j]=max(rmax[i][j],nw);
            nw=0;
            for (int k=l; k<r; k++) nw=max(nw+a[k^j],0ll),ans[i][j]=max(ans[i][j],nw);
        }
    }
    for (int i=0; i<(1<<n); i++)
    {
        Ans[i]=0;
        long long nw=0;
        int up=(i>>B),down=(i&((1<<B)-1));
        for (int j=0; j<num; j++)
        {
            Ans[i]=max(Ans[i],ans[j^up][down]);
            Ans[i]=max(Ans[i],nw+lmax[j^up][down]);
            nw=max(nw+sum[j^up][down],rmax[j^up][down]);
        }
    }
    x=0,scanf("%d",&q);
    while (q--) scanf("%d",&y),x^=(1<<y),printf("%lld\n",Ans[x]);
    return 0;
}