#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,k,x,y,a[4000000],b[4000000],c[4000000],s[4000000];
double r;
char z[7];
long long j;
void add(int d, int i) {
  if (d>=0) {
    if (x&(1<<d)) {
      if (c[i]==0) c[i]=++k;
      add(d-1,c[i]);
    } else {
      if (b[i]==0) b[i]=++k;
      add(d-1,b[i]);
    }
  } else a[i]+=y;
  s[i]=a[i];
  if (b[i]!=0) s[i]+=s[b[i]];
  if (c[i]!=0) s[i]+=s[c[i]]; //printf("%d %d = %d %d (%d %d)\n",d,i,a[i],s[i],b[i],c[i]);
}
void decay(int i, double p, int m) {
  if (s[b[i]]>s[c[i]]) {
    r+=p*max(m,s[i]-s[c[i]]);
    if (b[i]==0) r+=p*max(m,s[i]-s[b[i]]); else decay(b[i],p*0.5,max(m,s[i]-s[b[i]]));
  } else {
    r+=p*max(m,s[i]-s[b[i]]);
    if (c[i]==0) r+=p*max(m,s[i]-s[c[i]]); else decay(c[i],p*0.5,max(m,s[i]-s[c[i]]));
  }
}
int main() {
  scanf("%d%d",&n,&m); k=1;
  for (i=0; i<m; i++) {
    scanf("%s",z); r=0;
    if (z[0]=='a') {
      scanf("%d%d",&x,&y);
      for (j=0; (1LL<<j)<=x; j++);
      add(j-2,1);
    } else {
      decay(1,0.5,0);
      printf("%.5lf\n",r);
    }
  }
  return 0;
}