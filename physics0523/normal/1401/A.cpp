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
    if(n>=k){
      if(n%2==k%2){cout << "0\n";}
      else{cout << "1\n";}
    }
    else{
      cout << k-n << '\n';
    }
  }
  return 0;
}