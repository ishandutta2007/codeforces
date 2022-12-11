#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int cnt[20];
ll v[N];

int main(){
  fastIO;
  int n;
  cin >> n;
  ll x;
  for(int i = 0 ; i < n; i ++ ){
    cin >> x;
    for(int j = 0 ; j < 20; j ++ ){
      if((x & (1ll << j))) cnt[j] ++ ;
    }
  }
  for(int j = 0 ; j < 20 ; j ++ ){
    for(int i = 0 ; i < cnt[j]; i ++ )
      v[i] |= (1ll << j);
  }
  ll ans = 0;
  for(int i = 0 ; i < n; i ++ ){
    ans += (v[i] * 1ll * v[i]);
  }
  cout << ans << "\n";
  return 0;
}