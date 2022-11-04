#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105][105],res[105];
int len[105],usd[105],ok[105];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
        len[i]=strlen(s[i]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&ok[i]);
        ok[i]--;
        usd[ok[i]]=1;
    }
    for(int i=0;i<m;i++)
        if(len[ok[i]]!=len[ok[0]])return 0*printf("No");
    for(int i=0;i<len[ok[0]];i++)
        res[i]=s[ok[0]][i];
    for(int i=0;i<m;i++)
        for(int j=0;j<len[ok[i]];j++)
            if(res[j]!='?' && s[ok[i]][j]!=res[j])res[j]='?';
    for(int i=0;i<n;i++)if(!usd[i])
    {
        if(len[i]!=len[ok[0]])continue;
        bool isok=1;
        for(int j=0;j<len[i];j++)
            if(res[j]!='?' && s[i][j]!=res[j])isok=0;
        if(isok)return 0*printf("No");
    }
    return 0*printf("Yes\n%s",res);
}