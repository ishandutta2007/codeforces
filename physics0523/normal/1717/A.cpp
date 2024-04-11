// Sooo hard for D2A...
// I spent 8 min for this task

#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<pair<int,int>> ab={
    {1,1},
    {1,2},
    {1,3},
    {2,1},
    {3,1}
  };

  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,res=0;
    cin >> n;
    for(auto &nx : ab){
      res+=n/(max(nx.first,nx.second));
    }
    cout << res << "\n";
  }
  return 0;
}