#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i = 0;i<n/7;i++)
    cout << "ROYGBIV";
  if(n%7==1)
    cout << "G";
  if(n%7==2)
    cout << "GB";
  if(n%7==3)
    cout << "GBI";
  if(n%7==4)
    cout << "GBIV";
  if(n%7==5)
    cout << "GBIVG";
  if(n%7==6)
    cout << "GBIVGB";
  return 0;
}