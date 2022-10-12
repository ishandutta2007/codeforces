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
    if(n==1){
      cout << 2 << "\n";
      continue;
    }

    if(n%3==0){
      cout << n/3 << "\n";
    }
    else if(n%3==1){
      cout << (n+2)/3 << "\n";
    }
    else{
      cout << (n/3)+1 << "\n";
    }
  }
  return 0;
}