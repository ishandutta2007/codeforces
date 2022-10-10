#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[100010],a[110],b[110];
int p[100010],pp[100010],pa[110],pb[110],na,nb,n,i,j,k;
bool q,f;
bool can() {
  for (k=-1, j=i=0; i<n; i++) {
    while (j>0 && (j>=na || a[j]!=s[i])) j=pa[j-1];
    if (j<na && a[j]==s[i]) j++;
    p[i]=j;
    if (p[i]==na) { k=i; break; }
  }
  if (k==-1) return false;
  for (j=i=0; i<n; i++) {
    while (j>0 && (j>=nb || b[j]!=s[i])) j=pb[j-1];
    if (j<nb && b[j]==s[i]) j++;
    pp[i]=j;
    if (pp[i]==nb && k+nb<=i) return true;
  }
  return false;
}
int main() {
  gets(s); n=strlen(s);
  gets(a); na=strlen(a);
  for (j=0, i=1; i<na; i++) {
    while (j>0 && a[j]!=a[i]) j=pa[j-1];
    if (a[j]==a[i]) j++;
    pa[i]=j;
  }
  gets(b); nb=strlen(b);
  for (j=0, i=1; i<nb; i++) {
    while (j>0 && b[j]!=b[i]) j=pb[j-1];
    if (b[j]==b[i]) j++;
    pb[i]=j;
  }
  q=can();
  reverse(s,s+n);
  f=can();
  if (q) {
    if (f) puts("both"); else puts("forward");
  } else {
    if (f) puts("backward"); else puts("fantasy");
  }
  return 0;
}