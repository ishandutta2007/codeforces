#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
vector<int>edge[N];
int use[N][N];

int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  int u,v;
  for(int i = 0;i<m;i++){
    scanf("%d %d",&u,&v);
    edge[u].push_back(v);
  }
  int ans = 0;
  for(int i = 1;i<=n;i++)
    for(auto x : edge[i])
      for(auto v : edge[x]){
        if(v==i or v==x)continue;
        ans+=use[i][v];
        use[i][v]++;
      }
  printf("%d\n",ans);
  return 0;
}