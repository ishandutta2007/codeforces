#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
vector<int> T[N];
ll w[N];
int len;
ll S;
ll pf[N];

vector<int> path;
int ans;
int pp[N];

void dfs(int u){
  pf[u] += w[u];
  path.push_back(u);
  int low = (int)1e9;
  for(auto x : T[u]){
    pf[x]=pf[u];
    dfs(x);
    low = min(low, pp[x]);
  }
  int m = path.size();
  if(low < m){
    pp[u] = low;
  }
  else{
    int l = 0, r = m - 1;
    int mid;
    while(l < r){
      mid = (l + r) / 2;
      if((m-1)-mid+1 <= len && pf[u]-pf[path[mid]]+w[path[mid]] <= S)
        r = mid;
      else
        l = mid + 1;
    }
    pp[u] = l;
    ans ++ ;
  }
  path.pop_back();
}

int main(){
  fastIO;
  int n;
  cin >> n >> len >> S;
  for(int i = 1; i <= n; i ++ )
    pp[i] = n + 5;
  for(int i = 1; i <= n; i ++ ){
    cin >> w[i];
    if(w[i] > S){
      cout << -1 << "\n";
      return 0;
    }
  }
  int p;
  for(int i = 2; i <= n; i ++ ){
    cin >> p;
    T[p].push_back(i);
  }
  dfs(1);
  cout << ans << "\n";
  return 0;
}