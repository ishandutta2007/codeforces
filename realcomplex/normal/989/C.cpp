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
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  char ans[48][50];
  for(int i = 0;i < 12; i ++ )
    for(int j = 0;j < 50;j ++ )
      ans[i][j] = 'A';
  for(int i = 12;i < 24; i ++ )
    for(int j = 0;j < 50;j ++ )
      ans[i][j] = 'B';
  for(int i = 24;i < 36; i ++ )
    for(int j = 0;j < 50;j ++ )
      ans[i][j] = 'C';    
  for(int i = 36;i < 48; i ++ )
    for(int j = 0;j < 50;j ++ )
      ans[i][j] = 'D';
  a --, b -- , c --, d -- ;
  for(int i = 0;i < 12;i += 2){
    for(int j = 0;j < 50;j += 2){
      if(c > 0)
        ans[i][j] = 'C', c -- ;
    }
  }
  for(int i = 12;i < 24;i += 2){
    for(int j = 0;j < 50;j += 2){
      if(d > 0)
        ans[i][j] = 'D', d -- ;
    }
  }
  for(int i = 24;i < 36;i += 2){
    for(int j = 0;j < 50;j += 2){
      if(a > 0)
        ans[i][j] = 'A', a -- ;
    }
  }
  for(int i = 36;i < 48;i += 2){
    for(int j = 0;j < 50;j += 2){
      if(b > 0)
        ans[i][j] = 'B', b -- ;
    }
  }
  cout << "48 50\n";
  for(int i = 0;i < 48;i ++ ){
    for(int j = 0;j < 50;j ++ ){
      cout << ans[i][j];
    }
    cout << "\n";
  }
  return 0;
}