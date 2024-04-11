#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


void solve(){
  int n, k;
  cin >> n >> k;
  vector<int> cnt(200);
  ll a;
  int cur;
  int p = 0;
  for(int i = 1 ; i <= n; i ++ ){
    cin >> a;
    p = 0;
    while(a > 0){
      cur = a % k ;
      if(cur == 0 || cur == 1)
        cnt[p] += cur;
      else
        cnt[p] += 10;
      p++;
      a /= k;
    }
  }
  for(int i = 0 ; i < 200 ; i ++ ){
    if(cnt[i] > 1){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
 

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int i = 0 ; i < tc; i ++ )
    solve();
  return 0;
}