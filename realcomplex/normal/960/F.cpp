#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = (int)1e5 + 9;

map<int, int> dp[N];

int lastEdge(int u, int w){
  auto it = dp[u].lower_bound(w);
  if(it == dp[u].begin())
    return 1;
  it -- ;
  return (it -> second) + 1;
}

int main(){
  fastIO;
  int n,m;
  cin >> n >> m;
  int ai, bi, wi;
  int ans = 0;
  int current;
  for(int i = 0;i < m;i ++ ){
    cin >> ai >> bi >> wi;
    current = lastEdge(ai, wi);
    if(lastEdge(bi, wi + 1) > current)
      continue;
    dp[bi][wi] = current;
    auto it = dp[bi].upper_bound(wi);
    while(it != dp[bi].end()){
      if(it -> second > current)
        break;
      dp[bi].erase(it);
      it = dp[bi].upper_bound(wi);
    }
    ans = max(ans, current);
  }
  cout << ans << "\n";
  return 0;
}