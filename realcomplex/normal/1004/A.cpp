#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a)

int main(){
  fastIO;
  int n,d;
  cin >> n >> d;
  if(n == 1){
    cout << 2 << "\n";
    return 0;
  }
  int x[n];
  for(int i= 0 ;i < n;i ++ )
    cin >> x[i];  
  sort(x, x + n);
  int ans = 0;
  set<int>pos;
  for(int i = 0;i < n;i ++ ){
    if(i == 0)
      pos.insert(x[i] - d);
    if(i == n-1)
      pos.insert(x[i] + d);
    if(i != 0){
      if(x[i] -  x[i - 1] >= d * 2)
        pos.insert(x[i] - d);
    }
    if(i != n-1){
      if(x[i + 1] - x[i] >= d * 2)
        pos.insert(x[i] + d);
    }
  }
  cout << pos.size();
  return 0;
}