#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> gg;
map<vector<int>, int> ids;

void dfs(vector<int> cn, int sum, int idx){
  if(sum == 8){
    ids[cn] = gg.size();
    gg.push_back(cn);
    return;
  }
  cn[idx] ++ ;
  dfs(cn, sum + 1, idx);
  cn[idx] -- ;
  if(idx + 1 < 5)
    dfs(cn, sum, idx + 1);
}


const int N = 495;
vector<pii> T[N][N];
int deg[N][N];
int ans[N][N];

int main(){
  fastIO;
  dfs({0,0,0,0,0}, 0, 0);
  queue<pii> bf;
  int m;
  vector<int> A, B;
  int ni, nj;
  for(int i = 0 ; i < N ; i ++ ){
    for(int j = 0 ; j < N ; j ++ ){
      if(i + j == 0) continue;
      ans[i][j] = -1;
      if(i == 0){
        ans[i][j] = 1;
        bf.push(mp(i,j));
      }
      else if(j == 0){
        ans[i][j] = 0;
        bf.push(mp(i,j));
      }
      else{
        A = gg[i];
        B = gg[j];
        for(int p = 1; p < 5; p ++ ){
          for(int q = 1; q < 5; q ++ ){
            if(A[p] == 0 || B[q] == 0) continue; 
            m = (p + q) % 5;
            A[m] ++ ;
            A[p] -- ;
            nj = ids[A];
            ni = j;
            deg[i][j] ++ ;
            T[ni][nj].push_back(mp(i,j));
            A[m] -- ;
            A[p] ++ ;
          }
        }
      }
    }
  }
  int ci, cj;
  while(!bf.empty()){
    ci = bf.front().fi;
    cj = bf.front().se;
    bf.pop();
    for(auto x : T[ci][cj]){
      deg[x.fi][x.se] -- ;
      if(ans[ci][cj] == 0 && ans[x.fi][x.se] == -1) {
        ans[x.fi][x.se] = 1;
        bf.push(x);
      }
      if(deg[x.fi][x.se] == 0 && ans[x.fi][x.se] == -1 && ans[ci][cj] == 1){
        ans[x.fi][x.se] = 0;
        bf.push(x);
      }
    }
  }
  int T;
  cin >> T;
  int f1, f2;
  for(int t = 0 ; t < T; t ++ ){
    vector<int> A(5), B(5);
    int f;
    cin >> f;
    int x;
    for(int i = 0 ; i < 8; i ++ ){
      cin >> x;
      A[x] ++ ;
    }
    for(int i = 0 ; i < 8; i ++ ){
      cin >> x;
      B[x] ++ ;
    }
    f1 = ids[A];
    f2 = ids[B];
    if(f == 0){
      if(ans[f1][f2] == -1) cout << "Deal\n";
      else if(ans[f1][f2] == 1) cout << "Alice\n";
      else cout << "Bob\n";
    }
    else{
      if(ans[f2][f1] == -1) cout << "Deal\n";
      else if(ans[f2][f1] == 0) cout << "Alice\n";
      else cout << "Bob\n";
    }
  }
  return 0;
}