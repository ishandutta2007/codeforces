#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long x,n;
    cin >> x >> n;
    for(long long i=(n/4)*4+1;i<=n;i++){
      if(x%2){x+=i;}
      else{x-=i;}
    }
    cout << x << '\n';
  }
  return 0;
}