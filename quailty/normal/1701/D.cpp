#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
vector<pair<int,int>> e[MAXN];
int res[MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int b;
        scanf("%d",&b);
        e[i/(b+1)+1].emplace_back((b==0 ? n : i/b),i);
    }
    priority_queue<pair<int,int>> que;
    for(int i=1;i<=n;i++)
    {
        for(auto& ed : e[i])
            que.push({-ed.first,ed.second});
        assert(!que.empty());
        res[que.top().second]=i;
        que.pop();
    }
    for(int i=1;i<=n;i++)
        e[i].clear();
    for(int i=1;i<=n;i++)
        printf("%d%c",res[i]," \n"[i==n]);
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}