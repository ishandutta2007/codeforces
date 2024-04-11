#include <stdio.h>
#include <string.h>
int n,x,i,m1,m2,a,b,A[1000100],B[1000100];
char s1[1000100],s2[1000100];
int main() {
  scanf("%d",&n);
  scanf("%s",s1); m1=strlen(s1);
  scanf("%s",s2); m2=strlen(s2);
  x=m1*m2;
  for (i=0; i<n && i<x; i++) {
    if (i>=m1) s1[i]=s1[i-m1];
    if (i>=m2) s2[i]=s2[i-m2];
    if (s1[i]=='R') {
      if (s2[i]=='S') b++; else if (s2[i]=='P') a++;
    } else if (s1[i]=='S') {
      if (s2[i]=='R') a++; else if (s2[i]=='P') b++;
    } else if (s2[i]=='S') a++; else if (s2[i]=='R') b++;
    A[i+1]=a;
    B[i+1]=b;
  }
  if (i<n) {
    a=(n/x)*a+A[n%x];
    b=(n/x)*b+B[n%x];
  }
  printf("%d %d\n",a,b);
  return 0;
}