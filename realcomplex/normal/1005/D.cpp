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

const int N = (int)2e5 + 9;
int dp[N];

int main(){
  fastIO;
  string t;
  cin >> t;
  int p = 1;
  int sum;
  for(int j = 0;j < t.size(); j ++ ){
    sum = 0;
    dp[p] = dp[p - 1];
    for(int x = j; x >= max(0, j - 120); x -- ){
      sum += t[x] - '0';
      if(sum % 3 == 0)
        dp[p] = max(dp[p], dp[x] + 1);
    }
    p ++ ;
  } 
  cout << dp[t.size()];
  return 0;
}