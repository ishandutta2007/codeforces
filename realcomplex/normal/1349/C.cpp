#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
int dir[4][2] = {{-1,0},{+1,0},{0,-1},{0,+1}};
int d[N][N];
char conf[N][N];

void solve(){
  int n, m, q;
  cin >> n >> m >> q;
  for(int i = 0 ; i <= n + 1; i ++ ){
    for(int j = 0 ; j <= m + 1; j ++ ){
      d[i][j]=(int)1e9;
      conf[i][j]='#';
    }
  }
  int ni, nj;
  queue<pii> bf;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m; j ++ ){
      cin >> conf[i][j];
    }
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m; j ++ ){
      for(int t = 0; t < 4; t ++ ){
        ni = i + dir[t][0];
        nj = j + dir[t][1];
        if(conf[i][j] == conf[ni][nj]){
          d[i][j]=0;
        }
      }
      if(d[i][j]==0)
        bf.push(mp(i,j));
    }
  }
  int xi, xj;
  while(!bf.empty()){
    ni = bf.front().fi;
    nj = bf.front().se;
    bf.pop();
    for(int t = 0; t < 4; t ++ ){
      xi = ni + dir[t][0];
      xj = nj + dir[t][1];
      if(conf[ni][nj] != conf[xi][xj] && conf[xi][xj] != '#' && d[xi][xj] == (int)1e9){
        d[xi][xj]=d[ni][nj]+1;
        bf.push(mp(xi,xj));
      }
    }
  }
  int ii, jj;
  ll p;
  int xr;
  for(int i = 0 ; i < q; i ++ ){
    cin >> ii >> jj >> p;
    if(d[ii][jj]==(int)1e9)
      cout << conf[ii][jj] << "\n";
    else{
      if(p <= d[ii][jj]){
        cout << conf[ii][jj] << "\n";
      }
      else{
        xr = conf[ii][jj] - '0';
        xr ^= ((p-d[ii][jj])&1);
        cout << xr << "\n";
      }
    }
  }
}

int main(){
  fastIO;
  solve();
  return 0;
}