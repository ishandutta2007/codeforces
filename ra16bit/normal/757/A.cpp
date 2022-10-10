#include <cstdio>
#include <string>
using namespace std;
const string t="Bulbasaur";
int i,r=100100,a[277],c[277];
char s[100100];
int main() {
  for (i=0; i<t.length(); i++) a[t[i]]++;
  scanf("%s",s);
  for (i=0; s[i]; i++) c[s[i]]++;
  for (i=0; i<277; i++) if (a[i]>0) r=min(r,c[i]/a[i]);
  printf("%d\n",r);
  return 0;
}