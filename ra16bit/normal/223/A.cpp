#include <stdio.h>
#include <string.h>
int n,m,i,r,x,y=-1,a[100100],b[100100],f[100100],l[100100];
char s[100100];
int main() {
  scanf("%s",s+1);
  n=strlen(s+1);
  for (i=1; i<=n; i++) {
    b[i]=b[i-1]+int(s[i]=='[');
    if (s[i]==')') {
	  if (m>0 && s[a[m]]=='(') {
	    f[i]=f[a[m]-1]+b[i]-b[a[m]-1];
		l[i]=(l[a[m]-1]==0)?a[m]:l[a[m]-1];
	    if (f[i]>r) { r=f[i]; x=l[i]; y=i; }
	    m--;
	  } else m=0;
    } else if (s[i]==']') {
	  if (m>0 && s[a[m]]=='[') {
	    f[i]=f[a[m]-1]+b[i]-b[a[m]-1];
		l[i]=(l[a[m]-1]==0)?a[m]:l[a[m]-1];
	    if (f[i]>r) { r=f[i]; x=l[i]; y=i; }
	    m--;
	  } else m=0;
	} else a[++m]=i;
  }
  printf("%d\n",r);
  for (i=x; i<=y; i++) putchar(s[i]);
  putchar('\n');
  return 0;
}