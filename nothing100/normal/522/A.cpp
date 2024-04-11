#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define fi first
#define se second
#define N 205
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
map<string,int> mp;
int tot=1,ans=0,dep[N];
vector<int> G[N];
bool vis[N];
void dfs(int x)
{
    int i;
    ans=max(ans,dep[x]);
    vis[x]=1;
    for(i=0;i<G[x].size();i++)
        if(!vis[G[x][i]])
        {
            dep[G[x][i]]=dep[x]+1;
            dfs(G[x][i]);
        }
}

void F(string &s)
{
    int i;
    for(i=0;i<s.size();i++)
    {
        if(s[i]<97)
            s[i]+=32;
    }
}
int main()
{
    string s="polycarp",s1,s2;
    mp[s]=1;
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>s1>>s2;
        cin>>s2;
        F(s1);
        F(s2);
        //cout<<s1<<endl;
        //cout<<s2<<endl;
        if(!mp[s1])
            mp[s1]=++tot;
        if(!mp[s2])
            mp[s2]=++tot;
        //debug(mp[s1]);
        //debug(mp[s2]);
        G[mp[s2]].push_back(mp[s1]);
    }
    dep[1]=1;
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);