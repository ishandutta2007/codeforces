#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=300005;
const int ALPHA=26;
struct node
{
    int go[ALPHA],sz;
}s[MAXN<<1];
void maintain(int u)
{
    s[u].sz=1;
    for(int i=0;i<ALPHA;i++)
        s[u].sz+=s[s[u].go[i]].sz;
}
int tot;
int newnode(int u=0)
{
    int v=++tot;
    for(int i=0;i<ALPHA;i++)
        s[v].go[i]=s[u].go[i];
    maintain(v);
    return v;
}
int merge(int u,int v)
{
    if(!u)return v;
    if(!v)return u;
    int t=newnode();
    for(int i=0;i<ALPHA;i++)
        s[t].go[i]=merge(s[u].go[i],s[v].go[i]);
    maintain(t);
    return t;
}
vector<int>dep[MAXN];
void dfs(int u,int d)
{
    if(!u)return;
    dep[d].push_back(u);
    for(int i=0;i<ALPHA;i++)
        dfs(s[u].go[i],d+1);
    maintain(u);
}
void solve(int n)
{
    int r=n+1,p=0,up=0;
    for(int _=1;!dep[_].empty();_++)
    {
        int sum=0;
        for(int i=0;i<(int)dep[_].size();i++)
        {
            tot=n;
            int tmp=newnode();
            for(int j=0;j<ALPHA;j++)
                tmp=merge(tmp,s[dep[_][i]].go[j]);
            sum+=s[tmp].sz;
        }
        if(r>sum+up)r=sum+up,p=_;
        up+=(int)dep[_].size();
    }
    printf("%d\n%d\n",r,p);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        char c[5];
        scanf("%d%d%s",&u,&v,c);
        s[u].go[*c-'a']=v;
    }
    dfs(1,1);
    solve(n);
    return 0;
}