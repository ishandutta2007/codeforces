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
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    long long qt=a[0],ql=0;
    bool ok=false;
    for(int i=1;i<n;i++){
      qt+=a[i];
      ql+=a[n-i];
      if(qt<ql){ok=true;}
    }
    if(ok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}