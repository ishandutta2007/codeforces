#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<double,double> pdd;
const double pi=acos(-1.0);
int a,i,n,w,h,j;
double al,s;
vector<pdd> A,B,r;
bool cmp(pdd a, pdd b) {
  double aa=atan2(a.second,a.first);
  double bb=atan2(b.second,b.first);
  return aa<bb;
}
void rotate(double x, double y) {
  B.push_back(make_pair(x*cos(al)-y*sin(al),x*sin(al)+y*cos(al)));
}
int sgn(double x) {
  if (x<0) return -1;
  if (x>0) return +1;
  return 0;
}
void intersect(double xal, double yal, double xar, double yar, double xbl, double ybl, double xbr, double ybr) {
  double A=yal-yar,B=xar-xal,C=-A*xal-B*yal;
  if (sgn(A*xbl+B*ybl+C)*sgn(A*xbr+B*ybr+C)!=-1) return;
  double dA=ybl-ybr,dB=xbr-xbl,dC=-dA*xbl-dB*ybl,x,y;
  if (sgn(dA*xal+dB*yal+dC)*sgn(dA*xar+dB*yar+dC)!=-1) return;
  if (fabs(A)>1e-10) {
    y=((dA*C)/A-dC)/(dB-(dA*B)/A);
	x=(-B*y-C)/A;
  } else {
    y=((A*dC)/dA-C)/(B-(A*dB)/dA);
	x=(-dB*y-dC)/dA;
  }
  r.push_back(make_pair(x,y));
}
int main() {
  scanf("%d%d%d",&w,&h,&a);
  if (a==0 || a==180 || (a==90 && w==h)) {
    printf("%.8lf\n",double(w)*double(h));
	return 0;
  }
  al=a/180.0; al*=pi;
  A.push_back(make_pair(w*0.5,h*0.5));
  A.push_back(make_pair(w*0.5,-h*0.5));
  A.push_back(make_pair(-w*0.5,-h*0.5));
  A.push_back(make_pair(-w*0.5,h*0.5));
  for (i=0; i<4; i++) rotate(A[i].first,A[i].second);
  for (i=0; i<4; i++) for (j=0; j<4; j++) intersect(A[i].first,A[i].second,A[(i+1)%4].first,A[(i+1)%4].second,B[j].first,B[j].second,B[(j+1)%4].first,B[(j+1)%4].second);
  sort(r.begin(),r.end(),cmp);
  n=r.size();
  r.push_back(r[0]);
  for (i=0; i<n; i++) s+=(r[i].first-r[i+1].first)*(r[i].second+r[i+1].second);
  printf("%.8lf\n",fabs(s*0.5));
  return 0;
}