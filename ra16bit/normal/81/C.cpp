#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,a,b,c[100100],k[100100],r[100100];
bool cmpa(int i, int j) { return c[i]<c[j] || (c[i]==c[j] && i<j); }
bool cmpb(int i, int j) { return c[i]>c[j] || (c[i]==c[j] && i<j); }
int main() {
  scanf("%d%d%d",&n,&a,&b);
  for (i=0; i<n; i++) { scanf("%d",&c[i]); k[i]=i; }
  if (a==b) {
    for (i=0; i<a; i++) r[i]=1;
    for (i=a; i<n; i++) r[i]=2;
  } else {
    if (a>b) sort(k,k+n,cmpa); else sort(k,k+n,cmpb);
    for (i=0; i<a; i++) r[k[i]]=1;
    for (i=a; i<n; i++) r[k[i]]=2;
  }
  for (i=0; i<n; i++) {
    if (i) putchar(' ');
    printf("%d",r[i]);
  }
  return 0;
}