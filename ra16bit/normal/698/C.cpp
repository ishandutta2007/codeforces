#include <bits/stdc++.h>
using namespace std;
int n,m,mr,i,j,mask,c[1100100];
double cur,p[22],r[22],f[1100100];
int main() {
  cin>>n>>m;
  for (i=0; i<n; i++) {
    cin>>p[i];
    if (p[i]>1e-7) mr++;
  }
  m=min(m,mr);
  f[0]=1;
  for (mask=0; mask<(1<<n); mask++) {
    c[mask]=c[mask/2]+(mask&1);
    if (c[mask]==m) for (i=0; i<n; i++) if ((mask>>i)&1) r[i]+=f[mask];
    if (c[mask]>=m) continue;
    for (cur=1, i=0; i<n; i++) if ((mask>>i)&1) cur-=p[i];
    for (i=0; i<n; i++) if (p[i]>1e-7 && ((mask>>i)&1)==0) f[mask|(1<<i)]+=f[mask]*(p[i]/cur);
  }
  for (i=0; i<n; i++) printf("%.10lf%c",r[i],(i+1==n)?'\n':' ');
  return 0;
}