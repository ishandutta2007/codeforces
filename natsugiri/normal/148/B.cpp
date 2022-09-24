#include<cstdio>
int p,d,t,f,c;
int ika(double s){
  double x=s/(d-p);
  if(x*p+s+(1e-9)>=c)return 0;
  return 1+ika(s+(x*2+f)*p);
}

int main(){

  scanf("%d%d%d%d%d",&p,&d,&t,&f,&c);
  if(d<=p)puts("0");
  else printf("%d",ika(t*p));
  return 0;
}