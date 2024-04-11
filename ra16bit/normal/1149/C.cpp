#include <bits/stdc++.h>
using namespace std;
struct Node { int a,x,y,xy,yz,xyz; } a[550550];
int n,q,i,x,y,z[200200];
char s[200200];
void init(int i, int l, int r) {
  if (l==r) {
    a[i].x=z[r];
	a[i].y=-2*z[r];
	a[i].xy=-z[r];
	a[i].yz=-z[r];
    return;
  }
  int h=(l+r)/2;
  init(i*2,l,h);
  init(i*2+1,h+1,r);
  a[i].x=max(a[i*2].x,a[i*2+1].x)+a[i].a;
  a[i].y=max(a[i*2].y,a[i*2+1].y)-2*a[i].a;
  a[i].xy=max(max(a[i*2].xy,a[i*2+1].xy),a[i*2].x+a[i*2+1].y)-a[i].a;
  a[i].yz=max(max(a[i*2].yz,a[i*2+1].yz),a[i*2].y+a[i*2+1].x)-a[i].a;
  a[i].xyz=max(max(a[i*2].xyz,a[i*2+1].xyz),max(a[i*2].xy+a[i*2+1].x,a[i*2].x+a[i*2+1].yz));
}
void add(int i, int l, int r, int le, int ri, int v) {
  if (l==le && r==ri) {
    a[i].a+=v;
    a[i].x+=v;
	a[i].y-=2*v;
	a[i].xy-=v;
	a[i].yz-=v;
    return;
  }
  int h=(l+r)/2;
  if (le<=h) add(i*2,l,h,le,min(ri,h),v);
  if (ri>h) add(i*2+1,h+1,r,max(h+1,le),ri,v);
  a[i].x=max(a[i*2].x,a[i*2+1].x)+a[i].a;
  a[i].y=max(a[i*2].y,a[i*2+1].y)-2*a[i].a;
  a[i].xy=max(max(a[i*2].xy,a[i*2+1].xy),a[i*2].x+a[i*2+1].y)-a[i].a;
  a[i].yz=max(max(a[i*2].yz,a[i*2+1].yz),a[i*2].y+a[i*2+1].x)-a[i].a;
  a[i].xyz=max(max(a[i*2].xyz,a[i*2+1].xyz),max(a[i*2].xy+a[i*2+1].x,a[i*2].x+a[i*2+1].yz));
}
int main() {
  scanf("%d%d",&n,&q);
  scanf("%s",s);
  n=2*(n-1);
  for (z[0]=i=1; i<=n; i++) if (s[i-1]=='(') z[i]=z[i-1]+1; else z[i]=z[i-1]-1;
  init(1,0,n);
  printf("%d\n",a[1].xyz);
  while (q--) {
    scanf("%d%d",&x,&y);
	if (x>y) swap(x,y);
	if (s[x-1]!=s[y-1]) {
	  swap(s[x-1],s[y-1]);
	  add(1,0,n,x,y-1,(s[x-1]=='(')?2:-2);
	}
	printf("%d\n",a[1].xyz);
  }
  return 0;
}