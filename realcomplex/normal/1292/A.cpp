#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
int a[2][N];

int main(){
  fastIO;
  int n, q;
  cin >> n >> q;
  int r, c;
  int bad = 0;
  for(int i = 0 ; i < q; i ++ ){
    cin >> r >> c;
    --r;
    if(a[r][c] == 1 && a[1-r][c] == 1){
      bad -- ;
    }
    if(r == 0){
      if(a[r][c] == 1 && a[r+1][c+1] == 1){
        bad --;
      }
      if(a[r][c] == 1 && a[r+1][c-1] == 1){
        bad -- ;
      }
    }
    else{
      if(a[r][c] == 1 && a[r-1][c+1] == 1){
        bad -- ;
      }
      if(a[r][c] == 1 && a[r-1][c-1] == 1){
        bad -- ;
      }
    }
    a[r][c] = 1 - a[r][c];
    if(a[r][c] == 1 && a[1-r][c] == 1){
      bad ++ ;
    }
    if(r == 0){
      if(a[r][c] == 1 && a[r+1][c+1] == 1){
        bad ++;
      }
      if(a[r][c] == 1 && a[r+1][c-1] == 1){
        bad ++ ;
      }
    }
    else{
      if(a[r][c] == 1 && a[r-1][c+1] == 1){
        bad ++ ;
      }
      if(a[r][c] == 1 && a[r-1][c-1] == 1){
        bad ++ ;
      }
    }
    if(bad > 0)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}