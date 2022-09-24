#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long LL;

const double EPS=1e-9;


int main(){
  LL n,ma,mi,x,y;
  cin>>n;
  ma=(n+1)*9-n;
  x=(LL)(cbrt((double)n)+EPS);
  mi=ma;
  for(;x>0;x--){
    if(n%x==0){
      y=(LL)(sqrt((double)(n/x))+EPS);
      if(x>y)break;
      for(;y>0;y--){
	if((n/x)%y==0){
	  LL t=(x+1)*(y+2)*(n/x/y+2)-n;
	  if(mi>t)mi=t;
	}
	if(x>y)break;
      }
    }
  }
  
  cout<<mi<<' '<<ma<<endl;
  return 0;
}