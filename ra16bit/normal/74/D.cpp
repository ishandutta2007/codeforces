#include <set>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node { int l,r,s; } a[5000500];
set <pair <int, int> >::iterator st;
set <pair <int, int> > s1,s2;
map <int, int> mm;
int n,m,i,j,p,x,y,z,e,L,R,h,inf=1000000100;
int sum(int i, int l, int r, int L, int R) {
  if (l==L && r==R) return a[i].s;
  int h=(L+R)/2,s=0;
  if (l<=h && a[i].l>0) s+=sum(a[i].l,l,min(r,h),L,h);
  if (r>h && a[i].r>0) s+=sum(a[i].r,max(l,h+1),r,h+1,R);
  return s;
}
int main() {
  scanf("%d%d",&n,&m);
  s1.insert(make_pair(-n,-1));
  s2.insert(make_pair(-1,-n));
  for (i=0; i<m; i++) {
    scanf("%d",&x);
    if (x==0) {
      scanf("%d%d",&x,&y);
      printf("%d\n",sum(0,x,y,1,n));
    } else {
      if (mm[x]==0) {
        y=s1.begin()->first;
        z=s1.begin()->second;
        s1.erase(s1.begin());
        s2.erase(s2.find(make_pair(z,y)));
        y=-y; z=-z;
        mm[x]=p=(z+z+y)/2;
        j=0; L=1; R=n;
        while (L!=R) {
          h=(L+R)/2;
          a[j].s++;
          if (p<=h) {
            if (a[j].l==0) a[j].l=++e;
            j=a[j].l; R=h;
          } else {
            if (a[j].r==0) a[j].r=++e;
            j=a[j].r; L=h+1;
          }
        }
        a[j].s=1;
        if (p>z) {
          s1.insert(make_pair(z-p,-z));
          s2.insert(make_pair(-z,z-p));
        }
        if (p<z+y-1) {
          s1.insert(make_pair(p+1-z-y,-(p+1)));
          s2.insert(make_pair(-(p+1),p+1-z-y));
        }
      } else {
        p=mm[x]; mm[x]=j=0; L=1; R=n;
        while (L!=R) {
          h=(L+R)/2;
          a[j].s--;
          if (p<=h) {
            if (a[j].l==0) a[j].l=++e;
            j=a[j].l; R=h;
          } else {
            if (a[j].r==0) a[j].r=++e;
            j=a[j].r; L=h+1;
          }
        }
        a[j].s=0; L=p; R=p+1;
        st=s2.lower_bound(make_pair(-p,-inf));
        if (st!=s2.end()) {
          y=-(st->first);
          z=-(st->second);
          if (y+z==p) {
            L=y;
            s2.erase(st);
            s1.erase(s1.find(make_pair(-z,-y)));
          }
        }
        st=s2.lower_bound(make_pair(-p-1,-inf));
        if (st!=s2.end()) {
          y=-(st->first);
          z=-(st->second);
          if (y==p+1) {
            R=y+z;
            s2.erase(st);
            s1.erase(s1.find(make_pair(-z,-y)));
          }
        }
        s1.insert(make_pair(L-R,-L));
        s2.insert(make_pair(-L,L-R));
      }
    }
  }
  return 0;
}