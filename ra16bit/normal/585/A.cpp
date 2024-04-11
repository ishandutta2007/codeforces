#include <cstdio>
#include <vector>
using namespace std;
int n,i,j,k,v[4040],d[4040],pp;
bool u[4040];
vector<int> r;
long long e,p[4040];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d%d",&v[i],&d[i],&pp);
    p[i]=pp;
  }
  for (i=0; i<n; i++) if (!u[i]) {
    r.push_back(i+1);
    for (j=i+1, k=v[i]; j<n && k>0; j++) if (!u[j]) {
      p[j]-=k;
      k--;
    }
    for (j=i+1, e=0; j<n; j++) if (!u[j]) {
      p[j]-=e;
      if (p[j]<0) {
        u[j]=true;
        e+=d[j];
      }
    }
  }
  printf("%d\n",int(r.size()));
  for (i=0; i<r.size(); i++) printf("%d ",r[i]);
  return 0;
}