#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long x,y,a,b;
    cin >> x >> y >> a >> b;
    long long d=y-x;
    if(d%(a+b)){cout << -1 << '\n';continue;}
    cout << d/(a+b) << '\n';
  }
  return 0;
}