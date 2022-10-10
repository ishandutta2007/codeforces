#include <cstdio>
#include <algorithm>
using namespace std;
const long long inf=2000000000LL,half=inf/2,sinf=-inf*inf;
int n,m,tot,i,r=-inf,a[44],b[44],c[44],d[44];
pair<long long, long long> all[555555];
long long rmask;
void rec(int l, int sa, int sb, int sc, int mask) {
  if (l==m) {
    all[tot++]=make_pair((half+sb-sa)*inf+(half+sc-sa),(half-sa-sb-sc)*inf+mask);
    return;
  }
  rec(l+1,sa+a[l],sb+b[l],sc,mask*3);
  rec(l+1,sa+a[l],sb,sc+c[l],mask*3+1);
  rec(l+1,sa,sb+b[l],sc+c[l],mask*3+2);
}
void rec2(int l, int sa, int sb, int sc, long long pw, int mask) {
  if (l<m) {
    long long z=(half+sa-sb)*inf+(half+sa-sc);
    int x=lower_bound(all,all+tot,make_pair(z,sinf))-all;
    if (x<tot && all[x].first==z) {
      int cs=all[x].second/inf-half;
      cs=sa+sb+sc-cs;
      if (cs>r) {
        r=cs;
        rmask=(all[x].second%inf)*pw+mask;
      }
    }
    return;
  }
  rec2(l-1,sa+a[l],sb+b[l],sc,pw*3,mask);
  rec2(l-1,sa+a[l],sb,sc+c[l],pw*3,mask+pw);
  rec2(l-1,sa,sb+b[l],sc+c[l],pw*3,mask+pw*2);
}
int main() {
  scanf("%d",&n); m=n/2;
  for (i=0; i<n; i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
  rec(0,0,0,0,0);
  sort(all,all+tot);
  rec2(n-1,0,0,0,1,0);
  if (r!=-inf) {
    for (i=0; i<n; i++, rmask/=3) d[n-i-1]=rmask%3;
    for (i=0; i<n; i++) puts(d[i]?(d[i]==1?"LW":"MW"):"LM"); 
  } else puts("Impossible");
  return 0;
}