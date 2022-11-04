#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
map<pair<int,ll>,int>mp;
int dfs(int n,ll mask)
{
    if(mp.find(make_pair(n,mask))!=mp.end())
        return mp[make_pair(n,mask)];
    vector<int>nxt;
    for(int i=1;i<=n;i++)
        if(~mask>>i&1)nxt.push_back(dfs(n-i,mask|(1LL<<i)));
    sort(nxt.begin(),nxt.end());
    nxt.erase(unique(nxt.begin(),nxt.end()),nxt.end());
    for(int i=0;i<(int)nxt.size();i++)
        if(nxt[i]!=i)return mp[make_pair(n,mask)]=i;
    return mp[make_pair(n,mask)]=(int)nxt.size();
}
int main()
{
    int n,t=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int s;
        scanf("%d",&s);
        t^=dfs(s,0);
    }
    return 0*printf("%s",(t ? "NO" : "YES"));
}