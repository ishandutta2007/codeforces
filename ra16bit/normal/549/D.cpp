#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,k,i,j,e,x,y,z,need,r,b[102][102];
pair<int,int> a[102*102];
char s[102][102];
bool cmp(pair<int,int> x, pair<int,int> y) {
  return x.first+x.second>y.first+y.second;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=0; i<n; i++) for (j=0; j<m; j++) a[k++]=make_pair(i,j);
  sort(a,a+k,cmp);
  for (e=0; e<k; e++) {
    x=a[e].first;
    y=a[e].second;
    for (z=j=0; j<=y; j++) z+=b[x][j];
    need=s[x][y]=='B'?-1:1;
    if (z==need) continue; else r++;
    for (i=0; i<=x; i++) {
      b[i][0]+=need-z;
      b[i][y+1]-=need-z;
    }
  }
  printf("%d\n",r);
  return 0;
}