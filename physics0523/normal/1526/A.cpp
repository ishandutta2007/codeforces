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
    vector<int> a(2*n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    vector<int> res(2*n);
    for(int i=0;i<n;i++){
      res[2*i]=a[i];
      res[2*i+1]=a[n+i];
    }
    for(int i=0;i<2*n;i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}