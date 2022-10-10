#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
int n,i,m,xa[111],ya[111],xb[111],yb[111],xc[111],yc[111];
long long a,b,c,A,B,C;
pair<pair <double,double>,int> o[10100];
double r,eps=1e-7,eps2=1e-5;
bool u[111];
bool cmp(pair<pair <double,double>,bool> a, pair<pair<double,double>,bool> b) {
  if (fabs(a.first.first-b.first.first)>eps) return a.first.first<b.first.first;
  if (fabs(a.first.second-b.first.second)>eps) return a.first.second<b.first.second;
  return a.second<b.second;
}
void intersect(int ii, int xa, int ya, int xb, int yb) {
  double z1=xa*a+ya*b+c,z2=xb*a+yb*b+c,e,x,y;
  if (z1*z2<-eps2) {
    A=yb-ya; B=xa-xb; C=-xa*A-ya*B;
    if (A!=0) {
      e=double(a)/double(A);
      y=(-c+e*C)/(b-e*B);
      x=(-B*y-C)/double(A);
    } else {
      e=double(A)/double(a);
      y=(-C+e*c)/(B-e*b);
      x=(-b*y-c)/double(a);
    }
    o[m].first.first=x;
    o[m].first.second=y;
    o[m++].second=ii;
  }
}
void other(int ii, int xa, int ya, int xb, int yb, int xc, int yc) {
  if (a*xa+b*ya+c!=0) return;
  double z1=xc*a+yc*b+c,z2=xb*a+yb*b+c,e,x,y;
  if (z1*z2<-eps2) {
    o[m].first.first=double(xa);
    o[m].first.second=double(ya);
    o[m++].second=ii;
  }
}
double sqr(double x) { return x*x; }
void solve(int ii, int xA, int yA, int xB, int yB) {
  int i,j;
  a=yB-yA; b=xA-xB; c=-xA*a-yA*b;
  for (i=m=0; i<n; i++) if (i!=ii) {
    intersect(i,xa[i],ya[i],xb[i],yb[i]);
    intersect(i,xa[i],ya[i],xc[i],yc[i]);
    intersect(i,xc[i],yc[i],xb[i],yb[i]);
    other(i,xa[i],ya[i],xb[i],yb[i],xc[i],yc[i]);
    other(i,xb[i],yb[i],xc[i],yc[i],xa[i],ya[i]);
    other(i,xc[i],yc[i],xa[i],ya[i],xb[i],yb[i]);
  }
  double x,y;
  if (a!=0) {
    y=-1e7; x=double(-c-b*y)/double(a);
    o[m++]=make_pair(make_pair(x,y),n);
    y=1e7; x=double(-c-b*y)/double(a);
    o[m++]=make_pair(make_pair(x,y),n);
  } else {
    x=-1e7; y=double(-c-a*x)/double(b);
    o[m++]=make_pair(make_pair(x,y),n);
    x=1e7; y=double(-c-a*x)/double(b);
    o[m++]=make_pair(make_pair(x,y),n);
  }
  o[m++]=make_pair(make_pair(double(xA),double(yA)),n);
  o[m++]=make_pair(make_pair(double(xB),double(yB)),n);
  sort(o,o+m,cmp);
  for (i=j=0; i<m; i++) {
    if (u[o[i].second]) j--; else j++;
    u[o[i].second]=!u[o[i].second];
    if (j==0 && i<m-1) r+=sqrt(sqr(o[i+1].first.first-o[i].first.first)+sqr(o[i+1].first.second-o[i].first.second));
  }
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d%d%d%d%d%d",&xa[i],&ya[i],&xb[i],&yb[i],&xc[i],&yc[i]);
  for (i=0; i<n; i++) {
    solve(i,xa[i],ya[i],xb[i],yb[i]);
    solve(i,xa[i],ya[i],xc[i],yc[i]);
    solve(i,xc[i],yc[i],xb[i],yb[i]);
  }
  printf("%.10lf\n",r);
  return 0;
}