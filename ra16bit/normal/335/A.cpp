#include <stdio.h>
#include <string.h>
int i,z,l,r,h,m,n,e,b[277];
char s[1111],c;
int main() {
  scanf("%s",s);
  scanf("%d",&n);
  m=strlen(s);
  for (i=0; i<m; i++) b[s[i]]++;
  l=1; r=m+1;
  while (l<r) {
    h=(l+r)/2;
	for (e=0, c='a'; c<='z'; c++) e+=(b[c]+h-1)/h;
	if (e<=n) r=h; else l=h+1;
  }
  if (r==m+1) { puts("-1"); return 0; }
  printf("%d\n",r);
  for (c='a'; c<='z'; c++) for (e=0; e<b[c]; e+=r) { putchar(c); z++; }
  for (z++; z<=n; z++) putchar('a');
  puts("");
  return 0;
}