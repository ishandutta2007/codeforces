#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
char conf[N][N];
bool can[N][N];
int l1[N], r1[N];
int l2[N], r2[N];
bool vis[N][N];
bool e1[N], e2[N];

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      cin >> conf[i][j];
      can[i][j]=true;
      if(conf[i][j] == '.') can[i][j]=false;
    }
  }
  for(int i = 1; i <= n; i ++ ){
    e1[i]=true;
    for(int j = 1; j <= m ; j ++ ){
      if(conf[i][j]=='#')e1[i]=false;
    }
  }
  for(int i = 1; i <= m; i ++ ){
    e2[i]=true;
    for(int j = 1; j <= n; j ++ ){
      if(conf[j][i]=='#')e2[i]=false;
    }
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      if(e1[i] && e2[j])
        can[i][j]=true;
    }
  }
  int tot = 0, cur;
  for(int i = 1; i <= n; i ++ ){
    tot = 0, cur = 0;
    for(int j = 1; j <= m ; j ++ ){
      if(conf[i][j] == '#'){
        cur ++ ;
        if(cur == 1) tot ++ ;
      }
      else{
        cur = 0;
      }
    }
    if(tot > 1){
      cout << "-1\n";
      return 0;
    }
  }
  for(int j = 1; j <= m ; j ++ ){
    tot = 0;
    cur = 0;
    for(int i = 1; i <= n; i ++ ){
      if(conf[i][j] == '#'){
        cur ++ ;
        if(cur == 1) tot ++ ;
      }
      else{
        cur = 0;
      }
    }
    if(tot > 1){
      cout << "-1\n";
      return 0;
    }
  }
  for(int i = 1; i <= n; i ++ ){
    l1[i]=m + 5;
    r1[i]=-1;
    for(int j = 1; j <= m ; j ++ ){
      if(can[i][j]){
        l1[i]=min(l1[i],j);
        r1[i]=max(r1[i],j);
      }
    }
    if(r1[i]==-1){
      cout << "-1\n";
      return 0;
    }
  }
  for(int i = 1; i <= m ; i ++ ){
    l2[i]=n + 5;
    r2[i]=-1;
    for(int j = 1; j <= n; j ++ ){
      if(can[j][i]){
        l2[i]=min(l2[i],j);
        r2[i]=max(r2[i],j);
      }
    }
    if(r2[i]==-1){
      cout << "-1\n";
      return 0;
    }
  }
  int ans = 0;
  int ci, cj;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      if(!vis[i][j] && conf[i][j] == '#'){
        ans ++ ;
        queue<pii> bf;
        bf.push(mp(i,j));
        vis[i][j]=true;
        while(!bf.empty()){
          ci = bf.front().fi;
          cj = bf.front().se;
          bf.pop();
          if(l1[ci] <= cj - 1 && !vis[ci][cj - 1]){
            vis[ci][cj-1]=true;
            bf.push(mp(ci,cj-1));
          }
          
          if(r1[ci] >= cj + 1 && !vis[ci][cj + 1]){
            vis[ci][cj+1]=true;
            bf.push(mp(ci,cj+1));
          }
          if(l2[cj] <= ci - 1 && !vis[ci-1][cj]){
            vis[ci-1][cj]=true;
            bf.push(mp(ci-1,cj));
          }
          if(r2[cj] >= ci + 1 && !vis[ci+1][cj]){
            vis[ci+1][cj]=true;
            bf.push(mp(ci+1,cj));
          }
        }
      }
    }
  }
  cout << ans << "\n";
  return 0;
}