#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int a,b,c;
    cin >> a >> b >> c;
    int d=abs(b-a);
    int r=2*d;
    if(!(1<=a && a<=r)){cout << "-1\n";continue;}
    if(!(1<=b && b<=r)){cout << "-1\n";continue;}
    if(!(1<=c && c<=r)){cout << "-1\n";continue;}
    if(c<=d){cout << c+d << '\n';}else{cout << c-d << '\n';}
  }
  return 0;
}