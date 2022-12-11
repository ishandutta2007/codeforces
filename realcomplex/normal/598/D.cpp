#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int conf[N][N];
int wal[N][N];
int cnt[N*N];
int p = 1;
void ini(){
  for(int i = 0;i<N;i++)
    for(int j = 0;j<N;j++)
      conf[i][j] = -1,wal[i][j] = 0;
}
int l;
void dfs(int x,int y){
  conf[x][y] = p;
  if(conf[x+1][y]==INT_MAX)
    dfs(x+1,y);
  else if(conf[x+1][y]==-1 /*&& wal[x+1][y]!=p*/){
    wal[x+1][y] = p;
    l++;
  }
  if(conf[x-1][y]==INT_MAX)
    dfs(x-1,y);
  else if(conf[x-1][y]==-1 /*&& wal[x-1][y]!=p*/){
    wal[x-1][y] = p;
    l++;
  }
  if(conf[x][y+1]==INT_MAX)
    dfs(x,y+1);
  else if(conf[x][y+1]==-1 /*&& wal[x][y+1]!=p*/){
    wal[x][y+1] = p;
    l++;
  }
  if(conf[x][y-1]==INT_MAX)
    dfs(x,y-1);
  else if(conf[x][y-1]==-1 /*&&wal[x][y-1]!=p*/){
    wal[x][y-1] = p;
    l++;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ini();
  int n,m,k;
  cin >> n >> m >> k;
  char s;
  for(int i = 1;i<=n;i++){
    for(int j = 1;j<=m;j++){
      cin >> s;
      if(s=='.')conf[i][j]=INT_MAX;
    }
  }
  for(int i = 1;i<=n;i++){
    for(int j = 1;j<=m;j++){
      if(conf[i][j]!=INT_MAX)continue;
      p++;
      l = 0;
      dfs(i,j);
      cnt[p]=l;
    }
  }
  int l,r;
  for(int i = 0;i<k;i++){
    cin >> l >> r;
    cout << cnt[conf[l][r]] << "\n";
  }
  return 0;
}