//https://atcoder.jp/contests/abc254/submissions/32232114
#include<bits/stdc++.h>
using namespace std;
const int MAXN=6000005;
struct Node
{
    int go[2],cnt[2];
    Node()
    {
        memset(go,0,sizeof(go));
        memset(cnt,0,sizeof(cnt));
    }
}node[MAXN];
const int root=1;
int tot;
void init()
{
    for(int i=1;i<=tot;i++)
        node[i]=Node();
    tot=1;
}
void add(const vector<int>& s, int ty)
{
    int p=root;
    for(auto c : s)
    {
        if(!node[p].go[c])node[p].go[c]=++tot;
        p=node[p].go[c];
    }
    node[p].cnt[ty]++;
}
void dfs(int p,int& res)
{
    if(node[p].go[0])
    {
        dfs(node[p].go[0],res);
        for(int i=0;i<2;i++)
        {
            res+=node[node[p].go[0]].cnt[i];
            node[p].cnt[i]+=node[node[p].go[0]].cnt[i];
        }
    }
    if(node[p].go[1])
    {
        dfs(node[p].go[1],res);
        if(node[node[p].go[1]].cnt[1])throw "no solution";
        for(int i=0;i<2;i++)
        {
            res+=node[node[p].go[1]].cnt[i];
            node[p].cnt[i]+=node[node[p].go[1]].cnt[i];
        }
    }
    int t=min(node[p].cnt[0],node[p].cnt[1]);
    for(int i=0;i<2;i++)node[p].cnt[i]-=t;
}
int solve()
{
    init();
    int n;
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
        int a;
        scanf("%d",&a);
        vector<int> s;
        while(a)s.push_back(a%2),a/=2;
        reverse(s.begin(),s.end());
        add(s,i<=n);
    }
    try
    {
        int res=0;
        dfs(root,res);
        printf("YES\n");
    }
    catch(...)
    {
        printf("NO\n");
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}