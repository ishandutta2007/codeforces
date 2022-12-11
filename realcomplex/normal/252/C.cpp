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
  int n, d;
  cin >> n >> d;
  vector<int>p;
  int x;
  for(int i = 0; i < n; i++ ){
    cin >> x;
    p.push_back(x);
  }
  int y;
  ll rz;
  ll ans = 0;
  for(int i = 0;i < n; i++ ){
    if(p[n - 1] - p[i] <= d)
      y = n - 1;
    else{
      y = upper_bound(p.begin(), p.end(), p[i] + d) - p.begin();
      y--;
    }
    if(y < i)
      continue;
    rz = (y - i);
    ans += (rz * (rz - 1))/2;
  }
  cout << ans;
  return 0;
}