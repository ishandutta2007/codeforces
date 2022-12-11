#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))
#define all(a) a.begin(), a.end()
#define ones(a) __builtin_popcount(a)

int main(){
  fastIO;
  int n,k;
  cin >> n >> k;
  if(k % 2 == 0){
    cout << "YES\n";
    char ans[4][n];
    for(int i = 0;i < 4;i ++ )
      for(int j = 0;j < n;j ++ )
        ans[i][j] = '.';
    for(int i = 1;i <= k/2; i ++ ){
      ans[1][i] = '#';
      ans[2][i] = '#';
    }
    for(int i = 0;i < 4;i ++ ){
      for(int j = 0;j < n;j ++ ){
        cout << ans[i][j];
      }
      cout << "\n";
    }
    return 0;
  }
  else{
    if(k <= n-2){
      char ans[4][n];
      for(int i = 0;i < 4;i ++ ){
        for(int j = 0;j < n;j ++ ){
          ans[i][j] = '.';
        }
      }
      int l = n-k;
      l/=2;
      for(int j = l;j < n && k > 0;j ++ ){
        ans[1][j] = '#';
        k -- ;
      }
      cout << "YES\n";
      for(int i = 0;i < 4;i ++ ){
        for(int j = 0;j < n;j ++ ){
          cout << ans[i][j];
        }
        cout << "\n";
      }
    }
    else{
      cout << "YES\n";
      char ans[4][n];
      for(int i = 0;i < 4; i ++ ){
        for(int j = 0;j < n; j ++ ){
          ans[i][j] = '.';
        }
      }
      for(int j = 1;j < n-1;j ++ )
        ans[1][j] = '#';
      int lf = k-(n - 2);
      lf/=2;
      for(int i = 0;i < lf ;i ++ ){
        ans[2][i+1] = '#';
        ans[2][n-i-2] = '#';
      }
      for(int i = 0;i < 4;i ++ ){
        for(int j = 0;j < n;j ++ ){
          cout << ans[i][j];
        }
        cout << "\n";
      }
    }
  }
  return 0;
}