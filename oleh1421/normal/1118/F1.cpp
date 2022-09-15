#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[300001];
vector<int>g[300001];
int sz1[300001];
int sz2[300001];
int res=0;
bool ok(int a1,int a2,int b1,int b2){
     return (a1*a2==0 && b1*b2==0);
}
void dfsinit(int v,int pr){
     sz1[v]=(a[v]==1);
     sz2[v]=(a[v]==2);
     for (auto to:g[v]){
         if (to==pr) continue;
         dfsinit(to,v);
         sz1[v]+=sz1[to];
         sz2[v]+=sz2[to];
     }
}
void dfs(int v,int pr){
     for (auto to:g[v]){
         if (to==pr) continue;
         res+=ok(sz1[to],sz2[to],sz1[1]-sz1[to],sz2[1]-sz2[to]);
         dfs(to,v);
     }
}
int main(){
   int n;cin>>n;
   for (int i=1;i<=n;i++) cin>>a[i];
   for (int i=1;i<n;i++){
       int x,y;cin>>x>>y;
       g[x].push_back(y);
       g[y].push_back(x);
   }
   dfsinit(1,-1);
   dfs(1,-1);
   cout<<res;
   return 0;
}