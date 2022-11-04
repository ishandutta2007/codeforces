#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105];
bool vis[35];
int main()
{
    int k;
    scanf("%d%s",&k,s);
    int len=strlen(s);
    int cnt=0;
    for(int i=0;i<len;i++)
    {
        if(!vis[s[i]-'a'])
        {
            vis[s[i]-'a']=1;
            cnt++;
        }
    }
    if(cnt>=k)
    {
        printf("YES");
        memset(vis,0,sizeof(vis));
        cnt=0;
        for(int i=0;i<len;i++)
        {
            if(!vis[s[i]-'a'] && cnt<k)
            {
                printf("\n");
                vis[s[i]-'a']=1;
                cnt++;
            }
            printf("%c",s[i]);
        }
    }
    else printf("NO\n");
}