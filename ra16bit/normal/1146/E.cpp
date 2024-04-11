#include <bits/stdc++.h>
using namespace std;
int n,m,i,l,r,h,cur,t,s[100100],a[100100],b[100100],sb[100100],rev[100100];
char c[5],sc[100100];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=1; i<=m; i++) {
    scanf("%s",c);
	scanf("%d",&b[i]);
	sc[i]=c[0]; sb[i]=b[i];
	if (c[0]=='<') { if (b[i]>0) rev[i]=1; else b[i]--; }
	if (c[0]=='>') { if (b[i]<0) rev[i]=1; else b[i]++; }
	if (b[i]<0) b[i]=-b[i];
	while (t>0 && b[s[t]]>=b[i]) t--;
	s[++t]=i;
  }
//  for (i=1; i<=t; i++) printf("%d,",s[i]); puts(" <-s");
  for (i=m-1; i>0; i--) rev[i]+=rev[i+1];
//  for (i=0; i<=m; i++) printf("%d,",rev[i]); puts(" <-rev");
  for (i=0; i<n; i++) {
    cur=a[i];
	if (cur<0) cur=-cur;
	l=0; r=t;
	while (l<r) {
	  h=(l+r)/2+1;
	  if (b[s[h]]>cur) r=h-1; else l=h;
	}
	r=s[r];
	if (r!=0) {
	  if (sc[r]=='<' && a[i]<sb[r]) a[i]=-a[i];
	  if (sc[r]=='>' && a[i]>sb[r]) a[i]=-a[i];
	}
	if (rev[r+1]&1) a[i]=-a[i];
	printf("%d ",a[i]);
  }
  return 0;
}