#include <cstdio>
#include <vector>
using namespace std;
int n,i,j,k,x,y;
vector<int> a[26][2];
char s[2][200200];
long double cur,p,q;
long double sqr(long double x) { return x*x; }
int main() {
  scanf("%d",&n);
  for (i=0; i<2; i++) {
    scanf("%s",s[i]);
    for (j=0; j<n; j++) a[s[i][j]-'A'][i].push_back(j);
  }
  for (i=0; i<n; i++) q+=sqr(n-i);
  for (i=0; i<26; i++) {
    for (j=0; j<2; j++) {
      k=1-j;
      for (cur=y=0; y<a[i][k].size(); y++) cur+=n-a[i][k][y];
      for (x=y=0; x<a[i][j].size(); x++) {
        while (y<a[i][k].size() && a[i][k][y]<=a[i][j][x]) {
          cur-=n-a[i][k][y];
          y++;
        }
        p+=cur*(a[i][j][x]+1LL);
      }
    }
    for (x=y=0; x<a[i][0].size(); x++) {
      while (y<a[i][1].size() && a[i][1][y]<a[i][0][x]) y++;
      if (y>=a[i][1].size()) break;
      if (a[i][0][x]==a[i][1][y]) p+=(a[i][0][x]+1LL)*(n-a[i][0][x]);
    }
  }
  printf("%.15lf\n",double(p/q));
  return 0;
}