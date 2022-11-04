#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
char str[MAXN][MAXN];
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++)
        scanf("%s",str[i]);
    int tot=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            tot+=(str[i][j]=='*');
    int emp=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)if(j*n+i<tot)
            emp+=(str[i][j]=='.');
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--,y--;
        if(str[x][y]=='*')
        {
            emp+=(y*n+x<tot);
            str[x][y]='.';
            tot--;
            emp-=(str[tot%n][tot/n]=='.');
        }
        else
        {
            emp+=(str[tot%n][tot/n]=='.');
            tot++;
            str[x][y]='*';
            emp-=(y*n+x<tot);
        }
        printf("%d\n",emp);
    }
    return 0;
}