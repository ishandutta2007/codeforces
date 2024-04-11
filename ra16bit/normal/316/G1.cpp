#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
int i,k,n,m,e,j,cur,res,le[11],ri[11],d[11],p[100100];
char c[222],st[11][222],s[555];
set<string> ss;
string str;
int pre(int n, int e) {
  int z=0,k=0;
  for (int i=1; i<n; i++) {
    while (k>0 && s[k]!=s[i]) k=p[k-1];
	if (s[k]==s[i]) k++;
	p[i]=k;
	if (k==e) z++;
  }
  return z;
}
int main() {
  scanf("%s",c);
  n=strlen(c);
  scanf("%d",&m);
  for (j=0; j<m; j++) {
    scanf("%s",st[j]);
	scanf("%d%d",&le[j],&ri[j]);
	d[j]=e=strlen(st[j]);
  }
  for (i=1; i<=n; i++) for (j=i; j<=n; j++) {
    str="";
	for (k=i; k<=j; k++) str+=c[k-1];
	if (ss.count(str)) continue;
	ss.insert(str);
    for (k=0; k<m; k++) {
	  int ee=str.length();
	  for (int pp=0; pp<ee; pp++) s[pp]=str[pp];
	  s[ee]='$';
	  for (int pp=0; pp<d[k]; pp++) s[ee+1+pp]=st[k][pp];
	  s[ee+1+d[k]]=0;
	  cur=pre(ee+1+d[k],ee);
	  if (cur<le[k] || cur>ri[k]) break;
	}
	if (k>=m) res++;
  }
  printf("%d\n",res);
  return 0;
}