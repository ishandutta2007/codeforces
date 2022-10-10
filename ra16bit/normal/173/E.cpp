#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=100100;
struct query { int l,r,z,i; } q[MX];
int n,k,i,j,x,y,p,cur,ages,m,a[MX],r[MX],age[MX],ind[MX],g[MX],sa[MX],ma[MX],ml[MX],mr[MX],ans[MX];
int findmax(int left, int right) {
  if (left>right) return -1;
  int l=lower_bound(age,age+ages,left)-age+1,res=-1;
  int r=upper_bound(age,age+ages,right)-age,p,next;
  if (l>r) return -1;
  for (p=l; ; p=next) {
    next=(p<<1)-(p&(p-1));
    if (next>r) break;
    res=max(res,mr[p]);
  }
  res=max(res,ma[p]);
  for (p=r; ; p=next) {
    next=(p&(p-1));
    if (next<l) break;
    res=max(res,ml[p]);
  }
  return max(res,ma[p]);
}
void modify(int x, int v) {
  x=lower_bound(age,age+ages,x)-age+1;
  ma[x]=max(ma[x],v);
  for (int p=x; p<=ages; p=(p<<1)-(p&(p-1))) ml[p]=max(ml[p],v);
  for (int p=x; p>0; p&=p-1) mr[p]=max(mr[p],v);
}
bool byresp(int i, int j) {
  return r[i]<r[j];
}
bool queries(query x, query y) {
  return x.z>y.z;
}
int main() {
  scanf("%d%d",&n,&k);
  for (i=0; i<n; i++) scanf("%d",&r[i]);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    ind[i]=i;
    age[ages++]=a[i];
  }
  sort(age,age+ages);
  ages=unique(age,age+ages)-age;
  sort(ind,ind+n,byresp);
  for (i=0; i<n; i++) {
    cur=ind[i];
    if (i==0 || r[cur]!=r[ind[i-1]]) for (j=i; j<n && r[ind[j]]==r[cur]; j++) {
      x=lower_bound(age,age+ages,a[ind[j]])-age+1;
      //printf("mod %d\n",x);
      for (p=x; p<=ages; p=(p<<1)-(p&(p-1))) sa[p]++;
    }
    x=upper_bound(age,age+ages,a[cur]+k)-age;
    for (p=x; p>0; p&=p-1) g[cur]+=sa[p];
    //printf("fr %d\n",x);
    x=lower_bound(age,age+ages,a[cur]-k)-age;
    for (p=x; p>0; p&=p-1) g[cur]-=sa[p];
    //printf("fl %d\n",x);
  }
  scanf("%d",&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    x--; y--;
    q[i].z=max(r[x],r[y]);
    q[i].l=max(a[x],a[y])-k;
    q[i].r=min(a[x],a[y])+k;
    q[i].i=i;
  }
  sort(q,q+m,queries);
  for (i=1; i<=ages; i++) ma[i]=ml[i]=mr[i]=-1;
  for (j=0, i=n-1; i>=0; ) {
    for (cur=i; i>=0; i--) {
      if (r[ind[i]]!=r[ind[cur]]) break;
      modify(a[ind[i]],g[ind[i]]);
    }
    for (; j<m && q[j].z==r[ind[cur]]; j++) ans[q[j].i]=findmax(q[j].l,q[j].r);
  }
  for (i=0; i<m; i++) printf("%d\n",ans[i]);
  return 0;
}