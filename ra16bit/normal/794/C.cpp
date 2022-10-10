#include <bits/stdc++.h>
using namespace std;
int n,i,la,lb,lc,ra,rb,rc;
char a[300300],b[300300],c[300300];
int main() {
  scanf("%s",a);
  scanf("%s",b);
  n=strlen(a);
  sort(a,a+n);
  sort(b,b+n);
  reverse(b,b+n);
  ra=(n+1)/2-1;
  rb=n/2-1;
  rc=n-1;
  for (i=0; i<n; i++) if (i&1) {
    if (b[lb]>a[la]) c[lc++]=b[lb++]; else c[rc--]=b[rb--];
  } else {
    if (b[lb]>a[la]) c[lc++]=a[la++]; else c[rc--]=a[ra--];
  }
  puts(c);
  return 0;
}