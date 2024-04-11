#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
const ll MOD = 998244353;
int p[N];
bool pick[N];

int main(){
  fastIO;
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  for(int i = 0 ; i < k ; i ++ ){
    ans += n - i;
    pick[n - i] = true;
  }
  cout << ans << " ";
  ll wy = 0;
  ll cur = 1;
  for(int i = 1; i <= n; i ++ ){
    cin >> p[i];
    if(pick[p[i]]){
      wy *= cur;
      wy %= MOD;
      if(wy==0)wy=1;
      cur = 1;
    }
    else{
      cur ++ ;
    }
  }
  cout << wy << "\n";
  return 0;
}