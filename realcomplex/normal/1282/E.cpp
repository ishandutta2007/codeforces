#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;

vector<int> T[N];
map<pii, int> cnt;
bool cut[N];
vector<int> B[N];
int deg[N];

void solve(){
  cnt.clear();
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++ ){
    T[i].clear();
    B[i].clear();
    deg[i] = 0;
  }
  int t[n][3];
  for(int i = 0 ; i < n - 2; i ++ ){
    for(int j = 0 ; j < 3; j ++ ){
      cin >> t[i][j];
      B[t[i][j]].push_back(i);
    }
    for(int x = 0; x < 3; x ++ ){
      for(int z = 0 ; z < 3; z ++ ){
        if(x != z){
          T[t[i][x]].push_back(t[i][z]);
          cnt[mp(t[i][x],t[i][z])] ++ ;
          deg[t[i][x]] ++ ;
        }
          
      }
    }
    cut[i] = false;
  }
  int root = 0;
  for(int i = 1; i <= n; i ++ )
    if(T[i].size() == 2) root = i;
  vector<int> ord = {root};
  int nx;
  int p;
  while(1){
    p = ord.back();
    for(auto x : T[p]){
      if(cnt[mp(p, x)] == 1 && (ord.size() == 1 || x != ord[(int)ord.size() - 2])){
        nx = x;
        break;
      }
    }
    if(nx == root)
      break;
    ord.push_back(nx);
  }
  for(auto x : ord)
    cout << x << " ";
  cout << "\n";
  priority_queue<pii, vector<pii>, greater<pii>> dg;
  for(int i = 1; i <= n; i ++ )
    dg.push(mp(deg[i], i));
  int del;
  for(int i = 0 ; i < n-2; i ++ ){
    while(!dg.empty() && dg.top().fi != 2)dg.pop();
    root = dg.top().se;
    dg.pop();
    del = -1;
    for(auto x : B[root]){
      if(!cut[x]){
        del = x;
      }
    }
    for(int x = 0; x < 3; x ++ ){
      deg[t[del][x]] -= 2;
      dg.push(mp(deg[t[del][x]],t[del][x]));
    }
    cut[del] = true;
    cout << del + 1 << " ";
  }
  cout << "\n";
}

int main(){
  fastIO;
  int tc; 
  cin >> tc;
  for(int x = 0 ; x < tc ; x ++ ){
    solve();
  }
  return 0;
}