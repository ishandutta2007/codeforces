#include<bits/stdc++.h>

using namespace std;

long long f(long long x){
  long long del=(x/2);
  if(x%2){return del-x;}
  else{return del;}
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long l,r;
    cin >> l >> r;
    cout << f(r)-f(l-1) << '\n';
  }
  return 0;
}