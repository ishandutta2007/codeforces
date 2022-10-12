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
    int cv=a[n-1],res=0;
    for(int i=n-2;i>=0;i--){
      if(cv<a[i]){cv=a[i];res++;}
    }
    cout << res << '\n';
  }
  return 0;
}