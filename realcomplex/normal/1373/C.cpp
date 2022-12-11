#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 10;
int low[N];


void solve(){
  string s;
  cin >> s;
  int n = s.size();
  for(int i = 0 ; i <= n; i ++ ){
    low[i] = -1;
  }
  int sum = 0;
  for(int i = 0 ; i < n; i ++ ){
    if(s[i] == '+')
      sum ++ ;
    else
      sum -- ;
    if(sum < 0 && low[-sum] == -1)
      low[-sum] = i + 1;
  }
  ll ans = 0;
  for(int i = 0 ; i <= n; i ++ ){
    if(low[i] != -1){
      ans += low[i];
    }
  }
  cout << ans + n << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0;t < tc;t ++ )
    solve();
  return 0;
}