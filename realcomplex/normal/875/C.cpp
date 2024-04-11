#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 11;

vector<int> T[N];
vector<int> g[N];
bool need[N];

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  int k;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> k;
    g[i].resize(k);
    for(int j = 0 ; j < k ; j ++ )
      cin >> g[i][j];
  }
  int a, b;
  int x, y;
  queue<int> bf;
  for(int i = 0 ; i + 1 < n; i ++ ){
    a = g[i].size();
    b = g[i + 1].size();
    x=-1,y=-1;
    for(int t = 0 ; t < min(a, b); t ++ ){
      if(g[i][t] != g[i+1][t]){
        x=g[i][t];
        y=g[i+1][t];
        break;
      }
    }
    if(x==-1){
      if(a > b){
        cout << "No\n";
        return 0;
      }
      continue;
    }
    if(x < y){
      T[y + m].push_back(x + m);
    }
    else{
      bf.push(x + m);
      need[x + m] = true;
      T[x + m].push_back(y);
    }
  }
  int node;
  while(!bf.empty()){
    node = bf.front();
    bf.pop();
    for(auto p : T[node]){
      if(need[p]) continue;
      need[p]=true;
      bf.push(p);
    }
  }
  vector<int> ans;
  for(int i = 1; i <= m; i ++ ){
    if(need[i] && need[m + i]){
      cout << "No\n";
      return 0;
    }
    if(need[m + i]) ans.push_back(i);
  }
  cout << "Yes\n";
  cout << ans.size() << "\n";
  for(auto x : ans) cout << x << " ";
  cout << "\n";
  return 0;
}