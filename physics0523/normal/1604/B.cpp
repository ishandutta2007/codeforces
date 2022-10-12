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
    bool fl=false;
    for(int i=1;i<n;i++){
      if(a[i-1]>=a[i]){fl=true;}
    }
    if(n%2==1 && !fl){cout << "NO\n";}
    else{cout << "YES\n";}
  }
  return 0;
}