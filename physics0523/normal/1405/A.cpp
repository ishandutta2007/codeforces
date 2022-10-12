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
    vector<int> p(n);
    for(auto &nx : p){cin >> nx;}
    reverse(p.begin(),p.end());
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << p[i];
    }cout << '\n';
  }
  return 0;
}