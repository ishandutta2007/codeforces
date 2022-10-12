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
    vector<int> res={0};
    int i;
    for(i=1;i*i<=n;i++){
      res.push_back(i);
    }
    int lim=res.back();
    while(i>0){
      if(lim<(n/i)){res.push_back(n/i);}
      i--;
    }
    cout << res.size() << '\n';
    for(int i=0;i<res.size();i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}