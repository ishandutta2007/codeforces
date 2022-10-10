#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
struct zakaz {
  string s;
  int t,c,i,a;
} z[111];
int n,m,k,i,j,l,r,h,x,y,p,a2,b2,a,b,t[111],v[55555],sv[55555],f[55555][111],g[55555][111],X[111],Y[111],Z[111];
string s[111];
char ss[44];
bool cmp(zakaz i, zakaz j) { return i.t<j.t; }
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=0; i<55555; i++) v[i]=1;
  for (i=0; i<n; i++) { scanf("%s",&ss); s[i]=ss; }
  for (i=0; i<n; i++) scanf("%d",&t[i]);
  for (i=0; i<4; i++) {
    scanf("%d:%d-%d:%d",&a,&a2,&b,&b2);
    a=a*60+a2; b=b*60+b2;
    for (j=0; j<k; j++) for (p=j*1440+a; p<=j*1440+b; p++) v[p]=0;
  }
  for (i=0; i<m; i++) {
    scanf("%s",&ss); z[i].s=ss; z[i].a=-1;
    for (j=0; j<n; j++) if (s[j]==z[i].s) z[i].a=t[j];
    scanf("%d",&j);  scanf("%d:%d",&a,&a2);
    z[i].t=(j-1)*1440+a*60+a2;
    scanf("%d",&z[i].c);
    z[i].i=i+1;
  }
  sv[0]=v[0];
  for (i=1; i<55555; i++) sv[i]=sv[i-1]+v[i];
  sort(z,z+m,cmp);
//  for (i=0; i<m; i++) printf("%d %d %d %d\n",z[i].a,z[i].c,z[i].i,z[i].t);
  for (i=0; i<=1440*k; i++) for (j=0; j<=m; j++) {
    if (i>0 && f[i-1][j]>f[i][j]) f[i][j]=f[i-1][j];
    if (j>0 && f[i][j-1]>f[i][j]) f[i][j]=f[i][j-1];
    if (j==m || v[i]==0 || z[j].a==-1) continue;
    x=((i>0)?sv[i-1]:0)+z[j].a;
    l=i; r=1440*k;
    while (l<r) {
      h=(l+r)/2;
      if (sv[h]<x) l=h+1; else r=h;
    }
    h=r;
    if (h<z[j].t && f[h+1][j+1]<f[i][j]+z[j].c) { f[h+1][j+1]=f[i][j]+z[j].c; g[h+1][j+1]=i; }
  }
  printf("%d\n",f[1440*k][m]); r=0;
  for (i=1440*k, j=m; i>0 && j>0; ) {
    if (f[i-1][j]==f[i][j]) { i--; continue; }
    if (f[i][j-1]==f[i][j]) { j--; continue; }
    X[r]=z[j-1].i;
    Y[r]=g[i][j];
    Z[r++]=i-1;
//    printf("%d-%d %d %d\n",g[i][j],i,z[j-1].i);
    i=g[i][j]; j--;
  }
  printf("%d\n",r);
  for (i=r-1; i>=0; i--) {
    printf("%d ",X[i]);
    printf("%d ",(Y[i]/1440)+1);
    x=(Y[i]%1440)/60; y=(Y[i]%1440)%60;
    if (x<10) putchar('0'); printf("%d:",x);
    if (y<10) putchar('0'); printf("%d ",y);
    printf("%d ",(Z[i]/1440)+1);
    x=(Z[i]%1440)/60; y=(Z[i]%1440)%60;
    if (x<10) putchar('0'); printf("%d:",x);
    if (y<10) putchar('0'); printf("%d\n",y);
  }
  return 0;
}