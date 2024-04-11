#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long h,w,x;
    cin >> h >> w >> x;
    x--;
    long long p=x/h,q=x%h;
    cout << (q*w+p)+1 << '\n';
  }
  return 0;
}