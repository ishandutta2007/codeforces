#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MX=3002;
int cur,ii,i,j,k,n,xa,xb,ya,yb,cs,ck,sum,top,a[MX+2][MX+2],s[MX+2][MX+2],le[MX+2][MX+2],ri[MX+2][MX+2],up[MX+2][MX+2],dw[MX+2][MX+2],sk[3*MX],ss[3*MX],XA[100100],XB[100100],YA[100100],YB[100100];
vector<int> v;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
	xa++; ya++; xb++; yb++;
	XA[i]=xa; YA[i]=ya;
	XB[i]=xb; YB[i]=yb;
	for (j=xa; j<xb; j++) {
	  a[j][ya]|=1; a[j+1][ya]|=2;
	  a[j][yb]|=1; a[j+1][yb]|=2;
	  for (k=ya; k<yb; k++) a[j][k]|=16;
	}
	for (j=ya; j<yb; j++) {
	  a[xa][j]|=4; a[xa][j+1]|=8;
	  a[xb][j]|=4; a[xb][j+1]|=8;
	}
  }
  for (i=1; i<=MX; i++) for (j=1; j<=MX; j++) {
    s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(a[i][j]>>4);
	if (a[i][j]&2) le[i][j]=le[i-1][j]+1;
	if (a[i][j]&8) up[i][j]=up[i][j-1]+1;
  }
  for (i=MX; i>0; i--) for (j=MX; j>0; j--) {
    if (a[i][j]&1) ri[i][j]=ri[i+1][j]+1;
	if (a[i][j]&4) dw[i][j]=dw[i][j+1]+1;
  }
  //for (i=1; i<=12; i++,puts("")) for (j=1; j<12; j++) printf("%d ",up[i][j]);
  //for (i=1; i<=10; i++,puts("")) for (j=1; j<=10; j++) printf("%d ",s[i][j]);
  for (sum=0; sum<=2*MX; sum++) {
    i=j=0;
	if (sum<=MX) j=sum; else { j=MX; i=sum-MX; }
	for (top=k=0; i<=MX && j>=0; i++, j--, k++) {
	  //if (sum==11) printf("%d %d %d:\n",k,i,j);
	  while (top>0) {
	    ck=k-sk[top];
		cs=ss[top];
	    if (cs<ck) { top--; continue; }
		cur=s[i-1][j+ck-1]-s[i-1][j-1]-s[i-ck-1][j+ck-1]+s[i-ck-1][j-1];
		if (cur==ck*ck) break;
		//if (sum==11) printf("rm %d |          %d %d\n",sk[top],cur,ck);
		top--;
	  }
	  if (top>0) {
	    ck=k-sk[top];
		if (min(le[i][j],dw[i][j])>=ck) {
		  for (ii=0; ii<n; ii++) if (XA[ii]>=i-ck && YA[ii]>=j && XA[ii]<i && YA[ii]<j+ck) v.push_back(ii+1);
	      printf("YES %d\n",int(v.size()));
		  for (ii=0; ii<v.size(); ii++) printf("%d%c",v[ii],(ii+1==v.size())?'\n':' ');
		  return 0;
		}
	  }
	  sk[++top]=k;
	  ss[top]=min(ri[i][j],up[i][j]);
	  //if (sum==11) printf("add %d %d\n",sk[top],ss[top]);
	}
  }
  puts("NO");
  return 0;
}