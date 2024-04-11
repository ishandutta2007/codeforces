#include <bits/stdc++.h>
using namespace std;
int n,i,j,e,f[10100][4];
char s[10100];
string c,p;
set<string> a;
set<string>::iterator it;
int main() {
  scanf("%s",s);
  n=strlen(s);
  f[n][0]=true;
  for (i=n; i>=5; i--) for (j=0; j<4; j++) if (f[i][j]) {
    c=p="";
    for (e=0; e<j; e++) p+=s[i+e];
    for (e=1; e<4 && i-e>=5; e++) {
      c=s[i-e]+c;
      if (e>1 && c!=p) {
        a.insert(c);
        f[i-e][e]=true;
      }
    }
  }
  printf("%d\n",int(a.size()));
  for (it=a.begin(); it!=a.end(); it++) printf("%s\n",it->c_str());
  return 0;
}