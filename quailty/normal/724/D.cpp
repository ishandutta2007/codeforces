#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=100005;
char s[MAXN];
int vis[MAXN],cnt[26];
int check(int n,int m)
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<n;j++)
            if(s[j]=='a'+i)vis[j]=1;
        int now=0,mx=0;
        for(int j=0;j<n;j++)
        {
            now=(vis[j] ? 0 : now+1);
            mx=max(mx,now);
        }
        if(mx<m)return i;
    }
    return 26;
}
int main()
{
    int m;
    scanf("%d%s",&m,s);
    int n=strlen(s);
    int cur=check(n,m);
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
        if(s[i]<'a'+cur)
        {
            vis[i]=1;
            cnt[s[i]-'a']++;
        }
    int la=-1,now=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a'+cur)la=i;
        now=(vis[i] ? 0 : now+1);
        if(now==m)
        {
            now=i-la;
            cnt[cur]++;
        }
    }
    for(int i=0;i<26;i++)
        for(int j=0;j<cnt[i];j++)
            printf("%c",'a'+i);
    return 0;
}