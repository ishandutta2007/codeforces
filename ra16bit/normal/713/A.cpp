#include <bits/stdc++.h>
using namespace std;
int n,m,i,j;
char s[77],t[7];
string st;
map<string,int> a;
int main() {
  scanf("%d",&m);
  for (i=0; i<m; i++) {
    scanf("%s",t);
    scanf("%s",s);
    n=strlen(s);
    reverse(s,s+n);
    if (t[0]=='?') {
      for (j=n; j<18; j++) s[j]='0';
      st=s;
      printf("%d\n",a.count(st)?a[st]:0);
    } else {
      for (j=0; j<n; j++) s[j]='0'+((s[j]-'0')%2);
      for (j=n; j<18; j++) s[j]='0';
      st=s;
      if (t[0]=='+') a[st]++; else a[st]--;
    }
  }
  return 0;
}