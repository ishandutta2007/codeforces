#include <bits/stdc++.h>

using namespace std;

int mark[1005];//DIAMETER
int closed[1005];//DIAMETER

int markCol[1005][1005];//[DIAMETER][COLOR]
int closerCol[1005][1005];//[DIAMETER][COLOR]

int main(){
  int n,m;
  cin >> n >> m;
  int l,r;
  for(int i = 0;i<n;i++){
    cin >> l >> r;
    mark[r]++;
    markCol[l][r]++;
  }
  for(int i = 0;i<m;i++){
    cin >> l >> r;
    closed[r]++;
    closerCol[l][r]++;
  }
  int u = 0;
  for(int i = 0;i<1005;i++)
    u+=min(mark[i],closed[i]);
  cout << u << " ";
  int v = 0;
  for(int i = 0;i<1005;i++)
    for(int j = 0;j<1005;j++)
      v += min(markCol[i][j],closerCol[i][j]);
  cout << v << "\n";
  return 0;
}