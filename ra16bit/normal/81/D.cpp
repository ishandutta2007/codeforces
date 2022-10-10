#include <cstdio>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
int n,m,i,j,a[1010],b[1010];
pair <int, int> x,y,z;
set <pair <int, int> > s;
bool q;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) scanf("%d",&a[i]);
  for (j=0; j<m; j++) {
    s.clear(); b[0]=j+1; q=true;
    for (i=0; i<m; i++) if (i!=j) s.insert(make_pair(-a[i],i+1)); else if (a[i]>1) s.insert(make_pair(-a[i]+1,i+1));
    for (i=1; i+2<n; i+=2) {
      if (s.empty()) { q=false; break; } else { x=*s.begin(); s.erase(s.begin()); }
      if (s.empty()) { q=false; break; } else { y=*s.begin(); s.erase(s.begin()); }
      if (b[i-1]!=x.second) { b[i]=x.second; b[i+1]=y.second; } else { b[i]=y.second; b[i+1]=x.second; }
      if (x.first<-1) s.insert(make_pair(x.first+1,x.second));
      if (y.first<-1) s.insert(make_pair(y.first+1,y.second));
    }
    if (i==n-2) {
      if (s.empty()) q=false; else { x=*s.begin(); s.erase(s.begin()); }
      if (s.empty()) q=false; else { y=*s.begin(); s.erase(s.begin()); }
      if (q) {
        if (x.second!=b[i-1] && y.second!=b[0]) {
          b[i]=x.second; b[i+1]=y.second;
        } else if (x.second!=b[0] && y.second!=b[i-1]) {
          b[i]=y.second; b[i+1]=x.second;
        } else if (!s.empty()) {
          if (s.empty()) q=false; else { z=*s.begin(); s.erase(s.begin()); }
          if (x.second!=b[i-1] && z.second!=b[0]) {
            b[i]=x.second; b[i+1]=z.second;
          } else if (z.second!=b[0] && y.second!=b[i-1]) {
            b[i]=y.second; b[i+1]=z.second;
          } else if (z.second!=b[i-1] && y.second!=b[0]) {
            b[i]=z.second; b[i+1]=y.second;
          } else if (x.second!=b[0] && z.second!=b[i-1]) {
            b[i]=z.second; b[i+1]=x.second;
          } else q=false;
        } else q=false;
      }
    } else if (i==n-1) while (true) {
      if (s.empty()) { q=false; break; } else { x=*s.begin(); s.erase(s.begin()); }
      if (x.second!=b[0] && x.second!=b[i-1]) { b[i]=x.second; break; }
    }
    if (q) {
      for (i=0; i<n; i++) {
        if (i) putchar(' ');
        printf("%d",b[i]);
      }
      return 0;
    }
  }
  puts("-1");
  return 0;
}