#include<bits/stdc++.h>
using namespace std;
int a[100005];
int pmi[100005],pmx[100005];
int smi[100005],smx[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    pmi[0]=smi[n+1]=100001;
    for(int i=1;i<=n;i++)
    {
        pmi[i]=min(pmi[i-1],a[i]);
        pmx[i]=max(pmx[i-1],a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        smi[i]=min(smi[i+1],a[i]);
        smx[i]=max(smx[i+1],a[i]);
    }
    int res=100001;
    for(int i=1;i<=n;i++)
        res=min(res,max(pmx[i-1],smx[i+1])-min(pmi[i-1],smi[i+1]));
    printf("%d\n",res);
    return 0;
}