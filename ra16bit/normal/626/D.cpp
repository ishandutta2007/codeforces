#include <bits/stdc++.h>
using namespace std;
int n,i,j,a[2002];
double f[5005],s[5005],r,ans;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  for (i=0; i<n; i++) for (j=0; j<i; j++, r++) f[a[i]-a[j]]++;
  for (i=5000; i>=0; i--) { f[i]/=r; s[i]=s[i+1]+f[i]; }
  for (i=1; i<5000; i++) for (j=1; i+j<5000; j++) ans+=s[i+j+1]*f[i]*f[j];
  printf("%.10lf\n",ans);
  return 0;
}