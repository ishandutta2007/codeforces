#include<bits/stdc++.h>

using namespace std;

bool isprime(int x){
  if(x<=1){return false;}
  for(int i=2;i*i<=x;i++){
    if(x%i==0){return false;}
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int d;
    cin >> d;
    int res=1,fv=1;
    for(int k=0;k<2;k++){
      fv+=d;
      for(int i=fv;;i++){
        if(isprime(i)){
          res*=i;
          fv=i;break;
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}