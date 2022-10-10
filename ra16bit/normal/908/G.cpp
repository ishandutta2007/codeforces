#include <bits/stdc++.h>
using namespace std;
const int md=1000000007;
int n,i,j,x,r,c[11],z[11],cnt[11][707][707],C[707][707];
long long pw[11][707],p11[707],d[11][707],f[11][707],cur;
char s[707],ch;
long long sqr(long long x) { return (x*x)%md; }
int main() {
  scanf("%s",&s);
  n=strlen(s);
  for (i=1; i<=n; i++) p11[i]=(p11[i-1]*10LL+1)%md;
  for (j=0; j<=10; j++) for (pw[j][0]=i=1; i<=n; i++) pw[j][i]=(pw[j][i-1]*j)%md;
  for (i=0; i<=n; i++) {
    C[i][0]=1;
    for (j=1; j<=i; j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%md;
  }
  for (j=0; j<10; j++) for (i=0; i<=n; i++) for (x=0; x<=i; x++) d[j][i]=(d[j][i]+((C[i][x]*p11[x])%md*pw[j][i-x])%md*j)%md;
  for (j=0; j<10; j++) for (i=0; i<=n; i++) for (x=0; x<=i; x++) f[j][i]=(f[j][i]+((C[i][x]*pw[9-j][x])%md*d[j][i-x])%md*pw[10][x])%md;
  for (j=1; j<10; j++) for (i=0; i<=n; i++) for (x=0; x<=i; x++) cnt[j][i][x]=(((C[i][x]*pw[9-j][x])%md)*pw[j+1][i-x]%md)*pw[10][x]%md;
  for (i=0; i<n; i++) {
    for (ch='0'; ch<=s[i]; ch++) if (ch<s[i] || i==n-1) {
	  c[ch-'0']++;
	  z[9]=c[9];
	  for (j=8; j>=0; j--) z[j]=c[j]+z[j+1];
//	  for (j=0; j<10; j++) printf("%d,",c[j]); puts(" c");
//	  for (j=0; j<10; j++) printf("%d,",z[j]); puts(" z");
      for (j=1; j<10; j++) {
	    r=(r+f[j][n-i-1]*pw[10][z[j]])%md;
		cur=((p11[c[j]]*j)%md*pw[10][z[j+1]])%md;
		for (x=0; x<n-i; x++) r=(r+cur*cnt[j][n-i-1][x])%md;
	  }
	  c[ch-'0']--;
	}
	c[s[i]-'0']++;
  }
  printf("%d\n",r);
  return 0;
}