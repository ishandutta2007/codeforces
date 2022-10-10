#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,q,x,y,r,it=1,a[100100],w[100100],s[100100],was[100100];
void add(int i, int v) {
  if (was[i]==it) return;
  was[i]=it;
  for (int j=i; j<n; j=(j<<1)-(j&(j-1))) s[j]+=v;
}
void check(int x, int v) {
  if (x>1 && w[x-1]>w[x]) add(x-1,v);
  if (x<n && w[x]>w[x+1]) add(x,v);
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) { scanf("%d",&a[i]); w[a[i]]=i; }
  for (i=1; i<n; i++) if (w[i]>w[i+1]) add(i,1);
  scanf("%d",&m);
  while (m--) {
    scanf("%d%d%d",&q,&x,&y);
	if (q==1) {
	  r=1;
	  for (j=y-1; j>0; j&=j-1) r+=s[j];
	  for (j=x-1; j>0; j&=j-1) r-=s[j];
	  printf("%d\n",r);
	} else {
	  it++;
	  check(a[x],-1);
	  check(a[y],-1);
	  swap(w[a[x]],w[a[y]]);
	  swap(a[x],a[y]);
	  it++;
	  check(a[x],1);
	  check(a[y],1);
	}
  }
  return 0;
}