#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
int a[N];

map<int, int> bl;

void solve(){
  bl.clear();
  int n;
  cin >> n;
  for(int i = 1 ; i <= 2 * n; i ++ ){
    cin >> a[i];
  }
  int b = 0;
  bl[0] = 0;
  for(int i = 1 ; i <= n; i ++ ){
    if(a[i] == 1) b ++ ;
    else b -- ;
    bl[b] = i;
  }
  int res = 2 * n - bl[0];
  b = 0;
  for(int i = 2 * n; i >= n + 1; i -- ){
    if(a[i] == 2) b ++ ;
    else b -- ;
    if(bl.count(b))
      res = min(res, i - bl[b] - 1);
  }
  cout << res << "\n";
}

int main(){
  
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ){
    solve();
  }
  return 0;
}