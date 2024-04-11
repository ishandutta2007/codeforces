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
    vector<int> res;
    if(n%2==0){
      for(int i=n-2;i>=1;i--){res.push_back(i);}
      res.push_back(n-1);
      res.push_back(n);
    }
    else{
      res.push_back(1);
      res.push_back(2);
      res.push_back(3);
      for(int i=n-2;i>=4;i--){res.push_back(i);}
      res.push_back(n-1);
      res.push_back(n);
    }
    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      cout << res[i];
    }cout << "\n";
  }
  return 0;
}