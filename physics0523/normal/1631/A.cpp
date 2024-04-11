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
    vector<int> a(n),b(n);
    for(auto &nx : a){cin >> nx;}
    for(auto &nx : b){cin >> nx;}
    int e1=0,e2=0;
    for(int i=0;i<n;i++){
      e1=max(e1,max(a[i],b[i]));
      e2=max(e2,min(a[i],b[i]));
    }
    cout << e1*e2 << '\n';
  }
  return 0;
}