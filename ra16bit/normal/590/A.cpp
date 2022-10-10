#include <cstdio>
#include <vector>
using namespace std;
int n,i,m,j,c,d,r,a[500500];
vector<int> b,e;
bool o;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    if (i>0) {
      if (a[i]==a[i-1]) {
        if (o) { e.push_back(i-1); o=false; }
      } else if (!o) {
        b.push_back(i); o=true;
      }
    }
  }
  if (o) e.push_back(n-1);
  m=b.size();
  for (i=0; i<m; i++) {
    c=(b[i]+e[i])/2;
    r=max(r,e[i]-c);
    d=a[b[i]-1];
    for (j=b[i]; j<c; j++) a[j]=d;
    for (d=a[e[i]]; j<e[i]; j++) a[j]=d;
  }
  printf("%d\n",r);
  for (i=0; i<n; i++) printf("%d%c",a[i],(i==n-1)?'\n':' ');
  return 0;
}