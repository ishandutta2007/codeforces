#include <cstdio>
#include <queue>
using namespace std;
int n,m,i,j,st,r,a[5],t[5];
priority_queue<int, vector<int>, greater<int> > q[5];
int main() {
  scanf("%d",&n);
  for (i=0; i<3; i++) {
    scanf("%d",&m);
    for (j=0; j<m; j++) q[i].push(0);
  }
  for (i=0; i<3; i++) scanf("%d",&t[i]);
  for (i=0; i<n; i++) {
    for (j=0; j<3; j++) {
      a[j]=q[j].top();
      q[j].pop();
    }
    st=max(a[0],a[1]-t[0]);
    st=max(st,a[2]-t[1]-t[0]);
    for (j=0; j<3; j++) {
      if (j) a[j]=a[j-1]; else a[j]=st;
      a[j]+=t[j];
      q[j].push(a[j]);
      r=max(r,a[j]);
    }
  }
  printf("%d\n",r);
  return 0;
}