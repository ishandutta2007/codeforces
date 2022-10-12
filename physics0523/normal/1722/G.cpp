#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> prefix={
    {2,1,3,0},
    {2,0,4,5,3},
    {4,1,2,12,3,8},
    {2,1,3}
  };

  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    for(int i=0;i<prefix[n%4].size();i++){
      if(i){cout << " ";}
      cout << prefix[n%4][i];
    }
    int rem=n-prefix[n%4].size();
    for(int i=0;i<rem;i++){
      cout << " " << 100+i;
    }
    cout << "\n";
  }
  return 0;
}