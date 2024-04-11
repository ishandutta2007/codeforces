#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;
char m[55][55];
char re[55][55];
int tot;
struct node
{
    int x,y;
}c[2505];
bool isok[105][105];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",m[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(m[i][j]=='o')
            {
                c[++tot].x=i;
                c[tot].y=j;
            }
        }
    }
    for(int i=-n+1;i<n;i++)
    {
        for(int j=-n+1;j<n;j++)
        {
            bool flag=1;
            for(int k=1;k<=tot;k++)
            {
                int tx=c[k].x+i;
                int ty=c[k].y+j;
                if(tx>=0 && tx<n && ty>=0 && ty<n
                   && m[tx][ty]=='.')
                {
                    flag=0;
                }
            }
            if(flag)
            {
                isok[i+n-1][j+n-1]=1;
            }
        }
    }
    for(int i=-n+1;i<n;i++)
    {
        for(int j=-n+1;j<n;j++)
        {
            bool flag=1;
            for(int k=1;k<=tot;k++)
            {
                int tx=c[k].x+i;
                int ty=c[k].y+j;
                if(tx>=0 && tx<n && ty>=0 && ty<n
                   && m[tx][ty]=='.')
                {
                    flag=0;
                }
            }
            if(flag)
            {
                isok[i+n-1][j+n-1]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            re[i][j]='.';
        }
    }
    for(int i=1;i<=tot;i++)
    {
        re[c[i].x][c[i].y]='o';
    }
    for(int i=-n+1;i<n;i++)
    {
        for(int j=-n+1;j<n;j++)
        {
            if(isok[i+n-1][j+n-1])
            {
                for(int k=1;k<=tot;k++)
                {
                    int tx=c[k].x+i;
                    int ty=c[k].y+j;
                    if(tx>=0 && tx<n && ty>=0 && ty<n
                       && re[tx][ty]=='.')
                    {
                        re[tx][ty]='x';
                    }
                }
            }
        }
    }
    bool done=1;
    for(int i=0;i<n;i++)
    {
        if(strcmp(m[i],re[i]))done=0;
    }
    if(done)
    {
        printf("YES\n");
        for(int i=0;i<2*n-1;i++)
        {
            for(int j=0;j<2*n-1;j++)
            {
                if(i==n-1 && j==n-1)
                {
                    printf("o");
                }
                else
                {
                    if(isok[i][j])printf("x");
                    else printf(".");
                }
            }
            printf("\n");
        }
    }
    else printf("NO");
    return 0;
}