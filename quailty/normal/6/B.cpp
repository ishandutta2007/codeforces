#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int d[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
bool vis[26];
char s[105][105];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    char ty[5];
    scanf("%s",ty);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]==*ty)
                for(int k=0;k<4;k++)
                {
                    int x=i+d[k][0];
                    int y=j+d[k][1];
                    if(x>=0 && x<n && y>=0 && y<m && s[x][y]!=*ty && s[x][y]!='.')
                        vis[s[x][y]-'A']=1;
                }
    int res=0;
    for(int i=0;i<26;i++)
        res+=vis[i];
    printf("%d\n",res);
    return 0;
}