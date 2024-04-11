#include<bits/stdc++.h>
using namespace std;
const int MAXN=2505;
const int MAXL=5005;
string str[MAXN];
char buf[MAXL];
int dis[MAXN];
int main()
{
    int k,n;
    scanf("%d%d",&k,&n);
    for(int i=1;i<=k;i++)
    {
        scanf("%s",buf);
        str[i]=buf;
    }
    int cnt[26]={0},isok=1,same=0;
    for(int i=1;i<=k;i++)
    {
        if(i==1)
        {
            for(int j=0;j<n;j++)
                cnt[str[i][j]-'a']++;
            for(int j=0;j<26;j++)
                same|=(cnt[j]>1);
        }
        else
        {
            int tmp[26]={0};
            for(int j=0;j<n;j++)
                tmp[str[i][j]-'a']++;
            for(int j=0;j<26;j++)
                isok&=(tmp[j]==cnt[j]);
        }
    }
    if(!isok)return 0*printf("-1\n");
    for(int i=1;i<=k;i++)
        for(int j=0;j<n;j++)
            dis[i]+=(str[1][j]!=str[i][j]);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            for(int t=1;t<=k;t++)
            {
                dis[t]-=(str[1][i]!=str[t][i]);
                dis[t]-=(str[1][j]!=str[t][j]);
                dis[t]+=(str[1][i]!=str[t][j]);
                dis[t]+=(str[1][j]!=str[t][i]);
            }
            bool flag=1;
            for(int t=1;t<=k;t++)
                flag&=(dis[t]==2 || (dis[t]==0 && same));
            for(int t=1;t<=k;t++)
            {
                dis[t]+=(str[1][i]!=str[t][i]);
                dis[t]+=(str[1][j]!=str[t][j]);
                dis[t]-=(str[1][i]!=str[t][j]);
                dis[t]-=(str[1][j]!=str[t][i]);
            }
            if(flag)
            {
                swap(str[1][i],str[1][j]);
                return 0*printf("%s\n",str[1].c_str());
            }
        }
    return 0*printf("-1\n");
}