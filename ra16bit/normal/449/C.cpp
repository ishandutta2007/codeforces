#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,m,cur,a,l;
pair<int,int> r[100100];
bool u[100100];
int main() {
  scanf("%d",&n);
  u[2]=true;
  for (a=i=2; i*2<=n; i++) if (!u[i]) {
    cur=0;
    for (j=i; j<=n; j+=i) if (!u[j]) cur++;
    if (cur%2) {
      u[2*i]=true;
      if (a) {
        r[m++]=make_pair(a,2*i);
        a=0;
      } else a=2*i;
    }
    for (j=i; j<=n; j+=i) if (!u[j]) {
      u[j]=true;
      if (l) {
        r[m++]=make_pair(l,j);
        l=0;
      } else l=j;
    }
  }
  for (i=2; i<=n; i+=2) if (!u[i]) {
    if (a) {
      r[m++]=make_pair(a,i);
      a=0;
    } else a=i;
  }
  printf("%d\n",m);
  for (i=0; i<m; i++) printf("%d %d\n",r[i].first,r[i].second);
  return 0;
}