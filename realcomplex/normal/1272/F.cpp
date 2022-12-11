#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const short N = 205;
short dp[N][N][N];
struct L{
  short pi;
  short pj;
  short sig;
};

L las[N][N][N];

struct State{
  short ii;
  short jj;
  short bb;
};


int main(){
  fastIO;
  for(short i = 0 ; i < N ; i ++ ) for(short j = 0 ; j < N ; j ++ )
    for(short x = 0 ; x < N ; x ++ )
      dp[i][j][x] = 5000, las[i][j][x] = {-1,-1,-1};
  string s;
  string t;
  cin >> s >> t;
  short n = s.size();
  short m = t.size();
  short ni, nj, nb;
  dp[0][0][0] = 0;
  queue<State> ff;
  short i, j, x;
  ff.push({0,0,0});
  while(!ff.empty()){
    i = ff.front().ii;
    j = ff.front().jj;
    x = ff.front().bb;
    ff.pop();
    if(x > 0){
      ni = i;
      nj = j;
      if(i < n && s[i] == ')') ni ++ ;
      if(j < m && t[j] == ')') nj ++ ;
      nb = x - 1;
      if(dp[ni][nj][nb] > dp[i][j][x] + 1){
        dp[ni][nj][nb] = dp[i][j][x] + 1;
        ff.push({ni, nj, nb});
        las[ni][nj][nb] = {i, j, 0};
      }
    }
    if(x < 203){
      ni = i;
      nj = j;
      nb = x + 1;
      if(i < n && s[i] == '(') ni ++ ;
      if(j < m && t[j] == '(') nj ++ ;
      if(dp[ni][nj][nb] > dp[i][j][x] + 1){
        dp[ni][nj][nb] = dp[i][j][x] + 1;
        ff.push({ni, nj, nb});
        las[ni][nj][nb] = {i, j, 1};
      }
    }
  }
  ni = n;
  nj = m;
  nb = 0;
  vector<char> res;
  short fi, fj;
  short g = dp[ni][nj][nb];
  for(short i = 0 ; i < g; i ++ ){
    if(las[ni][nj][nb].sig == -1) break;
    if(las[ni][nj][nb].sig == 0){
      fi = las[ni][nj][nb].pi;
      fj = las[ni][nj][nb].pj;
      ni = fi;
      nj = fj;
      nb ++ ;
      res.push_back(')');
    }
    else{
      fi = las[ni][nj][nb].pi;
      fj = las[ni][nj][nb].pj;
      ni = fi;
      nj = fj;
      nb -- ;
      res.push_back('(');
    }
  }
  reverse(res.begin(), res.end());
  for(auto x : res)
    cout << x;
  cout << "\n";
  return 0;
}