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
    int ma=0;
    for(auto &nx : mp){
      ma=max(ma,nx.second);
    }
    int oth=n-ma;
    cout << max(n%2,ma-oth) << '\n';
  }
  return 0;
}