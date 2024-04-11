#include<bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
vector<pair<int,pair<int,int> > >g[1000001];
int d[1000001];
int last[1000001];
int32_t main()
{
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        int a,b,x;cin>>a>>b>>x;
        g[a].push_back({b,{x,i}});
        g[b].push_back({a,{x,i}});
    }
    set<pair<int,int> >q;
    int cnt=0;
    for (int i=1;i<=n;i++) d[i]=-1;
    q.insert({0,1});
    d[1]=0;
    vector<int>ans;
    while (!q.empty() && cnt<min(k,n-1)){
          auto x=*q.begin();
          q.erase(q.begin());
          int v=x.second;
          if (last[v]){
             cnt++;
             ans.push_back(last[v]);
          }
          for (auto y:g[v]){
              int to=y.first;
              int dist=y.second.first;
              int reb=y.second.second;
              if (d[to]==-1){
                  d[to]=d[v]+dist;
                  last[to]=reb;
                  q.insert({d[to],to});
              } else if (d[to]>d[v]+dist){
                  q.erase({d[to],to});
                  d[to]=d[v]+dist;
                  last[to]=reb;
                  q.insert({d[to],to});
              }
          }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for (auto i:ans) cout<<i<<" ";
    return 0;
}