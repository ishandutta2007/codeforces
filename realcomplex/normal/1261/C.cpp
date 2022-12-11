#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int dir[8][2] = {{-1,0},{1,0},{0,-1},{0,+1},{-1,-1},{-1,+1},{+1,-1},{+1,+1}};

vector<vector<int>> conf;
vector<vector<int>> init;
vector<vector<int>> dd;

int n, m;

bool check(int low){
  if(low==0)return true;
  for(int i = 0 ; i < n + 2; i ++ )
    for(int j = 0 ; j < m + 2; j ++ )
      dd[i][j] = (int)1e9;
  queue<pii> ff;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      if(conf[i][j] > low){
        ff.push(mp(i,j));
        dd[i][j] = 0;
      }
    }
  }
  int ii, jj;
  int ni, nj;
  while(!ff.empty()){
    ii = ff.front().fi;
    jj = ff.front().se;
    ff.pop();
    for(int x = 0; x < 8 ; x ++ ){
      ni = ii + dir[x][0];
      nj = jj + dir[x][1];
      if(ni >= 1 && ni <= n && nj >= 1 && nj <= m){
        if(dd[ni][nj] == (int)1e9){
          ff.push(mp(ni,nj));
          dd[ni][nj] = dd[ii][jj] + 1;
        }
      }
    }
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      if(dd[i][j] <= low && init[i][j] == 0){
        return false;
      }
      if(dd[i][j] > low && init[i][j] == (int)1e9){
        return false;
      }
    }
  }
  return true;
}

int main(){
  fastIO;
  cin >> n >> m;
  conf.resize(n + 2);
  dd.resize(n + 2);
  for(int i = 0 ; i < n + 2; i ++ ){
    conf[i].resize(m+2);
    dd[i].resize(m+2);
  }
  char f;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      cin >> f;
      if(f=='X')
        conf[i][j] = (int)1e9;
    }
  }
  init = conf;
  queue<pii> st;
  for(int i = 0 ; i < n + 2; i ++ ){
    for(int j = 0 ; j < m + 2; j ++ ){
      if(conf[i][j] == 0){
        st.push(mp(i,j));
      }
    }
  }
  int ii, jj;
  while(!st.empty()){
    ii = st.front().fi;
    jj = st.front().se;
    st.pop();
    for(int q = 0; q < 8; q ++ ){
      if(ii + dir[q][0] >= 1 && ii + dir[q][0] <= n && jj + dir[q][1] >= 1 && jj + dir[q][1] <= m){
        if(conf[ii + dir[q][0]][jj + dir[q][1]] == (int)1e9){
          conf[ii + dir[q][0]][jj + dir[q][1]] = conf[ii][jj] + 1;
          st.push(mp(ii + dir[q][0], jj + dir[q][1]));
        }
      }
    }
  }
  int mx = 0;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m; j ++ ){
      if(conf[i][j] > mx)
        mx = conf[i][j];
    }
  }
  int l = 0, r = mx + 1;
  int md;
  while(l + 1 < r){
    md = (l + r) / 2;
    if(check(md))
      l = md;
    else
      r = md;
  }
  cout << l << "\n";
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      if(conf[i][j] > l)
        cout << "X";
      else cout << ".";
    }
    cout << "\n";
  }
  return 0;
}