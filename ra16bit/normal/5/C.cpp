#include <cstdio>
#include <cstring>
using namespace std;
int i,n,m,d,r,c[1000100],t[1000100];
char s[1000100];
int main() {
  gets(s); n=strlen(s);
  for (i=0; i<n; i++) if (s[i]==')') {
    if (m==0) c[i+1]=0; else c[i+1]=c[t[m--]]+c[i]+1;
    if (r<c[i+1]) r=c[i+1];
  } else t[++m]=i;
  for (i=1; i<=n; i++) if (c[i]==r) d++;
  if (r==0) d=1;
  printf("%d %d\n",r*2,d);
  return 0;
}