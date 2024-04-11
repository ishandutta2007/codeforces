#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,x,y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  for(int i=0;i<n;i++){
    bool fl=true;
    for(int j=1;j<=x;j++){
      if((i-j)<0){continue;}
      if(a[i]>=a[i-j]){fl=false;}
    }
    for(int j=1;j<=y;j++){
      if((i+j)>=n){continue;}
      if(a[i]>=a[i+j]){fl=false;}
    }
    if(fl){cout << i+1 << '\n';return 0;}
  }
  return 0;
}