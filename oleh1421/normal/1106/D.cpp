#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
set<int>g[100001];
int cnt[100001];
vector<int>ans;
int n,m;
set<int>p;
bool used[100001];
void dfs(int v){
     p.erase(v);
     ans.push_back(v);
     if (ans.size()==n) return;
     used[v]=true;
     set<int>s=g[v];
     //if (p.size()<s.size()) p.swap(s);
     for (auto to:s) {
            if (!used[to]) p.insert(to);
     }
     //cout<<v<<endl;
     //for (auto j:p) cout<<j<<" ";
     //cout<<endl;
     set<int>::iterator u=p.begin();
    // while (used[*u]) u++;
     dfs(*u);
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin>>n>>m;
   for (int i=0;i<m;i++){
       int x,y;cin>>x>>y;
       g[x].insert(y);
       g[y].insert(x);
   }
   dfs(1);
   for (auto i:ans) cout<<i<<' ';

   return 0;
}