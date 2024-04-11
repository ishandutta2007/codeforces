#include <bits/stdc++.h>
using namespace std;
const int MX=20020;
int t,n,s,i,a[MX],b[MX];
int main() {
    scanf("%d",&n);
    for (s=i=0; i<n; i++) {
      scanf("%d",&a[i]);
      b[i]=a[i]/2;
      if (a[i]%2==-1) --b[i];
      s+=b[i];
    }
    for (i=0; i<n && s<0; i++) if (a[i]%2!=0) { ++s; ++b[i]; }
    for (i=0; i<n; i++) printf("%d\n",b[i]);
    return 0;
}