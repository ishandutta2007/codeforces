#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  vector<vector<int>> mem(k,vector<int>(2,0));
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    mem[i%k][v-1]++;
  }
  int res=0;
  for(int i=0;i<k;i++){
    res+=min(mem[i][0],mem[i][1]);
  }
  cout << res << '\n';
  return 0;
}