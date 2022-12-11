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
  cin >> n;
  int tom = 0, cur;
  int a;
  for(int i = 0;i < 4;i ++ ){
    cin >> a;
    tom += a;
  }
  int ans = 1;
  for(int i = 1;i < n;i ++ ){
    cur = 0;
    for(int j = 0;j < 4;j ++ ){
      cin >> a;
      cur += a;
    }
    if(cur > tom)
      ++ ans;
  }
  cout << ans;
  return 0;
}