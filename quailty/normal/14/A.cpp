#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
char s[55][55];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    int u=n-1,d=0,l=m-1,r=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]=='*')
            {
                u=min(u,i);
                d=max(d,i);
                l=min(l,j);
                r=max(r,j);
            }
    for(int i=u;i<=d;i++,printf("\n"))
        for(int j=l;j<=r;j++)
            printf("%c",s[i][j]);
    return 0;
}