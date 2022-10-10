#include <bits/stdc++.h>
using namespace std;
int n,s,x,i,best,up,a[100100],v[100100],nx[100100];
int main() {
  srand(time(0));
  scanf("%d%d%d",&n,&s,&x);
  a[0]=s;
  for (i=1; i<n; i++) a[i]=i+int(i>=s);
  random_shuffle(a+1,a+n);
  best=up=-1;
  for (i=0; i<n && i<1200; i++) {
    printf("? %d\n",a[i]);
    fflush(stdout);
    scanf("%d %d",&v[i],&nx[i]);
    if (v[i]<x) {
      if (best==-1 || v[i]>v[best]) best=i;
    } else {
      if (up==-1 || v[i]<v[up]) up=i;
    }
  }
  if (best!=-1) for (best=nx[best]; best!=-1 && i<1998; best=nx[best], i++) {
    printf("? %d\n",best);
    fflush(stdout);
    scanf("%d %d",&v[best],&nx[best]);
    if (v[best]>=x) break;
  }
  if (best==-1 || i>=1998) printf("! %d\n",(up==-1)?-1:v[up]); else printf("! %d\n",v[best]);
  return 0;
}