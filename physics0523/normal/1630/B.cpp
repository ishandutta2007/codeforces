#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    vector<int> a(n),b(n+3,0);
    for(auto &nx : a){
      cin >> nx;
      b[nx]++;
    }
    int fi=0,sig=0;
    int rx=1,ry=n;
    for(int st=1;st<=n;st++){
      while(fi<=n && (sig-(n-sig))<k){
        fi++;
        sig+=b[fi];
      }
      if(fi>n){break;}
      if((ry-rx)>(fi-st)){rx=st;ry=fi;}
      sig-=b[st];
    }
    cout << rx << ' ' << ry << '\n';
    int pt=0;
    for(int i=0;i<k-1;i++){
      int del=0;
      for(int j=pt;;j++){
        if(rx<=a[j] && a[j]<=ry){del++;}else{del--;}
        if(del==1){
          cout << pt+1 << ' ' << j+1 << '\n';
          pt=j+1;
          break;
        }
      }
    }
    cout << pt+1 << ' ' << n << '\n';
  }
  return 0;
}