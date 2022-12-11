#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool mch(pii f1, pii f2){
  return (f1.fi == f2.fi && f1.se == f2.se) || (f1.fi == f2.se && f1.se == f2.fi);
}

const int N = 251;
vector<int> T[N];
int match[N];
bool vis[N];
int dis[N];
bool use[N];

bool dfs(int u){
  if(vis[u]) return false;
  vis[u]=true;
  for(auto x : T[u]){
    if(match[x] == -1 || (dis[match[x]] == dis[u] + 1 && dfs(match[x]))){
      match[x]=u;
      use[u]=true;
      return true;
    }
  }
  return false;
}

void solve(){ 
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  vector<pii> m1, m2;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> a[i];
  }
  for(int i = 0 ; i < n ; i ++ ){
    cin >> b[i];
  }
  int k = n/2;
  if(n % 2 == 1){
    if(a[k] != b[k]){
      cout << "No\n";
      return;
    }
  }
  for(int i = 0 ; i < k ; i ++ ){
    m1.push_back(mp(a[i], a[n - i - 1]));
    m2.push_back(mp(b[i], b[n - i - 1]));
  }
  for(int i = 0 ; i < k ; i ++ ){
    T[i].clear();
    match[i]=-1;
    use[i]=false;
    for(int j = 0 ; j < k ; j ++ ){
      if(mch(m1[i],m2[j])){
        T[i].push_back(j);
      }
    }
  }
  int f = 0;
  int tot = 0;
  while(1){
    f = 0;
    queue<int> bf;
    for(int i = 0 ; i < k ; i ++ ){
      if(!use[i]){
        bf.push(i);
        dis[i]=0;
      }
      else{
        dis[i]=-1;
      }
    }
    int node;
    while(!bf.empty()){
      node=bf.front();
      bf.pop();
      for(auto x : T[node]){
        if(match[x] != -1 && dis[match[x]] == -1){
          dis[match[x]] = dis[node] + 1;
          bf.push(match[x]);
        }
      }
    }
    for(int i = 0 ; i < k ; i ++ ) vis[i] = false;
    for(int i = 0 ; i < k ; i ++ ){
      if(!use[i]){
        f += dfs(i);
      }
    }
    if(!f) break;
    tot += f;
  }
  if(tot == k)
    cout << "Yes\n";
  else
    cout << "No\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ) solve();
  return 0;
}