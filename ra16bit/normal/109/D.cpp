#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int n,m,tot,cur,i,x,z=-1,a[100100],b[100100],p[100100],r1[200200],r2[200200],t[200200];
pair <int, int> c[100100];
bool q,u[100100];
void go(int x) {
  int i,num=0;
  for (i=x; !u[i]; i=b[i]) {
    u[i]=true;
    p[++num]=i;
  }
  if (num==1) {
    if (cur==p[1]) t[tot++]=cur;
    return;
  }
  if (cur!=p[1]) {
    swap(a[cur],a[p[1]]);
    r1[m]=cur; r2[m++]=cur=p[1];
  }
  for (i=num; i>1; i--) {
    swap(a[cur],a[p[i]]);
    r1[m]=cur; r2[m++]=cur=p[i];
  }
  t[tot++]=cur;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    if (i>0 && a[i]<a[i-1]) q=true;
    for (x=a[i]; x>0; x/=10) if (x%10!=4 && x%10!=7) break;
    if (x==0) z=i;
    c[i]=make_pair(a[i],i);
  }
  if (!q) { puts("0"); return 0; }
  if (z==-1) { puts("-1"); return 0; }
  sort(c,c+n);
  for (i=0; i<n; i++) b[c[i].second]=i;
//  for (i=0; i<n; i++) printf("%d ",b[i]); puts("");
  cur=z; go(z);
  for (i=0; i<n; i++) if (!u[i]) go(i);
  for (i=tot-2; i>=0; i--) {
    swap(a[t[i]],a[cur]);
    r1[m]=cur; r2[m++]=cur=t[i];
  }
  printf("%d\n",m);
  for (i=0; i<m; i++) printf("%d %d\n",r1[i]+1,r2[i]+1);
//  for (i=0; i<n; i++) printf("%d ",a[i]);
  return 0;
}