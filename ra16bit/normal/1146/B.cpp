#include <bits/stdc++.h>
using namespace std;
int n,m,i,l,h,t[100100];
char s[100100];
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (l=-1, i=0; i<n; i++) if (s[i]=='a') l=i; else t[m++]=i;
  if (m==0) { puts(s); return 0; }
  if (m%2) { puts(":("); return 0; }
  h=m/2;
  for (i=0; i<h; i++) if (s[t[i]]!=s[t[i+h]]) { puts(":("); return 0; }
  if (l>t[h]) { puts(":("); return 0; }
  for (i=0; i<t[h]; i++) putchar(s[i]);
  return 0;
}