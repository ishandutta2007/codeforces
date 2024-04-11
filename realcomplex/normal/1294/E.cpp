#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
int cnt[N];

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> f(n);
  for(int i = 0 ; i < n ; i ++ ){
    f[i].resize(m);
    for(int j = 0 ; j < m ; j ++ ){
      cin >> f[i][j];
      f[i][j] -- ;
    }
  }
  int ans = 0;
  int low;
  int nx;
  for(int i = 0 ; i < m ; i ++ ){
    low = n;
    for(int j = 0 ; j < n; j ++ )cnt[j] = 0;
    for(int j = 0 ; j < n; j ++ ){
      if(f[j][i] % m == i && f[j][i] < n*m){
        nx=f[j][i]/m;
        cnt[(j-nx+n)%n]++;
      }
    }
    for(int j = 0 ; j < n ; j ++ ){
      low = min(low, j + n-cnt[j]);
    }
    ans += low;
  }
  cout << ans << "\n";
  return 0;
}