#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105][105];
int c[105][105];
void work(int x,int y,int k)
{
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            c[i][j]+=k;
        }
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    if(s[n-1][m-1]=='W')work(n-1,m-1,1);
    else work(n-1,m-1,-1);
    int cnt=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(s[i][j]=='W')
            {
                if(c[i][j]!=1)
                {
                    work(i,j,1-c[i][j]);
                    cnt++;
                }
            }
            else
            {
                if(c[i][j]!=-1)
                {
                    work(i,j,-1-c[i][j]);
                    cnt++;
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}