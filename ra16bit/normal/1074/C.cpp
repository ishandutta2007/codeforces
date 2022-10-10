#include <bits/stdc++.h>
using namespace std;
int n,mx,nx,i,r;
pair<int,int> a[300300];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d%d",&a[i].first,&a[i].second);
  sort(a,a+n);
  mx=nx=a[0].second;
  for (i=1; i<n; i++) {
    r=max(r,a[i].first-a[0].first+a[i].second-nx);
	r=max(r,a[i].first-a[0].first+mx-a[i].second);
    mx=max(mx,a[i].second);
    nx=min(nx,a[i].second);
  }
  mx=nx=a[n-1].second;
  for (i=n-2; i>=0; i--) {
    r=max(r,a[n-1].first-a[i].first+a[i].second-nx);
	r=max(r,a[n-1].first-a[i].first+mx-a[i].second);
	mx=max(mx,a[i].second);
    nx=min(nx,a[i].second);
  }
  printf("%d",2*r);
  r=2*(a[n-1].first-a[0].first+mx-nx);
  for (i=4; i<=n; i++) printf(" %d",r);
  return 0;
}