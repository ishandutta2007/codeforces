#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<vector<char>> gr;
vector<vector<bool>> hh;

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  vector<char> ff;
  vector<bool> hi;
  for(int i = 0 ; i <= m + 1 ; i ++ ){
    ff.push_back('#');
    hi.push_back(false);
  }
  for(int i = 0 ; i <= n + 1; i ++ ){
    gr.push_back(ff);
    hh.push_back(hi);
  }
  hh[n][m] = true;
  for(int i = 1 ; i <= n; i ++ ){
    for(int j = 1 ; j <= m; j ++ ){
      cin >> gr[i][j];
    }
  }
  for(int i = n; i >= 1; i -- ){
    for(int j = m; j >= 1; j -- ){
      if(i == n && j == m) continue;
      if(gr[i][j] == '.')hh[i][j] = (hh[i + 1][j] || hh[i][j + 1]);
    }
  }
  if(!hh[1][1]){
    cout << 0;
    return 0;
  }
  vector<pii> p1, p2;
  int ci = 1, cj = 1;
  while(ci != n || cj != m){
    p1.push_back(mp(ci, cj));
    if(hh[ci + 1][cj] == true){
      ci ++ ;
    }
    else{
      cj ++ ;
    }
  }
  ci = 1;
  cj = 1;
  while(ci != n || cj != m){
    p2.push_back(mp(ci,cj));
    if(hh[ci][cj + 1] == true){
      cj ++ ;
    }
    else{
      ci ++ ;
    }
  }
  for(int i = 1; i < p1.size(); i ++ ){
    if(p1[i] == p2[i]){
      cout << 1;
      return 0;
    }
  }
  cout << 2;
  return 0;
}