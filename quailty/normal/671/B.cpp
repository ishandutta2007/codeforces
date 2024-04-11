#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int c[500005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    sort(c+1,c+n+1);
    int l=1,r=n,t[2]={k,k};
    while(t[0] && l<n)
    {
        if(t[0]>=1LL*l*(c[l+1]-c[l]))t[0]-=1LL*l*(c[l+1]-c[l]),l++;
        else break;
    }
    while(t[1] && r>1)
    {
        if(t[1]>=1LL*(n+1-r)*(c[r]-c[r-1]))t[1]-=1LL*(n+1-r)*(c[r]-c[r-1]),r--;
        else break;
    }
    int nw[2]={c[l]+t[0]/l,c[r]-t[1]/(n-r+1)};
    if(nw[1]<=nw[0])
    {
        ll sum=0;
        for(int i=1;i<=n;i++)sum+=c[i];
        printf("%d\n",sum%n!=0);
    }
    else printf("%d\n",nw[1]-nw[0]);
    return 0;
}