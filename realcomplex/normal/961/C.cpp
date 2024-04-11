#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

int main(){
  //fastIO;
  int n;
  cin >> n;
  char fl[4][n][n];
  int rz = 0;
  for(int i = 0;i < 4; i++ ){
    for(int j = 0;j < n;j ++ ){
      for(int x = 0; x < n; x ++ ){
        cin >> fl[i][j][x];
      }
    }
  }
  int merged[n * 2][n * 2];
  int p[4];
  for(int i = 0;i < 4;i ++ )
    p[i] = i;
  int ans = 10000009;
  int v1,v2;
  do{
    for(int i = 0; i < n;i ++ ){
      for(int j = 0;j < n;j ++ ){
        merged[i][j] = fl[p[0]][i][j];
      }
    }
    for(int i = 0;i < n;i ++ ){
      for(int j = 0;j < n;j ++ ){
        merged[i + n][j] = fl[p[1]][i][j];
      }
    }
    for(int i = 0;i < n;i ++ ){
      for(int j = 0;j < n;j ++ ){
        merged[i][j + n] = fl[p[2]][i][j];
      }
    }
    for(int i = 0;i < n;i ++ ){
      for(int j = 0;j < n;j ++ ){
        merged[i + n][j + n] = fl[p[3]][i][j];
      }
    }
    v1 = 0,v2 = 0;
    for(int i = 0;i < n * 2;i ++ ){
      for(int j = 0;j < n * 2;j ++ ){
        if(i % 2 == j % 2){
          if(merged[i][j] == '0')
            v1 ++ ;
          else
            v2 ++ ;
        }
        else{
          if(merged[i][j] == '1')
            v1 ++;
          else
            v2 ++ ;
        }
      }
    }
    v1 = min(v1, v2);
    ans = min(ans, v1);
  }while(next_permutation(p, p + 4));
  cout << ans;
  return 0;
}