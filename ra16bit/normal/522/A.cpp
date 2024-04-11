#include <cstdio>
#include <string>
#include <map>
using namespace std;
int n,i,j,x,r;
char s[44];
string a,b;
map<string,int> m;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",s); a=s;
    scanf("%s",s);
    scanf("%s",s); b=s;
    for (j=0; j<a.length(); j++) a[j]=tolower(a[j]);
    for (j=0; j<b.length(); j++) b[j]=tolower(b[j]);
    m[a]=x=m[b]+1;
    r=max(x,r);
  }
  printf("%d\n",r+1);
  return 0;
}