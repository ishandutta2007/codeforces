#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>> res={
    {0,1,2},
    {1,0,2},
    {1,2,0},
    {2,1,0},
    {2,0,1},
    {0,2,1}
  };
  int n,x;
  cin >> n >> x;
  cout << res[n%6][x] << '\n';
  return 0;
}