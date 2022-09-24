#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int a, b, c, S;
double  x, y, z;
double calc(double zz){
  double l=0, r=S-zz;
  if(r<0)r=0;
  double x1, x2, y1, y2, v1, v2;
  for(int i=0; i<200; i++){
    y1=l+(r-l)/3;
    y2=l+(r-l)*2/3;
    x1=S-zz-y1;
    x2=S-zz-y2;
    v1=a*log(x1)+b*log(y1);
    v2=a*log(x2)+b*log(y2);
    if(v1<v2)l=y1;
    else r=y2;
  }
  y=l;
  x=S-zz-y;
  return v1;
}

int main(){
  scanf("%d%d%d%d", &S, &a, &b, &c);

  double l=0, r=S;
  double z1, z2, v1, v2;
  for(int i=0; i<200; i++){
    z1=l+(r-l)/3;
    z2=l+(r-l)*2/3;
    v1=calc(z1)+c*log(z1);
    v2=calc(z2)+c*log(z2);
    if(v1<v2)l=z1;
    else r=z2;
  }
  z=z1;
  printf("%.20e %.20e %.20e\n", x, y, z);
  return 0;
}