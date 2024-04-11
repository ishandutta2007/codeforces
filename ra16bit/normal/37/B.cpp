#include <cstdio>
#include <vector>
using namespace std;
int z,sm,m,n,r,i,j,res,p[1111],d[1111];
bool u[1111],q;
vector <int> r1,r2;
int main() {
  scanf("%d%d%d",&n,&m,&r); sm=m;
  for (i=0; i<n; i++) scanf("%d%d",&p[i],&d[i]);
  while (m>0) {
    q=true; m-=z; m+=r;
    if (m>sm) m=sm;
    if (m<=0) break;
    for (i=j=0; i<n; i++) if (p[i]*sm>=m*100 && (!u[i]) && (q || d[i]>d[j])) {
      q=false; j=i;
    }
    if (q && z<=r) break;
    if (!q) {
      z+=d[j]; u[j]=true;
      r1.push_back(res);
      r2.push_back(j+1);
    }
    res++;
  }
  if (m>0) puts("NO"); else {
    puts("YES");
    printf("%d %d\n",res,int(r1.size()));
    for (i=0; i<r1.size(); i++) printf("%d %d\n",r1[i],r2[i]);
  }
  return 0;
}