#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);

const int MAX = 3005;

vector<int> bribe[MAX];

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  int pi, ci;
  for(int i = 0;i < n;i ++ ){
    cin >> pi >> ci;
    bribe[pi].push_back(ci);
  }
  for(int i = 1;i <= m;i ++ ){
    sort(bribe[i].begin(), bribe[i].end());
  }
  int rq;
  int f;
  ll ans = (ll)1e18;
  ll cur;
  for(int i = max(1, (int)bribe[1].size());i <= n;i ++ ){
    cur = 0ll;
    f = bribe[1].size();
    vector<int> tt;
    for(int j = 2;j <= m;j ++ ){
      if(bribe[j].empty())
        continue;
      rq = max(0, ((int)bribe[j].size()) - (i - 1));
      for(int x = 0;x < bribe[j].size(); x++ ){
        if(x < rq){
          cur += bribe[j][x];
          f ++ ;
        }
        else{
          tt.push_back(bribe[j][x]);
        }
      }
    }
    sort(tt.begin(), tt.end());
    reverse(tt.begin(), tt.end());
    while(f < i){
      cur += tt.back();
      tt.pop_back();
      f ++ ;
    }
    ans = min(ans, cur);
  }
  cout << ans;
  return 0;
}