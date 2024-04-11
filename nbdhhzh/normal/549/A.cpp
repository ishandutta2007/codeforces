#include<cstdio>
using namespace std;
int n,m,f[256],t,i,j,ans;
char s[110][110];
int main()
{
    scanf("%d%d",&n,&m);
    f['f']=1;f['a']=2;
    f['c']=4;f['e']=8;
    for(i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(i=1;i<n;i++)
        for(j=1;j<m;j++)
        {
            t=f[s[i][j]];
            t|=f[s[i+1][j]];
            t|=f[s[i][j+1]];
            t|=f[s[i+1][j+1]];
            ans+=(t==15);
        }
    printf("%d\n",ans);
}