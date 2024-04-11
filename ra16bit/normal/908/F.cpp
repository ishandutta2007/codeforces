#include <bits/stdc++.h>
using namespace std;
int n,i,j,pr,pb,mr,mb,res,x[300300];
char s[5],c[300300];
vector<int> g;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x[i]);
	scanf("%s",s);
	c[i]=s[0];
	if (c[i]=='G') g.push_back(i);
	if (c[i]=='G' || c[i]=='B') {
	  if (pb>0) res+=x[i]-pb;
	  pb=x[i];
	}
	if (c[i]=='G' || c[i]=='R') {
	  if (pr>0) res+=x[i]-pr;
	  pr=x[i];
	}
  }
  for (i=1; i<g.size(); i++) {
    pb=pr=x[g[i-1]];
	mb=mr=0;
	for (j=g[i-1]+1; j<=g[i]; j++) {
	  if (c[j]=='G' || c[j]=='B') {
	    mb=max(mb,x[j]-pb);
	    pb=x[j];
	  }
	  if (c[j]=='G' || c[j]=='R') {
	    mr=max(mr,x[j]-pr);
	    pr=x[j];
	  }
	}
	if (x[g[i]]-x[g[i-1]]<mr+mb) res+=x[g[i]]-x[g[i-1]]-mr-mb;
  }
  printf("%d\n",res);
  return 0;
}