#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 55;
char conf[N][N];

int dir[4][2] = {{-1,0},{+1,0},{0,-1},{0,+1}};

void solve(){
  int n, m;
  cin >> n >> m;
  for(int i = 0 ; i <= n + 1; i ++ ){
    for(int j = 0 ; j <= m + 1; j ++ ){
      conf[i][j]='#';
    }
  }
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++ ){
      cin >> conf[i][j];
    }
  }
  int ni, nj;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      if(conf[i][j] == 'B'){
        for(int t = 0; t < 4; t ++ ){
          ni = i + dir[t][0];
          nj = j + dir[t][1];
          if(conf[ni][nj] == 'B') continue;
          if(conf[ni][nj] == 'G'){
            cout << "No\n";
            return;
          }
          conf[ni][nj] = '#';
        }
      }
    }
  }
  queue<pii> ff;
  int ii, jj;
  if(conf[n][m] != '#'){
    ff.push(mp(n,m));
    conf[n][m] = '!';
  }
  while(!ff.empty()){
    ii = ff.front().fi;
    jj = ff.front().se;
    ff.pop();
    for(int t = 0; t < 4; t ++ ){
      ni = ii + dir[t][0];
      nj = jj + dir[t][1];
      if(conf[ni][nj] != '#' && conf[ni][nj] != '!'){
        conf[ni][nj] = '!';
        ff.push(mp(ni, nj));
      }
    }
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m; j ++ ){
      if(conf[i][j] == 'G'){
        cout << "No\n";
        return ;
      }
    }
  }
  cout << "Yes\n";
}


int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t =0 ;t < tc; t ++ )
    solve();
  return 0;
}