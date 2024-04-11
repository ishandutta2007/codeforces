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
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    int res=0;
    if(k==1){
      res=(n-1)/2;
    }
    else{
      for(int i=1;i<n-1;i++){
        if(a[i-1]+a[i+1]<a[i]){res++;}
      }
    }
    cout << res << '\n';
  }
  return 0;
}