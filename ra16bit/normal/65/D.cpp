#include <cstdio>
#include <set>
#include <utility>
using namespace std;
int n,i,j,k,p,q,a[4],fi,fr,qx[11000000];
set <pair <int, long long> > st;
long long m,qy[11000000],z=(1<<15)-1;
char s[10101];
bool b[4];
void ins() {
  int j;
  q=1000000;
  for (j=m=0; j<4; j++) if (a[j]<q) q=a[j];
  for (j=3; j>=0; j--) m=(m<<15)+(a[j]-q);
  if (st.find(make_pair(i+1,m))==st.end()) {
    qx[fr]=i+1; qy[fr++]=m;
    st.insert(make_pair(i+1,m));
  }
}
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  fi=0; fr=1; qx[0]=0; qy[0]=0;
  while (fi<fr) {
    i=qx[fi];
    m=qy[fi++];
    for (j=0; j<4; j++) { a[j]=m&z; m>>=15; }
    if (i==n) {
      for (j=0; j<4; j++) if (a[j]<p) p=a[j];
      for (j=0; j<4; j++) if (a[j]==p) b[j]=true;
    } else if (s[i]=='?') {
      p=1000000;
      for (j=0; j<4; j++) if (a[j]<p) p=a[j];
      for (j=0; j<4; j++) if (a[j]==p) { a[j]++; ins(); a[j]--; }
    } else {
      if (s[i]=='G') a[0]++;
      if (s[i]=='H') a[1]++;
      if (s[i]=='R') a[2]++;
      if (s[i]=='S') a[3]++;
      ins();
    }
  }
  for (k=0; k<4; k++) if (b[k]) {
    if (k==0) puts("Gryffindor");
    if (k==1) puts("Hufflepuff");
    if (k==2) puts("Ravenclaw");
    if (k==3) puts("Slytherin");
  }
  return 0;
}