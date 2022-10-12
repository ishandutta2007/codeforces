#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a&b&c&d){cout << "2\n";}
    else if((a|b|c|d)==0){cout << "0\n";}
    else{cout << "1\n";}
  }
  return 0;
}