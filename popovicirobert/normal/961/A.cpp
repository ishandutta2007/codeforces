#include <cstdio>
#include <algorithm>
using namespace std;
int f[1001];
int main()
{
    int n,m,i,x,rez;
    scanf("%d%d",&n,&m);
    for(i=1; i<=m; i++)
    {
        scanf("%d",&x);
        f[x]++;
    }
    rez=m+1;
    for(i=1; i<=n; i++)
        rez=min(rez,f[i]);
    printf("%d",rez);

    return 0;
}