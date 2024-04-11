#include <bits/stdc++.h>
using namespace std;
int i,a,b;
char s[55];
int main() {
  scanf("%s",s);
  for (i=0; s[i]; i++) if (s[i]=='a') a++; else b++;
  printf("%d\n",a+b-((a>b)?0:b-a+1));
  return 0;
}