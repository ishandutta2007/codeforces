#include <cstdio>
#include <algorithm>
using namespace std;
const int md=1000000007;
int h,w,n,i,j,x,y,f[2020];
pair<int,int> a[2020];
long long fa[200200],of[200200];
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (a*pw(a,b-1))%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
long long C(int x, int y) {
  return (((fa[x]*of[y])%md)*of[x-y])%md;
}
int main() {
  for (fa[0]=of[0]=i=1; i<200200; i++) {
    fa[i]=(fa[i-1]*i)%md;
    of[i]=pw(fa[i],md-2);
  }
  scanf("%d%d%d",&h,&w,&n);
  for (i=0; i<n; i++) scanf("%d%d",&a[i].first,&a[i].second);
  sort(a,a+n);
  a[n]=make_pair(h,w);
  for (i=0; i<=n; i++) {
    x=a[i].first;
    y=a[i].second;
    f[i]=C(x+y-2,x-1);
    for (j=0; j<i; j++) if (a[j].first<=x && a[j].second<=y) {
      f[i]=(f[i]+md-(f[j]*C(x-a[j].first+y-a[j].second,x-a[j].first))%md)%md;
    }
  }
  printf("%d\n",f[n]);
  return 0;
}