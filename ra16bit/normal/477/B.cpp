#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int n,o,e,i,j,k,h,mm,m,r,a[500500],p[500500],x[500500];
vector<pair<pii,pii> > v;
void rem(int i) {
  int j=p[i];
  x[j]=x[i];
  p[x[i]]=j;
  if (i==h) h=x[i];
}
int main() {
  scanf("%d%d",&n,&mm);
  h=m=0;
  for (i=1; ; i++) {
    o=n;
    for (j=h; j>0 && n==o; j=p[j]) if (__gcd(i,a[j])==1) {
      for (k=p[j]; k>0 && n==o; k=p[k]) if (__gcd(i,a[k])==1 && __gcd(a[j],a[k])==1)
        for (e=p[k]; e>0 && n==o; e=p[e]) if (__gcd(i,a[e])==1 && __gcd(a[j],a[e])==1 && __gcd(a[k],a[e])==1) {
          v.push_back(make_pair(make_pair(i*mm,a[j]*mm),make_pair(a[k]*mm,a[e]*mm)));
          rem(j); rem(k); rem(e); n--; r=i;
          break;
        }
    }
    if (n==0) break;
    if (n==o) {
      a[++m]=i;
      p[m]=h;
      x[h]=m;
      h=m;
    }
  }
  printf("%d\n",r*mm);
  for (i=0; i<v.size(); i++) printf("%d %d %d %d\n",v[i].first.first,v[i].first.second,v[i].second.first,v[i].second.second);
  return 0;
}