#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
char str[MAXN];
bool vis[MAXN][MAXN];
vector<pair<int,int> > can[26],now;
void dfs(int x,int s)
{
    if(vis[x][s])return;
    vis[x][s]=1;
    if(str[x+1+s])
        can[str[x+1]-'a'].push_back({x+1,s});
    for(int i=0;s>>i;i++)
        if(s>>i&1)dfs(x+(1<<i),s-(1<<i));
}
int main()
{
    scanf("%s",str+1);
    int n=strlen(str+1),k=1;
    while((k<<1)<=n)k<<=1;
    now.push_back({0,k-1});
    while(1)
    {
        for(int i=0;i<(int)now.size();i++)
            dfs(now[i].first,now[i].second);
        int c=-1;
        for(int i=25;i>=0;i--)
            if(can[i].size())c=i;
        if(c<0)break;
        printf("%c",c+'a');
        now.swap(can[c]);
        for(int i=0;i<26;i++)
            can[i].clear();
    }
    return 0;
}