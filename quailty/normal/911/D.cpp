#include<bits/stdc++.h>
using namespace std;
const int MAXN=1505;
int a[MAXN],vis[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        reverse(a+l,a+r+1);
        memset(vis,0,sizeof(vis));
        int res=n;
        for(int i=1;i<=n;i++)if(!vis[i])
        {
            res--;
            int p=i;
            do
            {
                vis[p]=1;
                p=a[p];
            }
            while(!vis[p]);
        }
        printf("%s\n",(res&1 ? "odd" : "even"));
    }
    return 0;
}