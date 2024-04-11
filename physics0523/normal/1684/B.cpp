#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long a,b,c;
    cin >> a >> b >> c;
    cout << c+b+a << ' ';
    cout << c+b << ' ';
    cout << c << '\n';
  }
  return 0;
}