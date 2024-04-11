#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, short> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const short N = 81;
int len[N][N];
const int W = (int)1e7;
vector<short> ww[W];
int cnt;

short k;
short n;
void construct(){
  ww[cnt++] = {1};
  if(k == 4 || n <= 8){
    for(short i = 2; i <= n; i ++ ){
      ww[cnt++] = {1,i};
    }
  }
  if(k == 6 || n <= 8){
    for(short i = 2; i <= n; i ++ ){
      for(short j = i+1; j <= n; j ++ ){
        ww[cnt++] = {1,i,j};
      }
    }
  }
  if(k == 8 || n <= 8){
    for(short i = 2; i <= n; i ++ ){
      for(short j = i + 1; j <= n; j ++ ){
        for(short k = j + 1; k <= n; k ++ ){
          ww[cnt++]={1,i,j,k};
        }
      }
    }
  }
  if(k == 10 || n <= 8){
    for(short i = 2; i <= n; i ++ ){
      for(short j = i + 1; j <= n; j ++ ){
        for(short k = j + 1; k <= n; k ++ ){
          for(short p = k + 1; p <= n; p ++ ){
            ww[cnt++] = {1,i,j,k,p};
          }
        }
      }
    }
  }
}

bool is[N];
int dis[2][N];
int cc[N][N];
vector<pii> good[N][N];

int main(){
  fastIO;
  cin >> n >> k;
  construct();
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= n; j ++ ){
      cin >> len[i][j];
    }
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= n; j ++ ){
      for(int x = 1; x <= n; x ++ ){
        good[i][j].push_back(mp(len[i][x] + len[x][j], x));
      }
      sort(good[i][j].begin(), good[i][j].end());
      while(good[i][j].size() >= 6)
        good[i][j].pop_back();
    }
  }
  int res = (int)1e9 + 5;
  for(int i = 0 ; i < cnt; i++ ){
    for(auto x : ww[i]){
      is[x]=true;
      dis[0][x]=(int)1e9 + 5;
      dis[1][x]=(int)1e9 + 5;
    }
    dis[0][1]=0;
    for(auto x : ww[i])
      for(auto y : ww[i])
        cc[x][y] = (int)1e9 + 5;
    for(auto x : ww[i])
      for(auto y : ww[i])
        for(auto p : good[x][y])
          if(!is[p.se])
            cc[x][y]=min(cc[x][y],p.fi);
    for(int st = 0 ; st < k/2; st ++ ){
      for(auto x : ww[i])
        for(auto y : ww[i]){
          dis[1][y]=min(dis[1][y],dis[0][x]+cc[x][y]);
        }
      for(auto x : ww[i]){
        swap(dis[0][x], dis[1][x]);
        dis[1][x] = (int)1e9 + 5;
      }
    }
    res = min(res,dis[0][1]);
    for(auto x : ww[i])
      is[x]=false;
  }
  cout << res << "\n";
  return 0;
}