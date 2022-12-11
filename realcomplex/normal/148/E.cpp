#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int M = (int)1e4 + 9;
const int N = 105;
int dp[M];
int items[N];

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  int x;
  int el;
  int tot;
  int lf;
  int cur;
  for(int tt = 0;tt < n;tt ++ ){
    cin >> x;
    memset(items, 0, sizeof items);
    vector<int> pref;
    tot = 0;
    for(int i = 0;i < x;i ++ ){
      cin >> el;
      pref.push_back(el);
      tot += el;
    }
    items[x] = tot;
    for(int i = 0;i < x;i ++ ){
      cur = 0;
      lf = x;
      for(int j = i; j < x;j ++ ){
        cur += pref[j];
        lf -- ;
        items[lf] = max(items[lf], tot - cur);
      }
    }
    for(int i = m;i >= 0;i -- ){
      for(int j = 1;j <= x;j ++ ){
        if(i >= j){
          dp[i] = max(dp[i], dp[i-j] + items[j]);
        }
      }
    }
  }
  int ans = 0;
  for(int i = 1; i <= m; i ++ )
    ans = max(ans, dp[i]);
  cout << ans << "\n";
  return 0;
}