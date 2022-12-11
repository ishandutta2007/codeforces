#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
int ni[N][N];
int nj[N][N];
char sol[N][N];

int main(){
  fastIO;
  for(int i = 0 ; i < N ; i ++ ) for(int j = 0 ; j < N ; j ++ ){
    sol[i][j] = '#';
  }
  int n;
  cin >> n;
  int x, y;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= n; j ++ ){
      cin >> ni[i][j] >> nj[i][j];
    }
  }
  int ii, jj;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= n; j ++ ){
      if(ni[i][j] == i && nj[i][j] == j){
        queue<pii> qq;
        qq.push(mp(i,j));
        sol[i][j] = 'X';
        while(!qq.empty()){
          ii = qq.front().fi;
          jj = qq.front().se;
          qq.pop();
          if(sol[ii+1][jj] == '#' && ni[ii+1][jj] == i && nj[ii+1][jj] == j){
            sol[ii + 1][jj] = 'U';
            qq.push(mp(ii + 1, jj));
          }
          if(sol[ii-1][jj] == '#' && ni[ii-1][jj] == i && nj[ii-1][jj] == j){
            sol[ii - 1][jj] = 'D';
            qq.push(mp(ii - 1, jj));
          }
          if(sol[ii][jj+1] == '#' && ni[ii][jj+1] == i && nj[ii][jj+1] == j){
            sol[ii][jj+1] = 'L';
            qq.push(mp(ii, jj+1));
          }
          if(sol[ii][jj-1] == '#' && ni[ii][jj-1] == i && nj[ii][jj-1] == j){
            sol[ii][jj-1] = 'R';
            qq.push(mp(ii, jj-1));
          }
        }
      }
    }
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= n; j ++ ){
      if(ni[i][j] != -1 && sol[i][j] == '#'){
        cout << "INVALID\n";
        return 0;
      }
    }
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= n; j ++ ){
      if(ni[i][j] == -1 && sol[i][j] == '#'){
        queue<pii> qq;
        qq.push(mp(i,j));
        while(!qq.empty()){
          ii = qq.front().fi;
          jj = qq.front().se;
          qq.pop();
          if(sol[ii+1][jj] == '#' && ni[ii+1][jj] == -1){
            sol[ii + 1][jj] = 'U';
            if(ii == i && jj == j){
              sol[i][j] = 'D';
            }
            qq.push(mp(ii + 1, jj));
          }
          if(sol[ii-1][jj] == '#' && ni[ii-1][jj] == -1){
            sol[ii - 1][jj] = 'D';
            if(ii == i && jj == j){
              sol[i][j] = 'U';
            }
            qq.push(mp(ii - 1, jj));
          }
          if(sol[ii][jj+1] == '#' && ni[ii][jj+1] == -1){
            sol[ii][jj+1] = 'L';
            if(ii == i && jj == j){
              sol[i][j] = 'R';
            }
            qq.push(mp(ii, jj+1));
          }
          if(sol[ii][jj-1] == '#' && ni[ii][jj-1] == -1){
            sol[ii][jj-1] = 'R';
            if(ii == i && jj == j){
              sol[i][j] = 'L';
            }
            qq.push(mp(ii, jj-1));
          }
        }
        if(sol[i][j] == '#'){
          cout << "INVALID\n";
          return 0;
        }
      }
    }
  }
  cout << "VALID\n";
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= n; j ++ ){
      cout << sol[i][j];
    }
    cout << "\n";
  }
  return 0; 
}