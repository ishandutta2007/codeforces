#include <bits/stdc++.h>
using namespace std;
const char c[3]={'B','G','R'};
int n,i,a[277];
char s[277],d;
vector<char> e;
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  for (i=0; i<n; i++) a[s[i]]++;
  for (i=0; i<3; i++) if (a[c[i]]>0) e.push_back(c[i]); else d=c[i];
  if (e.size()==1) { putchar(e[0]); return 0; }
  if (e.size()==3) { puts("BGR"); return 0; }
  if (a[e[0]]==1 && a[e[1]]==1) { putchar(d); return 0; }
  if (a[e[0]]==1) {
    for (i=0; i<3; i++) if (c[i]!=e[1]) putchar(c[i]);
    return 0;
  }
  if (a[e[1]]==1) { 
    for (i=0; i<3; i++) if (c[i]!=e[0]) putchar(c[i]);
    return 0;
  }
  puts("BGR");
  return 0;
}