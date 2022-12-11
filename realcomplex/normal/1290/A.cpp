#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int a[4000];
int hgh[4000];
int low[4000][4000];

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++ )
      cin >> a[i];
    if(k >= m - 1){
      int res = 0;
      for(int i = 1; i <= n; i ++ ){
        if(min(i-1,n-i) <= m - 1){
          res = max(res, a[i]);
        }
      }
      cout << res << "\n";
      continue;
    }
    int lf = 0,rf = 0;
    int res = 0;
    int lw;
    int rm = m-1-k;
    for(int j = 0 ; j <= k; j ++ ){
      lf = j;
      rf = k - j;
      lw = (int)1e9;
      for(int c = 0;c <= rm; c ++ ){
        lw = min(lw,max(a[lf+c+1],a[n-rf-(rm-c)]));
      }
      res = max(res, lw);
    }
    cout << res << "\n";
  }
  return 0;
}