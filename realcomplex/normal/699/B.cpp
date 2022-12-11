#include <bits/stdc++.h>

using namespace std;

char conf[1005][1005];
int col[1005],row[1005];
int w = 0;

int main(){
  int n,m;
  cin >> n >> m;
  for(int i = 1;i<=n;i++){
    for(int j = 1;j<=m;j++){
      cin >> conf[i][j];
      if(conf[i][j]=='*')col[i]++,row[j]++,w++;
    }
  }
  int cur = 0;
  for(int i = 1;i<=n;i++){
    for(int j = 1;j<=m;j++){
      cur = col[i]+row[j];
      if(conf[i][j]=='*')cur--;
      if(cur==w){
        cout << "YES\n" << i << " " << j;
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}