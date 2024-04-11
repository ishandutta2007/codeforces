#include<bits/stdc++.h>

using namespace std;

void ope(int l,int r,vector<int> &a){
  cout << l << " " << r << "\n";
  if((a[l]+a[r])%2){a[r]=a[l];}
  else{a[l]=a[r];}
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
      cin >> a[i];
    }
    cout << n-1 << "\n";
    if(n>1){ope(1,n,a);}
    for(int i=2;i<=n-1;i++){
      if(a[1]%2==a[i]%2){ope(i,n,a);}
      else{ope(1,i,a);}
    }
    // for(auto &nx : a){
    //   cerr << nx << " ";
    // }cerr << "\n";
  }
  return 0;
}