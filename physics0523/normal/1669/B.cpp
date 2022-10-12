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
    int res=-1;
    for(auto &nx : mp){
      if(nx.second>=3){res=nx.first;break;}
    }
    cout << res << '\n';
  }
  return 0;
}