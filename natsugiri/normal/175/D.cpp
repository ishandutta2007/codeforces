#include<cstdio>
#include<algorithm>

using namespace std;

double hh[310], ehh[310];

double func(double*hhh, int h, int l, int r, double p){
  double x[310];
  for(int i=0; i<=h; i++)x[i]=0;
  
  for(int i=1; i<=h; i++){
    for(int j=l; j<=r; j++)
      x[max(0, i-j)]+=hhh[i]/(r-l+1.0)*(100.0-p)/100.0;

    hhh[i]*=p/100.0;
  }
  for(int i=0; i<=h; i++)hhh[i]+=x[i];

  return x[0];
}
      

	 
int main(){
  int h, t, l, r, p, eh, et, el, er, ep;
  scanf("%d%d%d%d%d%d%d%d%d%d", &h, &t, &l, &r, &p, &eh, &et, &el, &er, &ep);
  if(p==100){puts("0.0"); return 0;}
  if(ep==100){puts("1.0"); return 0;}
  
  double ans;
  hh[h]=1;
  ehh[eh]=1;
  ans=0;
  for(int i=0, y=0; i<5000; i++, y++){
    if(y%t && y%et){
      y+=min(t-y%t, et-y%et);
      if(hh[0]>0.99999){break;}
    }
    if(y%t==0){
      func(ehh, eh, l, r, p);
      ans+=(1.0-hh[0])*ehh[0];
      ehh[0]=0;
    }
    
    if(y%et==0){
      func(hh, h, el, er, ep);
    }
  }    
  
  printf("%.6f\n", ans);
  return 0;
}