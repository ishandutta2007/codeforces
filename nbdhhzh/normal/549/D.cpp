#include<cstdio>
using namespace std;
int n,m,f[110][110],i,j,ans,t,k,l;
char s[110][110];
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
        for(j=1;j<=m;j++)
            s[i][j]=='W'?s[i][j]=1:s[i][j]=-1;
    }
    for(i=n;i>=1;i--)
        for(j=m;j>=1;j--)
            if(s[i][j]!=f[i][j])
            {
                ans++;
                t=s[i][j]-f[i][j];
                for(k=i;k>=1;k--)
                    for(l=j;l>=1;l--)
                        f[k][l]+=t;
            }
    printf("%d",ans);
}