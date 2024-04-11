#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int l[55],r[55];
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
    }
    int loc=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        while(loc+x<=l[i])loc+=x;
        ans+=r[i]-loc+1;
        loc=r[i]+1;
    }
    printf("%d\n",ans);
    return 0;
}