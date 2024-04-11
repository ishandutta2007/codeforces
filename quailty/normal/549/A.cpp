#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[55][55];
int cnt[26];
int judge(int m,int n)
{
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<=1;i++)
    {
        for(int j=0;j<=1;j++)
        {
            cnt[s[m+i][n+j]-'a']++;
        }
    }
    if(cnt['f'-'a'] && cnt['a'-'a'] && cnt['c'-'a'] && cnt['e'-'a'])
    {
        return 1;
    }
    return 0;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            ans+=judge(i,j);
        }
    }
    printf("%d\n",ans);
    return 0;
}