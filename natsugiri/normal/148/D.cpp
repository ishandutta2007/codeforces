#include<cstdio>
#include<cstring>

double d[1001][1001];
double ccr(int w,int b){
  if(d[w][b]>-1)return d[w][b];
  if(b<0||w<0)return 0;
  if(w==0)return d[0][b]=0;
  if(b==0)return d[w][0]=1;
  double x=w,y=b,ans,p;
  ans=x/(x+y);
  p=y/(x+y);
  if(1<b)ans+=p*((y-1)/(x+y-1))*(x/(x+y-2))*ccr(w-1,b-2);
  if(2<b)ans+=p*((y-1)/(x+y-1))*((y-2)/(x+y-2))*ccr(w,b-3);
  return d[w][b]=ans;
}

int main(){
  int n,i,j,w,b;
  scanf("%d%d",&w,&b);
  memset(d,-1,sizeof d);
  printf("%.10f\n",ccr(w,b));
  return 0;
}