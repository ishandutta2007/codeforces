#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=105;
char s[MAXN][MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",&s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]!=s[i][0])
                return 0*printf("NO");
    for(int j=0;j<m;j++)
        for(int i=1;i<n;i++)
            if(s[i][j]==s[i-1][j])
                return 0*printf("NO");
    return 0*printf("YES");
}