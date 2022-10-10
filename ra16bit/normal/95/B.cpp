#include <stdio.h>
#include <string.h>
int n,m,i,j,a,b;
char s[100100],t[100100];
bool q;
void go(int m) {
  for (i=0; i<m; i++) putchar('4');
  for (i=0; i<m; i++) putchar('7');
}
int main() {
  gets(s);
  n=strlen(s);
  if (n&1) {
    go((n+1)/2);
    return 0;
  }
  a=b=n/2;
  for (i=0; i<n; i++) {
    if (s[i]!='4' && s[i]!='7') break;
    if (s[i]=='4') {
      t[i]='4'; a--;
	  if (a==0) break;
    } else {
      t[i]='7'; b--;
	  if (b==0) break;
	}
  }
  if (s[i]!='4' && s[i]!='7') {
    if (s[i]>'7') {
	  q=true;
	} else if (s[i]>'4') {
	  t[i]='7'; b--;
	  for (j=i+1; j<n; j++) if (a>0) {
	    t[j]='4'; a--;
	  } else {
	    t[j]='7'; b--;
	  }
	} else {
	  t[i]='4'; a--;
	  for (j=i+1; j<n; j++) if (a>0) {
	    t[j]='4'; a--;
	  } else {
	    t[j]='7'; b--;
	  }
	}
  } else for (j=i+1; j<n; j++) if (a>0) {
    t[j]='4'; a--;
  } else {
    t[j]='7'; b--;
  }
  if (!q) for (j=0; j<n; j++) if (s[j]!=t[j]) {
    if (s[j]>t[j]) break;
	puts(t);
	return 0;
  }
  if (q || j<n) {
    for (j=i; j>=0; j--) if (t[j]=='4') break;
	if (j<0) { go(n/2+1); return 0; }
	t[j]='7'; a=b=n/2;
	for (i=0; i<=j; i++) if (t[i]=='4') a--; else b--;
	for (; i<n; i++) if (a>0) {
	  t[i]='4'; a--;
	} else {
	  t[i]='7'; b--;
	}
  }
  puts(t);
  return 0;
}