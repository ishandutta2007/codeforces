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
    sort(a.begin(),a.end());
    int res=1,g=1e9;
    for(int i=1;i<n;i++){
      g=min(g,a[i]-a[i-1]);
      if(a[i]>g){break;}
      res=i+1;
    }
    cout << res << '\n';
  }
  return 0;
}