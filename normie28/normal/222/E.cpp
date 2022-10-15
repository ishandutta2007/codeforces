#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int MAX = 55;
const int MOD = 1e9 + 7;
 
struct mat
{
  int a[MAX][MAX], n;
  mat(int _n, int f){
    n = _n;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        a[i][j] = (i == j && f);
  }
  int * operator [](int x){
    return a[x];
  }
};
 
mat operator *(mat a, mat b){
  mat ans(a.n, 0);
  for(int i = 0; i < a.n; i++)
    for(int j = 0; j < a.n; j++)
      for(int k = 0; k < a.n; k++)
        ans[i][j] = (ans[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
  return ans;
}
 
mat bpow(mat a, ll b){
  mat ans(a.n, 1);
  while(b){
    if(b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
 
ll n;
int m, k;
int res[MAX];
 
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m >> k;
  mat a(m,0); for(int i=0;i<m;i++)for(int j=0;j<m;j++)a[i][j] = 1;
  
  for(int i = 0; i < k; i++){
    string s; cin >> s;
    int x = (s[0] <= 'Z' ? s[0]-'A' + 26 : s[0] - 'a');
    int y = (s[1] <= 'Z' ? s[1]-'A' + 26 : s[1] - 'a');
    a[x][y] = 0; 
  }
 
  if(n==1){
    cout<<m<<'\n'; return 0;
  }
  a = bpow(a,n-1);
  mat b(m,1); 
  b = b*a;
  int ans = 0;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < m; j++)
      ans = ( ans + b[i][j] ) % MOD;
 
  cout << ans << '\n';
}