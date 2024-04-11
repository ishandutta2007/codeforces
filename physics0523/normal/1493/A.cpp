#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> res;
    for(int i=k+1;i<=n;i++){res.push_back(i);}
    for(int i=(k+1)/2;i<k;i++){res.push_back(i);}
    cout << res.size() << '\n';
    for(int i=0;i<res.size();i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}