#include <iostream>
using namespace std;
long long n,l,r,s,b[55];
int m,i,a[55];
void solve(int d, long long L, long long l, long long r) {
  long long h=L+b[d+1];
  if (d<m-1 && l<h) solve(d+1,L,l,min(h-1,r));
  if (l<=h && h<=r) s+=a[d];
  if (d<m-1 && h<r) solve(d+1,h+1,max(h+1,l),r);
}
int main() {
  cin>>n>>l>>r;
  for (m=0; n>0; n/=2, m++) a[m]=n%2;
  for (i=m-1; i>=0; i--) b[i]=b[i+1]*2+1;
  solve(0,1,l,r);
  cout<<s<<'\n';
  return 0;
}