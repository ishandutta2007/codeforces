#include <bits/stdc++.h>
using namespace std;
int n,t,i,j,x,c[1000100];
double s[1000100],eps=1e-11;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x);
    s[++t]=x; c[t]=1;
    for (; t>1 && s[t]<s[t-1]+eps; --t) {
      s[t-1]=(s[t-1]*c[t-1]+s[t]*c[t])/(c[t-1]+c[t]);
      c[t-1]+=c[t];
    }
  }
  for (i=1; i<=t; i++) for (j=0; j<c[i]; j++) printf("%.11lf\n",s[i]);
  return 0;
}