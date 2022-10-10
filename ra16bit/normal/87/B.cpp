#include <cstdio>
#include <string>
#include <string.h>
#include <map>
using namespace std;
int n,i,j,k,x,c;
char s[77];
string st;
map <string, int> m;
void get() {
  scanf("%s",s); x=0;
  for (k=strlen(s)-1; s[k]=='*'; k--) x++;
  for (j=0; s[j]=='&'; j++) x--;
  for (st=""; j<=k; j++) st+=s[j];
  c=m[st];
  if (c>0) c+=x;
  if (c<=0) c=0;
}
int main() {
  scanf("%d",&n); m["void"]=1;
  for (i=0; i<n; i++) {
    scanf("%s",s);
    if (s[4]=='d') {
      get();
      scanf("%s",s); st=s; m[st]=c;
    } else {
      get();
      if (c>0) {
        printf("void");
        for (j=1; j<c; j++) printf("*"); puts("");
      } else puts("errtype");
    }
  }
  return 0;
}