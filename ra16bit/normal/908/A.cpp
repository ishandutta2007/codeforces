#include <bits/stdc++.h>
using namespace std;
const string g="aeiou";
int n,i,j,r;
char s[55];
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (i=0; i<n; i++) if (s[i]>='a' && s[i]<='z') {
    for (j=0; j<g.length(); j++) if (s[i]==g[j]) break;
	if (j<g.length()) r++;
  } else r+=(s[i]-'0')%2;
  printf("%d\n",r);
  return 0;
}