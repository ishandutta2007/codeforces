#include <stdio.h>
int n,i,j,a[11];
char s[22];
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  for (i=0; i<n; i++) if (s[i]>'1') a[s[i]-'0']++;
  for (j=0; j<a[9]; j++) {
    putchar('7');
    a[3]+=2; a[2]++;
  }
  for (j=0; j<a[8]; j++) {
    putchar('7');
    a[2]+=3;
  }
  for (j=0; j<a[7]; j++) putchar('7');
  for (j=0; j<a[6]; j++) {
    putchar('5');
    a[3]++;
  }
  for (j=0; j<a[5]; j++) putchar('5');
  for (j=0; j<a[4]; j++) {
    a[3]++; a[2]+=2;
  }
  for (j=0; j<a[3]; j++) putchar('3');
  for (j=0; j<a[2]; j++) putchar('2');
  return 0;
}