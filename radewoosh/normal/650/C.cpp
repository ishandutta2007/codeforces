#include <bits/stdc++.h>
using namespace std;

int n, m;

vector <int> tab[1000007];

vector <int> graf[1000007];
vector <int> farg[1000007];

vector < pair <int,int> > dos;

int bylo[1000007];
int l;
int pos[1000007];

int spo[1000007];
vector <int> grafs[1000007];

int dp[1000007];

void dfs(int v)
{
    if (bylo[v])
    return;
    bylo[v]=1;
    for (int i=0; i<graf[v].size(); i++)
    dfs(graf[v][i]);
    l++;
    pos[l]=v;
}

void dfs2(int v)
{
    if (spo[v])
    return;
    spo[v]=l;
    for (int i=0; i<farg[v].size(); i++)
    dfs2(farg[v][i]);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            tab[i].push_back(0);
            scanf("%d", &tab[i][j]);
        }
    }
    for (int i=0; i<n; i++)
    {
        dos.clear();
        for (int j=0; j<m; j++)
        {
            dos.push_back(make_pair(tab[i][j], j));
        }
        sort(dos.begin(), dos.end());
        for (int j=1; j<dos.size(); j++)
        {
            graf[i*m+dos[j-1].second].push_back(i*m+dos[j].second);
            if (dos[j].first==dos[j-1].first)
            graf[i*m+dos[j].second].push_back(i*m+dos[j-1].second);
        }
    }
    for (int i=0; i<m; i++)
    {
        dos.clear();
        for (int j=0; j<n; j++)
        {
            dos.push_back(make_pair(tab[j][i], j));
        }
        sort(dos.begin(), dos.end());
        for (int j=1; j<dos.size(); j++)
        {
            graf[m*dos[j-1].second+i].push_back(m*dos[j].second+i);
            if (dos[j].first==dos[j-1].first)
            graf[m*dos[j].second+i].push_back(m*dos[j-1].second+i);
        }
    }
    for (int i=0; i<n*m; i++)
    for (int j=0; j<graf[i].size(); j++)
    farg[graf[i][j]].push_back(i);
    for (int i=0; i<n*m; i++)
    dfs(i);
    l=0;
    for (int i=n*m; i; i--)
    {
        if (spo[pos[i]])
        continue;
        l++;
        dfs2(pos[i]);
    }
    for (int i=0; i<n*m; i++)
    {
        for (int j=0; j<farg[i].size(); j++)
        {
            if (spo[i]!=spo[farg[i][j]])
            {
                grafs[spo[i]].push_back(spo[farg[i][j]]);
            }
        }
    }
    for (int i=1; i<=l; i++)
    {
        dp[i]=1;
        for (int j=0; j<grafs[i].size(); j++)
        {
            dp[i]=max(dp[i], dp[grafs[i][j]]+1);
        }
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            printf("%d ", dp[spo[i*m+j]]);
        }
        printf("\n");
    }
    return 0;
}