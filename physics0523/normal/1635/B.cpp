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
    a.push_back(1000000000);
    int rc=0;
    for(int i=1;i<n-1;i++){
      if(a[i]>a[i-1] && a[i]>a[i+1]){
        rc++;
        a[i+1]=max(a[i],a[i+2]);
      }
    }
    cout << rc << '\n';
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << a[i];
    }cout << '\n';
  }
  return 0;
}