#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=105;
vector<int> ans[maxn];
int n,a[maxn],c,mx,mn;
int main()
{
    scanf("%d%d",&n,&c);
    mn=105;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
    }
    if(mx-mn>c)
    {
        puts("NO");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int j;
        for(j=1;j<=a[i]-mn;j++)ans[i].push_back(j);
        for(j=1;j<=mn;j++)ans[i].push_back(1);
    }
    puts("YES");
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<ans[i].size();j++)
            printf("%d ",ans[i][j]);
        puts("");
    }
    return 0;
}