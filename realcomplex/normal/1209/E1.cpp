#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 105;
int a[N][N];
int ch[N][N];

int n, m;

int calc(){
  int res = 0;
  int cur;
  for(int i = 0 ; i < n; i ++ ){
    cur = 0;
    for(int j = 0 ; j < m ; j ++ )
      cur = max(cur, ch[i][j]);
    res += cur;
  }
  return res;
}

void solve(){
  cin >> n >> m;
  int f = 0;
  for(int i = 0 ; i < n; i ++ ){
    for(int j = 0 ; j < m ; j ++ ){
      cin >> a[i][j];
      ch[i][j] = a[i][j];
    }
  }
  f = calc();
  int g;
  vector<int> tt;
  int ii, jj;
  for(int z = 0; z < 10; z ++ ){
    for(int i = 0 ; i < m ; i ++ )
      tt.push_back(i);
    for(int i = 0 ; i < 2 * m ; i ++ ){
      ii = rnd() % m + m;
      jj = rnd() % m + m;
      ii %= m;
      jj %= m;
      swap(tt[ii], tt[jj]);
    }
    for(int i = 0 ; i < m ; i ++ ){
      g = 1;
      for(int j = 0 ; j < n ; j ++ ){
        for(int x = 0 ; x < n ; x ++ ){
          for(int y = 0 ;y  < m ; y ++ ){
            if(y == tt[i])
              ch[(x+g)%n][y] = a[x][y];
            else
              ch[x][y] = a[x][y];
          }
        }
        if(calc() > f){
          f = calc();
          for(int x = 0 ; x < n; x ++ ){
            for(int y = 0 ;y < m ; y ++ ){
              a[x][y] = ch[x][y];
            }
          }
          g = 1;
        }
        else{
          g ++ ;
        }
      }
    }
  }
  cout << f << "\n";
}

int main(){ 
  fastIO;
  int testc;
  cin >> testc;
  for(int i = 1; i <= testc; i ++ ){
    solve();
  }
  return 0;
}