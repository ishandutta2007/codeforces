#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int r;
    cin >> r;
    cout << "Division ";
    if(1900<=r){cout << 1;}
    else if(1600<=r){cout << 2;}
    else if(1400<=r){cout << 3;}
    else{cout << 4;}
    cout << '\n';
  }
  return 0;
}