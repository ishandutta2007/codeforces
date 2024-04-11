#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    vector<pair<int,int>> p(3);
    for(int i=0;i<3;i++){
      cin >> p[i].second >> p[i].first;
    }
    long long res=0;
    sort(p.begin(),p.end());
    if(p[1].first==p[2].first){
      res+=abs(p[1].second-p[2].second);
    }
    cout << res << '\n';
  }
  return 0;
}