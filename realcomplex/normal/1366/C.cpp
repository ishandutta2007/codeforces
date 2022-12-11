#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ;t < tc; t ++ ){
    int n, m;
    cin >> n >> m;
    int d = n + m - 1;
    int c[2][d];
    for(int p = 0 ; p < 2; p ++ )
      for(int q = 0 ; q < d; q ++ )
        c[p][q]=0;
    int x;
    for(int i = 0 ; i < n; i ++ ){
      for(int j = 0 ; j < m ; j ++ ){
        cin >> x;
        c[x][i + j] ++ ;
      }
    }
    int ans = 0;
    for(int i = 0 ; i < d; i ++ ){
      if(d - i - 1 <= i) continue;
      ans += min(c[0][i] + c[0][d - i - 1], c[1][i] + c[1][d - i - 1]);
    }
    cout << ans << "\n";
  }
  return 0;
}