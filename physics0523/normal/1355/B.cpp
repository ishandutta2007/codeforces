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
    int res=0,cs=0;
    for(int i=0;i<n;i++){
      cs++;
      if(a[i]<=cs){
        cs=0;
        res++;
      }
    }
    cout << res << '\n';
  }
  return 0;
}