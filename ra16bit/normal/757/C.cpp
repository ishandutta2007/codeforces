#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,pair<int,int> > pii;
const int md[2]={1000000007, 1000000009};
const long long K[2]={100003, 100007};
int n,m,x,i,j,k,e,r,tot,f0,cur,a[1000100][2],c[1000100];
long long fact[1000100];
pii all[1000100];
int main() {
  for (fact[0]=i=1; i<1000100; i++) fact[i]=(fact[i-1]*i)%md[0];
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%d",&k);
    for (j=0; j<k; j++) {
      scanf("%d",&x);
      for (e=0; e<2; e++) a[x][e]=(a[x][e]*K[e]+i)%md[e];
      c[x]++;
    }
  }
  for (i=1; i<=m; i++) if (c[i]==0) f0++; else all[tot++]=make_pair(c[i],make_pair(a[i][0],a[i][1]));
  r=fact[f0];
  sort(all,all+tot);
  for (i=0; i<tot; i=j) {
    for (j=i; j<tot && all[i]==all[j]; j++);
    r=(r*fact[j-i])%md[0];
  }
  printf("%d\n",r);
  return 0;
}