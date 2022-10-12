#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<pi> pv;
    for(int i=0;i<n;i++){
      int k;
      cin >> k;
      int need=0;
      for(int j=0;j<k;j++){
        int v;
        cin >> v;
        need=max(need,v-j+1);
      }
      pv.push_back({need,k});
      //cout << need << ' ' << k << '\n';
    }
    sort(pv.begin(),pv.end());
    int res=pv[0].first;
    int cl=res;
    for(int i=0;i<n;i++){
      int del=max(0,pv[i].first-cl);
      res+=del;cl+=del;
      cl+=pv[i].second;
    }
    cout << res << '\n';
  }
  return 0;
}