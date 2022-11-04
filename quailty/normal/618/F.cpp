#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1000005;
ll a[MAXN],b[MAXN];
#define ft first
#define sd second
pair<int,int>vis[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&b[i]);
        b[i]+=b[i-1];
    }
    bool flag=0;
    if(a[n]>b[n])
    {
        for(int i=1;i<=n;i++)
            swap(a[i],b[i]);
        flag=1;
    }
    for(int i=1,j=0;i<=n;i++)
    {
        while(b[j]<a[i])j++;
        if(a[i]==b[j] || vis[b[j]-a[i]].ft)
        {
            if(!flag)
            {
                printf("%d\n",i-vis[b[j]-a[i]].ft);
                for(int k=vis[b[j]-a[i]].ft+1;k<=i;k++)
                    printf("%d ",k);
                printf("\n");
            }
            printf("%d\n",j-vis[b[j]-a[i]].sd);
            for(int k=vis[b[j]-a[i]].sd+1;k<=j;k++)
                printf("%d ",k);
            printf("\n");
            if(flag)
            {
                printf("%d\n",i-vis[b[j]-a[i]].ft);
                for(int k=vis[b[j]-a[i]].ft+1;k<=i;k++)
                    printf("%d ",k);
                printf("\n");
            }
            return 0;
        }
        else vis[b[j]-a[i]]=make_pair(i,j);
    }
    return 0;
}