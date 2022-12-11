#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for(int i = 0 ; i < n ; i ++ )
    cin >> a[i];
  for(int i = 1; i < n ; i ++ ){
    while(a[i] > 0 && d >= i){
      a[0] ++ ;
      a[i] -- ;
      d -= i;
    }
  }
  cout << a[0] << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ; t < tc; t ++ ){
    solve();
  }
  return 0;
}