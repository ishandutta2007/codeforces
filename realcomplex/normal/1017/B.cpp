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
  string a, b;
  cin >> a >> b;
  ll mask1 = 0, mask2 = 0, mask3 = 0, mask4 = 0;
  ll ans = 0ll;
  for(int i = 0;i < n;i ++ ){
    if(a[i] == '0' and b[i] == '0') mask1 ++ ;
    if(a[i] == '0' and b[i] == '1') mask2 ++ ;
    if(a[i] == '1' and b[i] == '0') mask3 ++ ;
    if(a[i] == '1' and b[i] == '1') mask4 ++ ;
  }
  ans += mask1 * (mask3 + mask4);
  ans += mask2 * mask3;
  cout << ans;
  return 0;
}