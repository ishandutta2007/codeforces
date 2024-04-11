#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXL=100005;

struct Trie
{
    int nxt[MAXL][26],dep[MAXL],tot;
    multiset<int> st[MAXL];
    void init()
    {
        memset(nxt,0,sizeof(nxt));
        dep[tot=1]=0;
    }
    void add(const string &str)
    {
        int now=1;
        for(int i=0;i<(int)str.size();i++)
        {
            if(!nxt[now][str[i]-'a'])
                dep[nxt[now][str[i]-'a']=++tot]=dep[now]+1;
            now=nxt[now][str[i]-'a'];
        }
        st[now].insert(dep[now]);
    }
    void dfs(int u=1)
    {
        int emp=(u>1 && st[u].empty());
        for(int i=0;i<26;i++)
        {
            int v=nxt[u][i];
            if(!v)continue;
            dfs(v);
            if(st[u].size()<st[v].size())
                st[u].swap(st[v]);
            for(auto &t:st[v])
                st[u].insert(t);
            st[v].clear();
        }
        if(emp)
        {
            st[u].erase(--st[u].end());
            st[u].insert(dep[u]);
        }
    }
}trie;

char buff[MAXL];

int main()
{
    int n;
    scanf("%d",&n);
    trie.init();
    for(int i=1;i<=n;i++)
    {
        scanf("%s",buff);
        trie.add(buff);
    }
    trie.dfs();
    ll res=0;
    for(auto &t:trie.st[1])
        res+=t;
    printf("%lld\n",res);
    return 0;
}