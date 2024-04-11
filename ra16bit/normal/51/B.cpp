#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,p,i,a[5555],b[5555];
char s[5555],st[5555];
int main() {
  while (scanf("%s",st)!=EOF) {
    m=strlen(st);
    for (i=0; i<m; i++) s[n++]=st[i];
  }
  for (i=m=0; i<n; ) {
    if (s[i]=='<' && s[i+1]=='t' && s[i+2]=='a' && s[i+3]=='b' && s[i+4]=='l' && s[i+5]=='e' && s[i+6]=='>') {
      b[++p]=0; i+=7; continue;
    }
    if (s[i]=='<' && s[i+1]=='/' && s[i+2]=='t' && s[i+3]=='a' && s[i+4]=='b' && s[i+5]=='l' && s[i+6]=='e' && s[i+7]=='>') {
      a[m++]=b[p--]; i+=8; continue;
    }
    if (s[i]=='<' && s[i+1]=='t' && s[i+2]=='d' && s[i+3]=='>') {
      b[p]++; i+=4; continue;
    }
    if (s[i]=='<' && s[i+1]=='/' && s[i+2]=='t' && s[i+3]=='d' && s[i+4]=='>') {
      i+=5; continue;
    }
    i++;
  }
  sort(a,a+m);
  for (i=0; i<m; i++) {
    if (i) putchar(' ');
    printf("%d",a[i]);
  }
  return 0;
}