#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int f[MAXN],b[MAXN];
int cnt[MAXN],la[MAXN];
int tot[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&f[i]);
        cnt[f[i]]++;
        la[f[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        tot[b[i]]++;
    }
    bool flag=0;
    for(int i=1;i<=n;i++)
        if(tot[i]>0 && cnt[i]==0)
            flag=1;
    if(flag)printf("Impossible\n");
    else
    {
        flag=0;
        for(int i=1;i<=n;i++)
            if(tot[i]>0 && cnt[i]>1)
                flag=1;
        if(flag)printf("Ambiguity\n");
        else
        {
            printf("Possible\n");
            for(int i=1;i<=m;i++)
                printf("%d ",la[b[i]]);
        }
    }
    return 0;
}