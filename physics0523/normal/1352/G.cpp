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
    if(n<=3){cout << "-1\n";continue;}
    vector<int> res;
    for(int i=4;i<=n;i+=4){
      res.push_back(i-2);
      res.push_back(i);
      res.push_back(i-3);
      res.push_back(i-1);
    }
    if(n%4==1){res.push_back(n);}
    if(n%4==2){
      res.pop_back();
      res.push_back(n-1);
      res.push_back(n-3);
      res.push_back(n);
    }
    if(n%4==3){
      res.pop_back();
      res.push_back(n-2);
      res.push_back(n);
      res.push_back(n-4);
      res.push_back(n-1);
    }
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}