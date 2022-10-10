#include <cstdio>
#include <vector>
using namespace std;
int n,i,j,y,md,all,last,res,k[2],a[2][200200];
vector <pair <int, int> > s;
long long x;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d%I64d%d%d",&k[i],&a[i][1],&x,&y,&md);
    for (j=2; j<=k[i]; j++) a[i][j]=(a[i][j-1]*x+y)%md;
    all+=k[i];
  }
  x=y=1;
  for (i=0; i<all; i++) if (x<=k[0] && (y>k[1] || ((a[0][x]>=last && (a[0][x]<=a[1][y] || a[1][y]<last)) || (a[0][x]<last && a[1][y]<last && a[0][x]<=a[1][y])))) {
    if (a[0][x]<last) res++;
    last=a[0][x];
    if (all<=200000) s.push_back(make_pair(a[0][x++],1));
  } else {
    if (a[1][y]<last) res++;
    last=a[1][y];
    if (all<=200000) s.push_back(make_pair(a[1][y++],2));
  }
  printf("%d\n",res);
  for (i=0; i<s.size(); i++) printf("%d %d\n",s[i].first,s[i].second);
  return 0;
}