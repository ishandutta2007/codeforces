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

int main(){
  fastIO;
  int n;
  ll m;
  cin >> n >> m;
  ll d[n];
  ll a, b;
  ll sum = 0;
  for(int j = 0;j < n;j ++ ){
    cin >> a >> b;
    sum += a;
    d[j] = a - b;
  }
  sort(d, d + n);
  int ans = 0;
  if(sum <= m){
    cout << 0;
    return 0;
  }
  for(int x = n-1;x >= 0; x -- ){
    sum -= d[x];
    ans ++ ;
    if(sum <= m){
      cout << ans;
      return 0;
    }
  }
  cout << -1;
  return 0;
}