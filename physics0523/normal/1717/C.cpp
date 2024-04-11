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

    int ama=-2e9,bmi=2e9;
    vector<int> a(n),b(n);
    for(auto &nx : a){
      cin >> nx;
      ama=max(ama,nx);
    }
    for(auto &nx : b){
      cin >> nx;
      bmi=min(bmi,nx);
    }

    if(ama<=bmi){
      for(auto &nx : a){nx=bmi;}
    }

    for(int i=5*n;i>=0;i--){
      if(a[i%n]==b[i%n]){continue;}
      int mxm=min(b[i%n],a[(i+1)%n]+1);
      a[i%n]=max(a[i%n],mxm);
    }

    if(a==b){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}