#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll d[200005];
int main()
{
    int n;
    ll A;
    scanf("%d%I64d",&n,&A);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&d[i]);
        sum+=d[i];
    }
    ll mini,maxi;
    for(int i=1;i<=n;i++)
    {
        mini=A-(sum-d[i]);
        if(mini<1)mini=1;
        maxi=A-(n-1);
        if(maxi>d[i])maxi=d[i];
        printf("%I64d ",d[i]-(maxi-mini+1));
    }
    return 0;
}