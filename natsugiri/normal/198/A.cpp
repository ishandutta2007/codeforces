#include<iostream>
using namespace std;

long long  k,b,n,t, x, y;


int main(){
  cin>>k>>b>>n>>t;
  for (x=1, y=0; y<n && x<t; y++) x=k*x+b;
  if (x>t) y--;
  cout<<n-y<<endl;
  return 0;
}