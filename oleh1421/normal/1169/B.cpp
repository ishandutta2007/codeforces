#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>g[300001];
int cnt[300001];
map<pair<int,int>,bool>used;
int main() {
   int n,m;cin>>n>>m;
   vector<pair<int,int> >q;
   for (int i=1;i<=m;i++){
       int a,b;cin>>a>>b;
       if (a>b) swap(a,b);
     //  if (used[{a,b}]) continue;
       g[a].push_back(b);
       g[b].push_back(a);
       q.push_back({a,b});
      // used[{a,b}]=true;
   }
   vector<int>v;
   v.push_back(q[0].first);
   v.push_back(q[0].second);
   for (auto i:v){
       for (int j=1;j<=n;j++) cnt[j]=0;
       int cur=0;
       for (auto p:q){
          if (p.first!=i && p.second!=i){
              cnt[p.first]++;
              cnt[p.second]++;
              cur++;
          }
       }
       for (int j=1;j<=n;j++){
           if (cnt[j]==cur){
              cout<<"YES";
              return 0;
           }
       }

   }
   cout<<"NO";
   return 0;
}
/*
6 7
1 2
2 3
1 3
4 5
5 6
4 6
3 4
*/