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
    int st=0;
    int res=0;
    for(int i=1;i<=n;i++){
      if(i==n || a[i-1]<=a[i]){
        res+=(i-st)/2;
        st=i;
      }
    }
    cout << res << '\n';
  }
  return 0;
}