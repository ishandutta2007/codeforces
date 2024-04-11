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
    vector<int> p(n);
    for(auto &nx : p){cin >> nx;}
    vector<pi> vp;
    vector<int> res(n);
    for(int i=1;i<n;i++){
      vp.push_back({p[i-1]-p[i],i+1});
    }
    sort(vp.begin(),vp.end());
    res[0]=1;
    for(int i=0;i<vp.size();i++){res[i+1]=vp[i].second;}
    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      cout << res[i];
    }cout << "\n";
  }
  return 0;
}