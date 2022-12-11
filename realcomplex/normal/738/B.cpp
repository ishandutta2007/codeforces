#pragma optimize ("O3")
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
#define len(x) ((int)(x).size())

const int N = 1005;
int cf[N][N];
int n,m;

int up(){
  int x = 0, y = 0;
  int rz = 0;
  for(int i = 1;i <= m; i ++ ){
    x = 0, y = 0;
    for(int j = 1;j <= n;j ++ ){
      y += cf[j][i];
    }
    for(int j = 1;j <= n;j ++ ){
      y -= cf[j][i];
      x += cf[j][i];
      if(cf[j][i] == 0){
        if(x >= 1)
          rz++;
        if(y >= 1)
          rz++;
      }
    }
  }
  return rz;
}

int down(){
  int x = 0 ,y = 0;
  int rz = 0;
  for(int i = 1;i <= n;i ++ ){
    x = 0,y = 0;
    for(int j = 1;j <= m ; j ++ ){
      y += cf[i][j];
    }
    for(int j = 1;j <= m; j ++ ){
      x += cf[i][j];
      y -= cf[i][j];
      if(cf[i][j] == 0){
        if(x >= 1)
          rz ++ ;
        if(y >= 1)
          rz ++ ;
      }
    }
  }
  return rz;
}

int main(){
  fastIO;
  cin >> n >> m;
  for(int i = 1;i <= n; i ++ )
    for(int j = 1; j <= m; j ++)
      cin >> cf[i][j];
  cout << up() + down();
  return 0;
}