#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define mod 1000000007

const int N = (int)1e5 + 7;
vector<int>fir[N],sec[N],scc;
bool mark[N];
int cost[N];

ll cv = 0;
int w = 1;
int vl = 2e9;
int cnt = 0;
void ini(){
  for(int i = 1;i<N;i++)
    mark[i] = false;
}

void dfs(int x){
  mark[x] = true;
  for(auto i : fir[x])
    if(!mark[i])
      dfs(i);
  scc.push_back(x);
}

void nfs(int x){
  mark[x] = true;
  if(cost[x]<vl)vl=cost[x],cnt = 1;
  else if(vl==cost[x])cnt++;
  for(auto i : sec[x])
    if(!mark[i])
      nfs(i);
}

int main(){
  int n,m;
  scanf("%i",&n);
  for(int i = 1;i<=n;i++)
    scanf("%i",&cost[i]);
  scanf("%i",&m);
  int a,b;
  for(int i = 0;i<m;i++){
    scanf("%i %i",&a,&b);
    fir[a].push_back(b);
    sec[b].push_back(a);
  }
  for(int i = 1;i<=n;i++){
    if(!mark[i])
      dfs(i);
  }
  ini();
  int v;
  while(!scc.empty()){
    v = scc.back();
    scc.pop_back();
    if(mark[v])continue;
    vl = 2e9;
    cnt = 0;
    nfs(v);
    cv += vl;
    w = (1LL*w*cnt)%mod;
  }
  printf("%I64d %i\n",cv,w);
  return 0;
}