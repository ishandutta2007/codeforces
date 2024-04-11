#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    if(n%2){
      cout << "Mike\n";
      continue;
    }
    long long jm=8e18,jj=8e18;
    for(int i=0;i<n;i++){
      if(i%2==0){jm=min(jm,a[i]*n+i);}
      else{jj=min(jj,a[i]*n+i);}
    }
    if(jm<jj){cout << "Joe\n";}
    else{cout << "Mike\n";}
  }
  return 0;
}