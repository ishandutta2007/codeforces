#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int n,a[5050],f[5050],p[2010][700],r[700],i,j,k,x,y;
vector <pair <int, int> > b;
char s[8];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s %d",&s,&a[i]);
    if (s[0]=='s') {
      b.push_back(make_pair(a[i],i));
      a[i]=-1;
    }
  }
  p[0][0]=1; p[0][1]=1;
  for (i=0; i<2000; i++) {
    for (j=1; j<=p[i][0]; j++) p[i+1][j]=p[i][j]*2;
    for (j=1; j<=p[i][0]; j++) if (p[i+1][j]>9) {
      p[i+1][j]-=10; p[i+1][j+1]++;
    }
    p[i+1][0]=p[i][0];
    if (p[i+1][p[i][0]+1]>0) p[i+1][0]++;
  }
  sort(b.rbegin(),b.rend()); r[0]=1;
  for (i=0; i<b.size(); i++) {
    x=b[i].first; y=b[i].second;
    for (j=y-1; j>=0 && a[j]!=-2; j--) if (a[j]==x) {
      for (; j<=y; j++) a[j]=-2;
      r[0]=max(p[x][0],r[0]);
      for (k=1; k<=r[0]; k++) {
        r[k]+=p[x][k];
        if (r[k]>9) { r[k+1]++; r[k]-=10; }
      }
      if (r[r[0]+1]>0) r[0]++;
      break;
    }
  }
  for (i=r[0]; i>=1; i--) printf("%d",r[i]);
  return 0;
}