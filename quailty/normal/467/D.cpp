#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
pair<int,ll> operator + (const pair<int,ll> &a,const pair<int,ll> &b)
{
    return make_pair(a.first+b.first,a.second+b.second);
}
map<string,int>mp;
int getId(string &s)
{
    if(!mp[s])mp[s]=(int)mp.size();
    return mp[s];
}
void normalize(string &s)
{
    for(int i=0;i<(int)s.size();i++)
        if(s[i]>='a' && s[i]<='z')
            s[i]=s[i]-'a'+'A';
}
vector<int>essay,edge[MAXN],tedge[MAXN];
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int Index,top,scc;
bool Instack[MAXN];
void Tarjan(int u)
{
    int v;
    Low[u]=DFN[u]=++Index;
    Stack[top++]=u;
    Instack[u]=1;
    for(int i=0;i<(int)edge[u].size();i++)
    {
        v=edge[u][i];
        if(!DFN[v])
        {
            Tarjan(v);
            if(Low[u]>Low[v])Low[u]=Low[v];
        }
        else if(Instack[v] && Low[u]>DFN[v])
            Low[u]=DFN[v];
    }
    if(Low[u]==DFN[u])
    {
        scc++;
        do
        {
            v=Stack[--top];
            Instack[v]=0;
            Belong[v]=scc;
        }
        while(v!=u);
    }
}
pair<int,ll>cost[MAXN],tcost[MAXN];
bool vis[MAXN];
void dfs(int u)
{
    if(vis[u])return;
    vis[u]=1;
    for(int i=0;i<(int)tedge[u].size();i++)
    {
        int v=tedge[u][i];
        dfs(v);
        tcost[u]=min(tcost[u],tcost[v]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin>>m;
    string str;
    for(int i=0;i<m;i++)
    {
        cin>>str;
        normalize(str);
        essay.push_back(getId(str));
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        normalize(str);
        int u=getId(str);
        cin>>str;
        normalize(str);
        int v=getId(str);
        edge[u].push_back(v);
    }
    for(auto itr=mp.begin();itr!=mp.end();itr++)
    {
        int cnt=0;
        for(int i=0;i<(int)itr->first.size();i++)
            cnt+=(itr->first[i] == 'R');
        cost[itr->second]=make_pair(cnt,(int)itr->first.size());
    }
    for(int i=1;i<=(int)mp.size();i++)
        if(!DFN[i])Tarjan(i);
    for(int i=1;i<=scc;i++)tcost[i]=make_pair(INF,0);
    for(int i=1;i<=(int)mp.size();i++)
    {
        tcost[Belong[i]]=min(tcost[Belong[i]],cost[i]);
        for(int j=0;j<(int)edge[i].size();j++)
            if(Belong[i]!=Belong[edge[i][j]])
                tedge[Belong[i]].push_back(Belong[edge[i][j]]);
    }
    for(int i=1;i<=scc;i++)
        if(!vis[i])dfs(i);
    pair<int,ll> res=make_pair(0,0);
    for(int i=0;i<(int)essay.size();i++)
        res=res+tcost[Belong[essay[i]]];
    cout<<res.first<<" "<<res.second<<endl;
    return 0;
}