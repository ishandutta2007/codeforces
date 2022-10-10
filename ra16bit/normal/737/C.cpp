#include <cstdio>
#include <algorithm>
using namespace std;
int n,x,i,a,m,z,r,cnt[200200],e[200200],s[200200];
int main() {
  scanf("%d%d",&n,&x);
  for (i=1; i<=n; i++) {
    scanf("%d",&a);
    if (i==x) {
      if (a!=0) m=1;
    } else if (a==0) z++; else cnt[a]++;
  }
  if (n==1) {
    printf("%d\n",m);
    return 0;
  }
  for (i=1; i<n; i++) {
    e[i]=e[i-1]+int(cnt[i]==0);
    s[i]=s[i-1]+cnt[i];
  }
  for (r=n, i=1; i<n; i++) r=min(r,m+z+max(e[i]-z,s[n-1]-s[i]));
  printf("%d\n",r);
  return 0;
}