#include <stdio.h>
const int md=1000000007;
int n,k,r,a[11];
bool v[11];
long long pw(int a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
void rec(int l) {
  if (l==k+1) {
    int cnt=0;
	for (int i=1; i<=k; i++) if (a[i]==1) { v[i]=true; cnt++; } else v[i]=false;
    while (true) {
	  int o=cnt;
	  for (int i=1; i<=k; i++) if (v[a[i]] && (!v[i])) {
	    v[i]=true;
		cnt++;
	  }
	  if (cnt==o) break;
	}
	if (cnt==k) r++;
    return;
  }
  for (int i=1; i<=k; i++) {
	a[l]=i;
	rec(l+1);
  }
}
int main() {
  scanf("%d%d",&n,&k);
  rec(1);
  if (n>k) r=(r*pw(n-k,n-k))%md;
  printf("%d\n",r);
  return 0;
}