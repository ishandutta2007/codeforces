#include <cstdio>
#include <algorithm>
using namespace std;
int n,ii,i,j,p,cur,a[100100],b[100100],k[100100];
bool cmp(int i, int j) { return b[i]<b[j]; }
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&b[i],&a[i]);
	k[i]=i;
  }
  sort(k,k+n,cmp);
  for (ii=1; ii<n; ii++) {
    p=k[ii-1]; i=k[ii];
	for (cur=a[p], j=b[p]+1; j<=b[i]; j++) {
	  cur=(cur+3)/4;
	  if (cur<=1) break;
	}
	a[i]=max(a[i],cur);
  }
  p=b[k[n-1]]+1;
  cur=(a[k[n-1]]+3)/4;
  while (cur>1) {
    cur=(cur+3)/4;
	p++;
  }
  printf("%d\n",p);
  return 0;
}