#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,a[1010],b,d,i,j;
vector <int> c[2];
double r;
bool cmp(int i, int j) { return a[i]>a[j]; }
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%d%d",&a[i],&b);
    c[b-1].push_back(i);
  }
  for (i=0; i<2; i++) sort(c[i].begin(),c[i].end(),cmp);
  if (c[0].size()<m) {
    for (i=0; i<c[0].size(); i++) r+=0.5*a[c[0][i]];
    for (i=0; i<c[1].size(); i++) r+=a[c[1][i]];
    printf("%.1lf\n",r);
    for (i=j=0; i<c[0].size(); i++, j++) printf("%d %d\n",1,c[0][i]+1);
    for (i=0; j<m-1; i++, j++) printf("%d %d\n",1,c[1][i]+1);
    printf("%d",n-m+1);
    for (; i<c[1].size(); i++) printf(" %d",c[1][i]+1);
  } else {
    for (i=0; i<m-1; i++) r+=0.5*a[c[0][i]];
    d=2000000000;
    for (i=m-1; i<c[0].size(); i++) { r+=a[c[0][i]]; d=min(d,a[c[0][i]]); }
    for (i=0;   i<c[1].size(); i++) { r+=a[c[1][i]]; d=min(d,a[c[1][i]]); }
    printf("%.1lf\n",r-0.5*d);
    for (i=0; i<m-1; i++) printf("%d %d\n",1,c[0][i]+1);
    printf("%d",n-m+1);
    for (i=m-1; i<c[0].size(); i++) printf(" %d",c[0][i]+1);
    for (i=0;   i<c[1].size(); i++) printf(" %d",c[1][i]+1);
  }
  puts("");
  return 0;
}