#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,a,t,i,j,l,b[2][100100],c[2][100100],m[2],x[2],res;
vector<int> r[100100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a); a--;
    b[a][++m[a]]=i;
    c[a][m[a]]=m[1-a];
  }
  for (t=1; t<=n; t++) {
    x[0]=x[1]=i=j=0;
    while (true) {
      if (i==m[0] && j==m[1]) {
        if (x[l]>x[1-l]) {
          res++;
          r[x[l]].push_back(t);
        }
        break;
      }
      if (i+t>m[0]) {
        if (j+t>m[1]) break;
        j+=t; i=c[1][j]; x[1]++; l=1;
      } else if (j+t>m[1]) {
        i+=t; j=c[0][i]; x[0]++; l=0;
      } else if (b[0][i+t]<b[1][j+t]) {
        i+=t; j=c[0][i]; x[0]++; l=0;
      } else {
        j+=t; i=c[1][j]; x[1]++; l=1;
      }
    }
  }
  printf("%d\n",res);
  for (i=1; i<=n; i++) for (j=0; j<r[i].size(); j++) printf("%d %d\n",i,r[i][j]);
  return 0;
}