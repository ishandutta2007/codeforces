#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair

const int N = 10;
const int inf = (int)1e9;
int a[N][N];

vector<pii> go[3];


pii f[N][N][N * N][3];

struct State{
  int rw;
  int cl;
  int has;
  int sh;
  bool operator< (State F) const {
    return has < F.has;
  }
};

int main(){
  for(int i = 0; i < N; i ++ ){
    for(int j = 0 ; j < N ; j ++ ){
      for(int k = 0 ; k < N * N; k ++ ){
        for(int z = 0; z < 3; z ++ ){
          f[i][j][k][z] = mp(inf, inf);
        }
      }
    }
  }
  int n;
  cin >> n;
  int ni, nj;
  for(int i = 1; i < n; i ++ ){
    go[1].push_back(mp(i,i));
    go[1].push_back(mp(-i,i));
    go[1].push_back(mp(i,-i));
    go[1].push_back(mp(-i,-i));
  }
  go[0] = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
  for(int i = 1; i < n; i ++ ){
    go[2].push_back(mp(0,i));
    go[2].push_back(mp(0,-i));
    go[2].push_back(mp(i,0));
    go[2].push_back(mp(-i,0));
  }
  priority_queue<pair<pii, State>, vector<pair<pii, State>>, greater<pair<pii, State>>> bf;
  State cur;
  for(int i = 0 ; i < n; i ++ ){
    for(int j = 0 ; j < n ; j ++ ){
      cin >> a[i][j];
      a[i][j] -- ;
      if(a[i][j] == 0){
        for(int t = 0;t < 3; t ++ ){
          f[i][j][0][t] = mp(0,0);
          cur = {i, j, 0, t};
          bf.push(mp(mp(0,0),cur));
        }
      }
    }
  }
  int pp;
  State nw;
  pii tt;
  while(!bf.empty()){
    cur = bf.top().se;
    bf.pop();
    if(cur.has == n * n - 1){
      cout << f[cur.rw][cur.cl][cur.has][cur.sh].fi << " " << f[cur.rw][cur.cl][cur.has][cur.sh].se << "\n";
      return 0;
    }
    for(auto q : go[cur.sh]){
      ni = cur.rw + q.fi;
      nj = cur.cl + q.se;
      if(ni < 0 || ni >= n || nj < 0 || nj >= n) 
        continue;
      pp = cur.has;
      if(a[ni][nj] == pp + 1) pp ++ ;
      tt = f[cur.rw][cur.cl][cur.has][cur.sh];
      tt.fi ++ ;
      if(f[ni][nj][pp][cur.sh] > tt){
        f[ni][nj][pp][cur.sh] = tt;
        nw = {ni,nj,pp,cur.sh};
        bf.push(mp(f[ni][nj][pp][cur.sh], nw));
      }
    }
    for(int z = 0;z < 3; z ++ ){
      if(z != cur.sh){
        tt = f[cur.rw][cur.cl][cur.has][cur.sh];
        tt.se ++ ;
        tt.fi ++ ;
        if(f[cur.rw][cur.cl][cur.has][z] > tt){
          f[cur.rw][cur.cl][cur.has][z] = tt;
          nw = cur;
          nw.sh = z;
          bf.push(mp(tt, nw));
        }
      }
    }
  }
  return 0;
}