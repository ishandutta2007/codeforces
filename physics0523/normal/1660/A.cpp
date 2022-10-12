#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long a,b;
    cin >> a >> b;
    if(a==0){cout << "1\n";}
    else{cout << a+2*b+1 << '\n';}
  }
  return 0;
}