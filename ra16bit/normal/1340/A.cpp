#include <bits/stdc++.h>
using namespace std;
int it,t,n,x,i,j,k,w[100100],u[100100];
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%d",&n);
    for (i=1; i<=n; i++) {
      scanf("%d",&x);
      w[x]=i;
    }
    for (i=1; i<=n; i=j) {
      u[w[i]]=it;
      for (j=i+1, k=w[i]+1; j<=n && k<=n && u[k]!=it && k==w[j]; j++, k++) u[k]=it;
      if (j<=n && k<=n && u[k]!=it) break;
    }
    puts((i<=n)?"No":"Yes");
  }
  return 0;
}