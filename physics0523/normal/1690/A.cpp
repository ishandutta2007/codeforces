#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    long long p=2,q=3,r=1;
    n-=6;
    long long x=(n+1)/3,y=(n+2)/3,z=n/3;
    cout << p+x << ' ' << q+y << ' ' << r+z << '\n';
  }
  return 0;
}