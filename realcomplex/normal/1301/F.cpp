#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1004;
const int K = 41;
int dir[4][2] = {{-1,0},{+1,0},{0,-1},{0,+1}};
int ci[N][N];
int dis[K][N][N];
vector<pii> idx[K];

int n, m;
int k;

void bfs(int col){
  deque<pii> ff;
  for(int j = 1; j <= k ; j ++ )
    dis[col][0][j] = (int)1e5 + 10;
  for(int i = 1 ; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      dis[col][i][j]=(int)1e5 + 10;
    }
  }
  ff.push_back(mp(0, col));
  dis[col][0][col]=0;
  int ii, jj;
  int ni, nj;
  int cost;
  while(!ff.empty()){
    ii = ff.front().fi;
    jj = ff.front().se;
    ff.pop_front();
    if(ii == 0){
      for(auto x : idx[jj]){
        if(dis[col][x.fi][x.se]>dis[col][ii][jj]){
          dis[col][x.fi][x.se]=dis[col][ii][jj];
          ff.push_front(mp(x.fi, x.se));
        }
      }
    }
    else{
      if(dis[col][0][ci[ii][jj]]>dis[col][ii][jj]+1){
        dis[col][0][ci[ii][jj]]=dis[col][ii][jj]+1;
        ff.push_back(mp(0, ci[ii][jj]));
      }
      for(int i = 0 ; i < 4; i ++ ){
        ni = ii + dir[i][0];
        nj = jj + dir[i][1];
        if(ci[ni][nj]==0)continue;
        if(dis[col][ni][nj]>dis[col][ii][jj]+1){
          dis[col][ni][nj]=dis[col][ii][jj]+1;
          ff.push_back(mp(ni,nj));
        }
      }
    }
  }
}

int main(){
  fastIO;
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      cin >> ci[i][j];
      idx[ci[i][j]].push_back(mp(i,j));
    }
  }
  for(int i = 1; i <= k ; i ++ ) bfs(i);
  int q;
  cin >> q;
  int li,lj,ri,rj;
  int ans;
  for(int i = 0 ; i < q; i ++ ){
    cin >> li >> lj >> ri >> rj;
    ans = abs(rj-lj)+abs(ri-li);
    for(int a = 1; a <= k ;a ++ )
      ans = min(ans, dis[a][li][lj]+dis[a][ri][rj]+1);
    cout << ans << "\n";
  }
  return 0;
}