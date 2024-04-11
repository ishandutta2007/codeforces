#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int n,v,i,r,d=-1,d2=-1,e=-1,x,x2,y,a[110000],b[110000],k[110000];
bool q=false,u[110000];
bool cmp(int i, int j) {
  return (3-a[i])*b[i]>(3-a[j])*b[j];
}
int main() {
  scanf("%d%d",&n,&v);
  for (i=0; i<n; i++) { scanf("%d%d",&a[i],&b[i]); k[i]=i; }
  sort(k,k+n,cmp);
  for (i=0; i<n; i++) if (a[k[i]]<=v) {
    v-=a[k[i]]; r+=b[k[i]];
	if (a[k[i]]==1) { d2=d; d=k[i]; }
    u[k[i]]=true;
  } else if (a[k[i]]==2 && e==-1) e=k[i];
  if (v==1 && e!=-1 && d!=-1) {
	  if (b[e]>b[d]) { u[d]=false; u[e]=true; r=r-b[d]+b[e]; }
  } else if (v==0 && e!=-1 && d!=-1 && d2!=-1) {
	  if (b[e]>b[d]+b[d2]) { u[d]=false; u[d2]=false; u[e]=true; r=r-b[d]-b[d2]+b[e]; }
  }
  printf("%d\n",r);
  for (i=0; i<n; i++) if (u[i]) printf("%d ",i+1);
  return 0;
}