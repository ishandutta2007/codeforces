#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define int ll
typedef long long ll;
int n,m,i,j,k,t,u,v,a,b,cur[100001],diff[7];
struct cmp
{
    int operator() (int a, int b) const
    {
        if (!(cur[a]-cur[b])) return (a>b);
        return cur[a]>cur[b];
    }
};
set<int,cmp> se;
vector<pii> bruh;
signed main()
{
    for (i=1;i<=6;i++) cin>>diff[i];
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cur[i]=1e18;
        cin>>u;
        for (j=1;j<=6;j++) bruh.push_back({u-diff[j],i});
    
        se.insert(i);
    }
    a=1e18;
    sort(bruh.begin(),bruh.end(),[](pii a, pii b){return (a.first>b.first);});
    for (pii pp : bruh)
    {
        se.erase(pp.second);
        cur[pp.second]=pp.first;
        se.insert(pp.second);
        a=min(a,cur[*(se.begin())]-pp.first);
    }
    cout<<a;
}