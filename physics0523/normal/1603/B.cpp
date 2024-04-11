#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long x,y;
    cin >> x >> y;
    long long n;
    if(x>y){
      long long p=2000000000000000000;
      p-=y;p/=x;
      n=p*x+y;
    }
    else{
      n=(x+y)/2;
      long long del=y-n;
      n+=(del/x)*x;
    }
    cout << n << '\n';
    //assert(n%x==y%n);
    //cerr << '(' << n%x << ' ' << y%n << ')' << '\n';
  }
  return 0;
}