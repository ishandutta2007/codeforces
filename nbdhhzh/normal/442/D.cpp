#include<cstdio>
#include<algorithm>
using namespace std;
int i,n,fa[1000010],tot[1000010],t,s,max1[1000010],max2[1000010],ff;
int main()
{
    scanf("%d",&n);
    for(i=2;i<=n+1;i++)
    {
        scanf("%d",&fa[i]);tot[i]=1;
        for(t=i;t>1;t=s)
        {
            s=fa[t];if(tot[t]>tot[max1[s]])
                max2[s]=max1[s],max1[s]=t;else
            if(tot[t]>tot[max2[s]]&&t!=max1[s])max2[s]=t;
            ff=max(tot[max1[s]],tot[max2[s]]+1);
            if(ff>tot[s])tot[s]=ff;else break;
        }printf("%d ",tot[max1[1]]);
    }fclose(stdout);
}