#include <bits/stdc++.h>
using namespace std;
 
int n, m, q;
 
int p1, p2, p3, p4;
vector < pair <int,int> > graph[1000007];
 
int l;
int pre[1000007];
int low[1000007];
 
vector <int> vec;
 
int bic[1000007];
 
int b;
vector <int> bgraph[1000007];
int bpre[1000007];
int bpost[1000007];
 
int c;
int conn[1000007];
int dis[1000007];
 
vector <int> jump[1000007];
 
vector <int> subset;
vector < pair <int,int> > edges;
 
int trans[1000007];
vector <int> sta;
 
vector < pair <int,int> > ngraph[1000007];
int bic2[1000007];
 
int res;
 
void dfs1(int v, int p)
{
    l++;
    pre[v]=l;
    low[v]=l;
    sta.push_back(v);
    for (int i=0; i<graph[v].size(); i++)
    {
        if (graph[v][i].second==p)
        continue;
        if (pre[graph[v][i].first])
        {
            low[v]=min(low[v], pre[graph[v][i].first]);
        }
        else
        {
            dfs1(graph[v][i].first, graph[v][i].second);
            low[v]=min(low[v], low[graph[v][i].first]);
        }
    }
    if (pre[v]==low[v])
    {
        b++;
        while(sta.back()!=v)
        {
            bic[sta.back()]=b;
            sta.pop_back();
        }
        bic[sta.back()]=b;
        sta.pop_back();
    }
}
 
void dfs2(int v, int p)
{
    l++;
    bpre[v]=l;
    conn[v]=c;
 
    jump[v].push_back(p);
    while(jump[v].back())
    {
        p1=jump[v].size()-1;
        p2=jump[v].back();
        jump[v].push_back(jump[p2][min(p1, (int)jump[p2].size()-1)]);
    }
 
    for (int i=0; i<bgraph[v].size(); i++)
    {
        if (bgraph[v][i]!=p)
        {
            dis[bgraph[v][i]]=dis[v]+1;
            dfs2(bgraph[v][i], v);
        }
    }
    l++;
    bpost[v]=l;
}
 
int lca(int v, int u)
{
    if (conn[v]!=conn[u])
    return 0;
    for (int i=jump[v].size()-1; i>=0; i--)
    {
        if (i<jump[v].size() && dis[jump[v][i]]>=dis[u])
        {
            v=jump[v][i];
        }
    }
    for (int i=jump[u].size()-1; i>=0; i--)
    {
        if (i<jump[u].size() && dis[jump[u][i]]>=dis[v])
        {
            u=jump[u][i];
        }
    }
    for (int i=jump[v].size()-1; i>=0; i--)
    {
        if (i<jump[v].size() && i<jump[u].size() && jump[v][i]!=jump[u][i])
        {
            v=jump[v][i];
            u=jump[u][i];
        }
    }
    if (v!=u)
    v=jump[v][0];
    return v;
}
 
bool comp(int v, int u)
{
    return bpre[v]<bpre[u];
}
 
void filtr()
{
    vector <int> vec2=vec;
    vec.clear();
    sort(vec2.begin(), vec2.end(), comp);
    for (int i=0; i<vec2.size(); i++)
    {
        if (!vec2[i])
        continue;
        if (!i || vec2[i]!=vec2[i-1])
        {
            vec.push_back(vec2[i]);
        }
    }
}
 
void dfs3(int v, int p)
{
    l++;
    pre[v]=l;
    low[v]=l;
    sta.push_back(v);
    for (int i=0; i<ngraph[v].size(); i++)
    {
        if (ngraph[v][i].second==p)
        continue;
        if (pre[ngraph[v][i].first])
        {
            low[v]=min(low[v], pre[ngraph[v][i].first]);
        }
        else
        {
            dfs3(ngraph[v][i].first, ngraph[v][i].second);
            low[v]=min(low[v], low[ngraph[v][i].first]);
        }
    }
    if (pre[v]==low[v])
    {
        b++;
        while(sta.back()!=v)
        {
            bic2[sta.back()]=b;
            sta.pop_back();
        }
        bic2[sta.back()]=b;
        sta.pop_back();
    }
}
 
long long R;
 
int rotate(int element)
{
    element=(element+R)%n;
    if (element==0)
    element=n;
    return element;
}
 
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d", &p1, &p2);
        graph[p1].push_back(make_pair(p2, i));
        graph[p2].push_back(make_pair(p1, i));
    }
    for (int i=1; i<=n; i++)
    {
        if (!pre[i])
        {
            dfs1(i, 0);
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<graph[i].size(); j++)
        {
            if (bic[i]!=bic[graph[i][j].first])
            {
                bgraph[bic[i]].push_back(bic[graph[i][j].first]);
            }
        }
    }
    l=0;
    for (int i=1; i<=b; i++)
    {
        if (!bpre[i])
        {
            c++;
            dfs2(i, 0);
        }
    }
    for (int h=1; h<=q; h++)
    {
        subset.clear();
        edges.clear();
        vec.clear();
        scanf("%d%d", &p1, &p2);
        while(p1--)
        {
            scanf("%d", &p3);
            p3=rotate(p3);
            subset.push_back(bic[p3]);
            vec.push_back(bic[p3]);
        }
        while(p2--)
        {
            scanf("%d%d", &p3, &p4);
            p3=rotate(p3);
            p4=rotate(p4);
            edges.push_back(make_pair(bic[p3], bic[p4]));
            vec.push_back(bic[p3]);
            vec.push_back(bic[p4]);
        }
        sort(vec.begin(), vec.end(), comp);
        for (int i=vec.size()-1; i; i--)
        {
            vec.push_back(lca(vec[i], vec[i-1]));
        }
        filtr();
        c=vec.size();
        for (int i=0; i<c; i++)
        {
            trans[vec[i]]=i+1;
            ngraph[i+1].clear();
            pre[i+1]=0;
            low[i+1]=0;
        }
        l=0;
        sta.clear();
        for (int i=0; i<c; i++)
        {
            while(!sta.empty() && bpost[vec[i]]>bpost[sta.back()])
            {
                sta.pop_back();
            }
            if (!sta.empty())
            {
                l++;
                ngraph[trans[vec[i]]].push_back(make_pair(trans[sta.back()], l));
                ngraph[trans[sta.back()]].push_back(make_pair(trans[vec[i]], l));
            }
            sta.push_back(vec[i]);
        }
        sta.clear();
        for (int i=0; i<edges.size(); i++)
        {
            l++;
            ngraph[trans[edges[i].first]].push_back(make_pair(trans[edges[i].second], l));
            ngraph[trans[edges[i].second]].push_back(make_pair(trans[edges[i].first], l));
        }
        b=0;
        l=0;
        for (int i=1; i<=c; i++)
        {
            if (!pre[i])
            {
                dfs3(i, 0);
            }
        }
        res=1;
        for (int i=1; i<subset.size(); i++)
        {
            if (bic2[trans[subset[i]]]!=bic2[trans[subset[0]]])
            {
                res=0;
            }
        }
        if (res)
        {
            printf("YES\n");
            R+=h;
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}