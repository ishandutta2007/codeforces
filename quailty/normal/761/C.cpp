#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int inf=100000;
char s[55][55];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]);
    int res=inf;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(j==i)continue;
            for(int k=1;k<=n;k++)
            {
                if(k==i || k==j)continue;
                int now=0,tmp=inf;
                for(int t=0;t<m;t++)
                    if(s[i][t]>='0' && s[i][t]<='9')
                        tmp=min({tmp,t,m-t});
                now+=tmp;
                tmp=inf;
                for(int t=0;t<m;t++)
                    if(s[j][t]>='a' && s[j][t]<='z')
                        tmp=min({tmp,t,m-t});
                now+=tmp;
                tmp=inf;
                for(int t=0;t<m;t++)
                    if(s[k][t]=='#' || s[k][t]=='*' || s[k][t]=='&')
                        tmp=min({tmp,t,m-t});
                now+=tmp;
                res=min(res,now);
            }
        }
    return 0*printf("%d",(res<inf ? res : -1));
}