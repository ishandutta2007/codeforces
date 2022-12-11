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

bool check(char v1,char v2, char v3){
  int x = (v1 == 'x') + (v2 == 'x') + (v3 == 'x');
  if(x != 2)
    return false;
  if(v1 == '.' or v2 == '.' or v3 == '.')
    return true;
  return false;
}

void Output(){
  cout << "YES\n";
  exit(0);
}

int main(){
  fastIO;
  char yi[4][4];
  for(int i= 0;i < 4;i ++ ){
    for(int j = 0;j < 4; j ++ ){
      cin >> yi[i][j];
    }
  }
  for(int i = 0;i < 2;i ++ ){
    for(int j = 0;j < 2;j ++ ){
      if(check(yi[i][j],yi[i+1][j+1],yi[i+2][j+2])){
        Output(); 
      }
    }
  }
  for(int i = 0;i < 4;i ++ ){
    for(int j = 0;j < 2;j ++ ){
      if(check(yi[i][j], yi[i][j + 1], yi[i][j + 2])){
        Output();
      }
    }
  }
  for(int i = 0;i < 2; i ++ ){
    for(int j = 0;j < 4;j ++ ){
      if(check(yi[i][j], yi[i + 1][j], yi[i + 2][j])){
        Output();
      }
    }
  }
  for(int i = 2;i < 4;i ++ ){
    for(int j = 0;j < 2;j ++ ){
      if(check(yi[i][j],yi[i - 1][j+1],yi[i - 2][j + 2])){
        Output();
      }
    }
  }
  cout << "NO\n";
  return 0;
}