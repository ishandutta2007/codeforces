#include<bits/stdc++.h>
using namespace std;
char str[55][55];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,r,c;
        scanf("%d%d%d%d",&n,&m,&r,&c);
        for(int i=1;i<=n;i++)
            scanf("%s",str[i]+1);
        if(str[r][c]=='B')
        {
            printf("0\n");
            continue;
        }
        bool isok=0,has=0;
        for(int i=1;i<=n;i++)
            isok|=(str[i][c]=='B');
        for(int j=1;j<=m;j++)
            isok|=(str[r][j]=='B');
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                has|=(str[i][j]=='B');
        if(isok)printf("1\n");
        else if(has)printf("2\n");
        else printf("-1\n");
    }
    return 0;
}