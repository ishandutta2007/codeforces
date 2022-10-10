#include <bits/stdc++.h>
using namespace std;
int n,m,num,i,j;
char a[500500];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m && num<n; i++) {
    for (j=i; j>0; j--) {
      a[num++]='a'+j;
      a[num++]='a'+i;
      if (num>=n) break;
    }
    a[num++]='a';
  }
  for (i=j=0; i<n; i++, j++) {
    if (j>=num) j=0;
    putchar(a[j]);
  }
  return 0;
}