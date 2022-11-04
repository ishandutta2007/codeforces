#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f;
int c[15];
int main()
{
    int n,l,r,x;
    scanf("%d%d%d%d",&n,&l,&r,&x);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&c[i]);
    }
    int ed=(1<<n)-1;
    int cnt=0;
    int tot,mini,maxi;
    for(int i=1;i<=ed;i++)
    {
        tot=0;
        mini=INF;
        maxi=0;
        for(int j=0;j<n;j++)
        {
            if((1<<j)&i)
            {
                tot+=c[j];
                mini=min(mini,c[j]);
                maxi=max(maxi,c[j]);
            }
        }
        if(maxi-mini>=x && tot>=l && tot<=r)cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}