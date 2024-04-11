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
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++){
      cin >> vp[i].second;
      vp[i].first=vp[i].second%2;
    }
    sort(vp.begin(),vp.end());
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << vp[i].second;
    }cout << '\n';
  }
  return 0;
}