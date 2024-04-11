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
#define ones(a) __builtin_popcount(a)

const int N = (int)1e5 + 9;
const int SQ = int(sqrt(N) + 1);

int dp[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  int a;
  int ans = 1;
  int mx;
  for(int i = 0;i < n;i ++ ){
    cin >> a;
    if(a == 1)
      continue;
    vector<int> dd;
    dd.push_back(a);
    for(int j = 2;j*j <= a; j ++ ){
      if(a%j != 0) continue;
      dd.push_back(j);
      if(a/j != j)
        dd.push_back(a/j);
    } 
    mx = 0;
    for(int x : dd)
      mx = max(dp[x], mx);
    for(auto x : dd){
      dp[x] = max(dp[x], mx + 1);
      ans = max(ans, dp[x]);
    }
  }
  cout << ans;
  return 0;
}