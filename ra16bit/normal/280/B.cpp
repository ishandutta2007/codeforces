#include <cstdio>
#include <algorithm>
using namespace std;
int i,n,t,r,a[100100],s[100100];
void process() {
  for (t=i=0; i<n; i++) {
    for (; t>0 && a[i]>s[t]; t--) r=max(r,a[i]^s[t]);
	s[++t]=a[i];
  }
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  process();
  reverse(a,a+n);
  process();
  printf("%d\n",r);
  return 0;
}