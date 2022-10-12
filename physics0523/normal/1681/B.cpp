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
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    int m,d=0;
    cin >> m;
    for(int i=0;i<m;i++){
      int v;
      cin >> v;
      d+=v;d%=n;
    }
    cout << a[d] << '\n';
  }
  return 0;
}