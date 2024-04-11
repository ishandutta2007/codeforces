#include <bits/stdc++.h>

using namespace std;

const int N = 505;
int conf[N][N];

void ini(){
  for(int i = 0;i<N;i++)
    for(int j = 0;j<N;j++)
      conf[i][j] = 3;
}

void dfs(int i,int j){
  conf[i][j]+=1;
  if(conf[i][j]>=3)return;
  dfs(i,j+1);
  dfs(i+1,j);
  dfs(i-1,j);
  dfs(i,j-1);
}

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(0);
  cout.tie(0);
  ini();
  int n,m;
  cin >> n >> m;
  char c;
  for(int i = 1;i<=n;i++){
    for(int j = 1;j<=m;j++){
      cin >> c;
      conf[i][j] = (c=='X')+1;
    }
  }
  int c1,c2,e1,e2;
  cin >> c1 >> c2 >> e1 >> e2;
  conf[c1][c2] = 1;
  dfs(c1,c2);
  if(conf[e1][e2]>=3)
    puts("YES");
  else
    puts("NO"); 
  return 0;
}