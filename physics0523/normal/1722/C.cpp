#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    map<string,int> mp;
    vector<vector<string>> game(3,vector<string>(n));
    for(int i=0;i<3;i++){
      for(int j=0;j<n;j++){
        cin >> game[i][j];
        mp[game[i][j]]++;
      }
    }
    vector<int> res(3,0);
    vector<int> pt={5,3,1,0};
    for(int i=0;i<3;i++){
      for(int j=0;j<n;j++){
        res[i]+=pt[mp[game[i][j]]];
      }
    }
    cout << res[0] << " " << res[1] << " " << res[2] << "\n";
  }
  return 0;
}