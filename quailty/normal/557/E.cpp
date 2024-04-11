#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=5005;
int n;
char s[MAXN];
bool isok,dp[MAXN][MAXN];
deque<int>ans;
struct node
{
    int cnt,nex[2];
    void newnode()
    {
        nex[0]=nex[1]=-1;
        cnt=0;
    }
}t[MAXN*MAXN];
int root=0,tot=0,k=0;
void init()
{
    ans.clear();
    memset(dp,0,sizeof(dp));
    isok=0;
    tot=0;
    t[root].newnode();
}
void insert(int st)
{
    int p=root;
    for(int i=st;i<n;i++)
    {
        int id=s[i]-'a';
        if(t[p].nex[id]==-1)
        {
            t[++tot].newnode();
            t[p].nex[id]=tot;
        }
        p=t[p].nex[id];
        //printf("%d %d\n",p,dp[st][i]);
        if(dp[st][i])t[p].cnt++;
    }
}
void dfs(int p)
{
    //printf("%d %d\n",p,t[p].cnt);
    k-=t[p].cnt;
    if(k<=0)
    {
        for(int i=0;i<ans.size();i++)
        {
            printf("%c",ans[i]+'a');
        }
        printf("\n");
        isok=1;
        return;
    }
    for(int i=0;i<2;i++)
    {
        if(t[p].nex[i]!=-1)
        {
            ans.push_back(i);
            dfs(t[p].nex[i]);
            if(isok)return;
            ans.pop_back();
        }
    }
}
int main()
{
    init();
    scanf("%s%d",s,&k);
    n=strlen(s);
    init();
    for(int len=0;len<n;len++)
    {
        for(int i=0;i+len<n;i++)
        {
            int j=i+len;
            if(len<=3)dp[i][j]=(s[i]==s[j]);
            else dp[i][j]=(s[i]==s[j] && dp[i+2][j-2]);
        }
    }
    for(int i=0;i<n;i++)insert(i);
    dfs(root);
    return 0;
}