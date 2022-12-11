#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = (int)2e5 + 1234;
vector<int>T[N];
bool vis[N];
int p = 0;
vector<int>C[N];

void dfs(int u){
  vis[u] = true;
  C[p].push_back(u);
  for(auto x : T[u]){
    if(!vis[x])
      dfs(x);
  }
}

int main(){
  fastIO;
  int n,m;
  cin >> n >> m;
  int a,b;
  for(int i = 0;i < m ;i ++ ){
    cin >> a >> b;
    T[a].push_back(b);
    T[b].push_back(a);
  }
  for(int i = 1;i <= n; i ++){
    if(!vis[i]){
      dfs(i);
      p ++ ;
    }
  }
  bool check;
  int ans = 0;
  for(int i = 0;i < p;i ++){
    check = true;
    for(auto x : C[i]){
      if(T[x].size() != 2){
        check = false;
      }
    }
    if(check)
      ans ++ ;
  }
  cout << ans;
  return 0;
}