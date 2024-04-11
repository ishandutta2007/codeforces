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
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    bool fl=true;
    for(int i=0;i<n;i++){
      int d=b[i]-a[i];
      if(!(0<=d && d<=1)){fl=false;}
    }
    if(fl){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}