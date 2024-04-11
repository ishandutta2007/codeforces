#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,e,w,x[77],y[77];
long long a,b,f[77][2];
int main() {
  cin>>a>>b;
  if (a==b) w=2;
  for (n=0; a>0; a/=2) x[n++]=a&1;
  for (m=0; b>0; b/=2) y[m++]=b&1;
  n=max(n,m);
  f[0][0]=1;
  for (i=0; i<n; i++) for (j=0; j<2; j++) if (f[i][j]) for (k=0; k<2; k++) {
    e=y[i]^k;
    if (((e+j+k)&1)==x[i]) f[i+1][(e+j+k)/2]+=f[i][j];
  }
  cout<<f[n][0]-w<<'\n';
  return 0;
}