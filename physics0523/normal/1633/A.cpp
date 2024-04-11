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
    if(n%7==0){cout << n << '\n';continue;}
    n/=10;n*=10;
    while(n%7!=0){n++;}
    cout << n << '\n';
  }
  return 0;
}