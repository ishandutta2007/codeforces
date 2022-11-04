#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[505][505];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int u=n-1,d=0,l=m-1,r=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
        for(int j=0;j<m;j++)if(s[i][j]=='X')
        {
            u=min(u,i),d=max(d,i);
            l=min(l,j),r=max(r,j);
        }
    }
    bool isok=1;
    for(int i=u;i<=d;i++)
        for(int j=l;j<=r;j++)
            isok&=(s[i][j]=='X');
    printf("%s\n",(isok ? "YES" : "NO"));
    return 0;
}