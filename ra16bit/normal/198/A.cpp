#include <iostream>
using namespace std;
long long k,b,t,cur,x;
int i,n;
int main() {
  cin>>k>>b>>n>>t;
  x=1;
  for (i=0; i<=n; i++) {
    if (x>t) break;
    x=x*k+b;
  }
  cout<<n-i+1<<'\n';
  return 0;
}