#include <stdio.h>
int i,j,k,z,n,m,x[111],y[111],s[111],c[1111][1111],md=1000000007;
long long f[111][1111],e=1LL;
int main() {
  for (i=0; i<1111; i++) {
    c[i][0]=1;
    for (j=1; j<=i; j++) {
      c[i][j]=c[i-1][j-1]+c[i-1][j];
      if (c[i][j]>=md) c[i][j]-=md;
    }
  }
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x[i]);
    s[i+1]=s[i]+x[i];
  }
  for (i=0; i<n; i++) scanf("%d",&y[i]);
  for (i=0; i<n; i++) e=(e*c[s[n]-s[i]][x[i]])%md;
  f[0][0]=1;
  for (i=0; i<n; i++) for (j=0; j<=s[i]; j++) if (f[i][j]>0) {
    z=s[i+1]-j;
    for (k=0; k<=y[i] && k<=z; k++) f[i+1][j+k]=(f[i+1][j+k]+c[z][k]*f[i][j])%md;
  }
  z=(f[n][s[n]]*e)%md;
  printf("%d\n",z);
  return 0;
}