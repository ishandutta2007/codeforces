#include <stdio.h>
#include <string.h>
int n,m,i,j,a[40000];
long long all,res,c[40000];
char s[4444];
int main() {
  scanf("%d",&m);
  scanf("%s",s);
  n=strlen(s);
  for (i=0; i<n; i++) {
    a[i+1]=a[i]+s[i]-'0';
	for (j=0; j<=i; j++) { c[a[i+1]-a[j]]++; all++; }
  }
  if (m>0) {
    for (i=1; i<40000; i++) if (m%i==0 && m/i<40000) res+=c[i]*c[m/i];
	printf("%I64d\n",res);
  } else printf("%I64d\n",2*c[0]*all-c[0]*c[0]);
  return 0;
}