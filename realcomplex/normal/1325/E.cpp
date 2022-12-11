#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 9;
const int M = (int)1e3 + 5;
vector<int> pr[N];
vector<int> g[N];

int cnt[N];
int dis[N];


int main(){
  fastIO;
  for(int i = 0 ; i < N ; i ++ ){
    dis[i] = (int)1e9;
  }
  for(int i = 2; i < N ; i ++ ){
    if(pr[i].empty()){
      pr[i].push_back(i);
      for(int j = 2 * i ; j < N ; j += i ){
        pr[j].push_back(i);
      }
    }
  }
  int n;
  cin >> n;
  int a;
  int p,q;
  bool two = false;
  for(int i = 1; i <= n; i ++ ){
    cin >> a;
    p = 1, q = 1;
    for(auto x : pr[a]){
      while(x <= M && a % (x * x) == 0){
        a /= x * x;
      }
      if(a % x == 0){
        if(p == 1) p = x;
        else q = x;
      }
    }
    cnt[a]++;
    if(cnt[a] > 1) two = true;
    if(p==1 && q==1){
      cout << 1 << "\n";
      return 0;
    }
    g[p].push_back(q);
    g[q].push_back(p);
  }
  if(two){
    cout << 2 << "\n";
    return 0;
  }
  int res = n + 1;
  int node;
  for(int i = 1 ;i < M ; i ++ ){
    if(g[i].size() >= 2){
      queue<int> bf;
      bf.push(i);
      vector<int> had;
      dis[i] = 0;
      while(!bf.empty()){
        node = bf.front();
        had.push_back(node);
        bf.pop();
        for(auto x : g[node]){
          if(dis[x] > dis[node] + 1){
            dis[x] = dis[node] + 1;
            bf.push(x);
          }
          else if(dis[x] == dis[node] + 1){
            res = min(res, 2 * dis[x]);
          }
          else if(dis[x] == dis[node]){
            res = min(res, 2 * dis[x] + 1);
          }
        }
      }
      for(auto p : had) dis[p] = (int)1e9;
    }
  }
  if(res == n + 1) cout << -1 << "\n";
  else cout << res << "\n";
  return 0;
}