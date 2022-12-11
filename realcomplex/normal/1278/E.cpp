#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 9;
vector<int> T[N];

bool use[2 * N];
int p;
int l[N], r[N];

void dfs(int u, int par){
  if(par == -1){
    l[u] = 1;
    r[u] = T[u].size() + 2;
    use[1] = true;
    use[T[u].size() + 2] = true;
    p = T[u].size() + 3;
    vector<pii> srt;
    int fl = 2;
    for(auto x : T[u]){
      if(x == par) continue;
      dfs(x, u);
      srt.push_back(mp(r[x], x));
    }
    sort(srt.begin(), srt.end());
    reverse(srt.begin(), srt.end());
    for(int i = 0 ; i < srt.size(); i ++ ){
      l[srt[i].se] = fl ++ ;
    }
    return;
  }
  vector<int> rr;
  for(auto x : T[u]){
    if(x == par){
      continue;
    }
    while(use[p])
      p ++ ;
    use[p]=true;
    rr.push_back(p);
  }
  while(use[p])
    p++;
  r[u] = p;
  use[p]=true;
  vector<pii> srt;
  for(int i = 0 ; i < T[u].size(); i ++ ){
    if(T[u][i] == par)continue;
    dfs(T[u][i], u);
    srt.push_back(mp(r[T[u][i]], T[u][i]));
  }
  sort(srt.begin(), srt.end());
  reverse(srt.begin(), srt.end());
  for(int i = 0 ; i < srt.size(); i ++ ){
    l[srt[i].se] = rr[i];
  }
}

int main(){
  fastIO;
  int n;
  cin >> n;
  int x, y;
  for(int i = 1 ;i < n; i ++ ){
    cin >> x >> y;
    T[x].push_back(y);
    T[y].push_back(x);
  }
  dfs(1, -1);
  for(int i = 1; i <= n; i ++ )
    cout << l[i] << " " << r[i] << "\n";
  return 0;
}