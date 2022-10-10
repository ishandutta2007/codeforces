#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
struct point { int a,b; } a[100000],b[100000];
int tt,n,i,j,k,m,x,y,p,z,s[100000];
bool q;
int len(point x) { return x.a*x.a+x.b*x.b; }
bool cmp(point x, point y) { return len(x)<len(y); }
bool cmpt(point x, point y) { return atan2(x.a,x.b)>atan2(y.a,y.b); }
void add(int xx, int yy) {
  if (abs(xx)+abs(yy)<abs(p)+abs(z)) {
    p=xx; z=yy;
    b[k].a=p-x;
    b[k].b=z-y;
  }
}
int main() {
  for (i=1; i<=200; i++) for (j=0; j<=i; j++) {
    a[m].a=i; a[m++].b=j;
  }
  sort(a,a+m,cmp); k=0;
  for (i=1; i<m; i++) if (cmp(a[k],a[i])) a[++k]=a[i]; else if (len(a[k])==len(a[i]) && a[k].a+a[k].b>a[i].a+a[i].b) a[k]=a[i];
  s[0]=len(a[0])&1;
  for (i=1; i<=k; i++) s[i]=(s[i-1]+len(a[i]))&1;
  scanf("%d",&n); m=k+1;
  if (s[n-1]) {
    q=true; i=n; j=s[i];
  } else {
    q=false; i=n-1;
  }
  puts("YES");
  for (x=y=k=0; i>=0; i--,k++) {
    if (q && ((len(a[i])&1)==j)) { k--; q=false; continue; }
    p=z=1e7;
    add(x+a[i].a,y+a[i].b);
    add(x+a[i].a,y-a[i].b);
    add(x-a[i].a,y+a[i].b);
    add(x-a[i].a,y-a[i].b);
    add(x+a[i].b,y+a[i].a);
    add(x+a[i].b,y-a[i].a);
    add(x-a[i].b,y+a[i].a);
    add(x-a[i].b,y-a[i].a);
    x=p; y=z;
  }
  sort(b,b+k,cmpt);
  for (x=y=i=0; i<k; i++) {
    printf("%d %d\n",x,y);
    x+=b[i].a; y+=b[i].b;
  }
  return 0;
}