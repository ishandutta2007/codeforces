#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
int n,m,i,j,x,y,a,b,k,r,rx,ry;
pair <string, int> c[11111];
char s[22][22];
bool q;
void convert(int xa, int ya, int xb, int yb) {
  string r="",d="";
  int i,j;
  for (i=xa; i<xb; i++) for (j=ya; j<yb; j++) r+=s[i][j];
  for (i=xb-1; i>=xa; i--) for (j=yb-1; j>=ya; j--) d+=s[i][j];
  if (d<r) r=d;
  if (xb-xa!=yb-ya) {
    c[k++]=make_pair(r,x);
    for (i=0; i<x*y; i++) r[i]='a';
  }
  for (d="",j=ya; j<yb; j++) for (i=xb-1; i>=xa; i--) d+=s[i][j];
  if (d<r) r=d;
  for (d="",j=yb-1; j>=ya; j--) for (i=xa; i<xb; i++) d+=s[i][j];
  if (d<r) r=d;
  c[k++]=make_pair(r,y);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (x=1; x<=n; x++) if (n%x==0) for (y=1; y<=m; y++) if (m%y==0) {
    for (k=a=0; a*x<n; a++) for (b=0; b*y<m; b++) convert(a*x,b*y,(a+1)*x,(b+1)*y);
    sort(c,c+k); q=true;
    for (i=1; i<k; i++) if (c[i]==c[i-1]) { q=false; break; }
    if (q) if (++r==1 || x*y<rx*ry) { rx=x; ry=y; }
  }
  printf("%d\n%d %d\n",r,rx,ry);
  return 0;

}