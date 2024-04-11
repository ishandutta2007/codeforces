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
    vector<long long> res;
    long long pd=1;
    for(int i=0;i<n;i++){
      if(pd>1000000000){break;}
      res.push_back(pd);
      pd*=3;
    }
    if(res.size()==n){
      cout << "Yes\n";
      for(int i=0;i<n;i++){
        if(i){cout << ' ';}cout << res[i];
      }cout << '\n';
    }
    else{
      cout << "No\n";
    }
  }
  return 0;
}