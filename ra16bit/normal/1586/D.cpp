#include <bits/stdc++.h>
using namespace std;
int n,i,mn,r,a[111];
int ask(int x) {
  int e,lst;
  if (x>0) {
    e=1; lst=x+1;
  } else {
    lst=1; e=-x+1;
  }
  if (e<1 || e>n || lst<1 || lst>n) return 0;
  printf("?");
  for (int i=1; i<n; i++) printf(" %d",e);
  printf(" %d\n",lst);
  fflush(stdout);
  int r;
  scanf("%d",&r);
  return r;
}
int main() {
  scanf("%d",&n);
  for (i=1; ; i++) {
    r=ask(i);
    if (r==0) break;
    a[r-1]=i;
  }
  for (i=1; ; i++) {
    r=ask(-i);
    if (r==0) break;
    a[r-1]=-i;
  }
  mn=a[0];
  for (i=1; i<n; i++) mn=min(mn,a[i]);
  printf("!");
  for (i=0; i<n; i++) printf(" %d",a[i]-mn+1);
  puts("");
  fflush(stdout);
  return 0;
}