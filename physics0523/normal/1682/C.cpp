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
    map<int,int> mp;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      mp[v]++;
    }
    vector<int> bk(3,0);
    for(auto &nx : mp){
      bk[min(2,nx.second)]++;
    }
    int t=bk[2]*2+bk[1];
    cout << (t+1)/2 << '\n';
  }
  return 0;
}