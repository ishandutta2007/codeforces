#include<bits/stdc++.h>

using namespace std;

int main(){
  long long l,r,g,lc;
  cin >> l >> r >> g >> lc;
  if(lc%g!=0){cout << "0\n";return 0;}
  long long pr=(lc/g),res=0;
  for(long long i=1;i*i<=pr;i++){
    if(pr%i!=0){continue;}
    long long p,q;
    p=i;
    q=pr/i;
    if(!(l<=g*p && g*p <= r)){continue;}
    if(!(l<=g*q && g*q <= r)){continue;}
    if(gcd(g*p,g*q)!=g || lcm(g*p,g*q)!=lc){continue;}
    if(p==q){res++;}
    else{res+=2;}
  }
  cout << res << '\n';
}