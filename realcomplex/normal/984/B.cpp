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

const int N = 105;
int xy[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int sk[N][N];
int bomb[N][N];

int main(){
  fastIO;
  int n,m;
  cin >> n >> m;
  char x;
  for(int i = 1;i <= n;i ++ ){
    for(int j = 1;j <= m;j ++ ){
      cin >> x;
      if(x == '*')
        bomb[i][j] = 1, sk[i][j] = -1;
      else{
        if(x == '.')
          sk[i][j] = 0;
        else
          sk[i][j] = x-48;
      }
    }
  }
  int check;
  for(int i = 1;i <= n;i ++ ){
    for(int j = 1;j <= m;j ++ ){
      if(sk[i][j] == -1)
        continue;
      check = 0;
      for(int k = 0;k < 8; k ++ )
        check += bomb[i+xy[k][0]][j+xy[k][1]];
      if(check != sk[i][j]){
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
  return 0;
}