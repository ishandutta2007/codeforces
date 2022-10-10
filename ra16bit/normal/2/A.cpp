#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int n,i,j,e,nn,a,b[2000000],c[2000000],o[1010],t[1010];
char ss[1000];
string s,cs[1010];
map <string, int> m;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s %d",&ss,&a);
    string s=ss; j=m[ss];
    if (j==0) { m[ss]=j=++nn; cs[nn]=s; }
    o[j]+=a; e=o[j];
    if (e>=0 && b[e]==0) { b[e]=j; c[e]=i; }
  }
  for (e=0, j=i=1; i<=nn; i++) {
    if (o[i]>o[j]) { j=i; e=0; }
    if (o[i]==o[j]) e++;
    t[i]=n+10;
  }
  if (e==1) puts(cs[j].c_str()); else {
    for (i=o[j]; i<2000000; i++) t[b[i]]=min(t[b[i]],c[i]);
	for (e=0, j=i=1; i<=nn; i++) if (o[i]>o[j] || (o[i]==o[j] && t[i]<t[j])) j=i;
    puts(cs[j].c_str());
  }
  return 0;
}