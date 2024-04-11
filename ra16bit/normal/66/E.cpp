#include <cstdio>
#include <set>
using namespace std;
int n,i,x,a[100100],b[100100],c[100100];
set <pair <int,int> > st;
set <pair <int,int> >::iterator si;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) scanf("%d",&b[i]);
  for (x=i=0; i<n; i++) {
    st.insert(make_pair(x,i));
    while (!st.empty()) {
      si=--st.end();
      if (si->first>x) {
        c[si->second]|=1;
        st.erase(si); 
      } else break;
    }
    x+=a[i]-b[i];
  }
  for (i=0; i<n; i++) {
    while (!st.empty()) {
      si=--st.end();
      if (si->first>x) {
        if (si->second>=i) c[si->second]|=1;
        st.erase(si);
      } else break;
    }
    x+=a[i]-b[i];
  }
  st.clear(); x=0;
  for (i=n-1; i>=0; i--) {
    st.insert(make_pair(x,i));
    while (!st.empty()) {
      si=--st.end();
      if (si->first>x) {
        c[si->second]|=2;
        st.erase(si); 
      } else break;
    }
    x+=a[i]-b[(i+n-1)%n];
  }
  for (i=n-1; i>=0; i--) {
    while (!st.empty()) {
      si=--st.end();
      if (si->first>x) {
        if (si->second<=i) c[si->second]|=2;
        st.erase(si);
      } else break;
    }
    x+=a[i]-b[(i+n-1)%n];
  }
  for (i=x=0; i<n; i++) if (c[i]!=3) a[x++]=i+1;
  printf("%d\n",x);
  for (i=0; i<x; i++) printf("%d ",a[i]);
  return 0;
}