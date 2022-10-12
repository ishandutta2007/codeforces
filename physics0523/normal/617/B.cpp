#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int sig=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    sig+=a[i];
  }
  if(sig==0){cout << 0 << '\n';return 0;}
  long long res=1;
  int pv=-1;
  for(int i=0;i<n;i++){
    if(a[i]==1){
      if(pv!=-1){
        res*=(long long)(i-pv);
      }
      pv=i;
    }
  }
  cout << res << '\n';
  return 0;
}