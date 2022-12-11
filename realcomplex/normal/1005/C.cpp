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

map<ll,ll>has;
map<ll,ll>ok;

int main(){
  fastIO;
  int n;
  cin >> n;
  ll a[n];
  for(int i = 0;i < n;i ++ ){
    cin >> a[i];
    has[a[i]] ++ ;
  }
  
  ll pw = 1LL;
  for(int i = 0;i < n;i ++ ){
    pw = 1;
    for(int j = 0;j < 32; j ++ ){
      if(pw >= a[i]){
        if(has[pw - a[i]] >= 1 + (a[i] * 2 == pw)){
          ok[a[i]] = 1;
          break;
        }
      }

      pw *= 2LL;
    }
  }
  int ans = 0;
  for(int j = 0;j < n; j ++ ){
    if(ok[a[j]] != 1)
      ans ++ ;
  }
  cout << ans;
  return 0;
}