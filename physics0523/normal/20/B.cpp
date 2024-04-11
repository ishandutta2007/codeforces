#include<bits/stdc++.h>

using namespace std;

int main(){
  long long a,b,c;
  cin >> a >> b >> c;
  if(a==0 && b==0){
    if(c==0){printf("-1\n");}
    else{printf("0\n");}
    return 0;
  }
  if(a==0){
    printf("1\n");
    double res=-c;
    res/=((double)b);
    printf("%.12lf\n",res);
    return 0;
  }
  long long d;
  d=b*b-4ll*a*c;
  if(d<0){
    printf("0\n");
    return 0;
  }
  if(d==0){
    printf("1\n");
    double res=-b;
    res/=(2.0*(double)a);
    printf("%.12lf\n",res);
    return 0;
  }
  double res=-b;
  double sd=sqrt((double)d);
  res/=(2.0*(double)a);
  sd/=(2.0*(double)a);
  double r1,r2;
  if(res<0){r1=res-sd;}
  else{r1=res+sd;}
  r2=((double)(-b)/(double)(a))-r1;
  if(r1>r2){swap(r1,r2);}
  printf("2\n");
  printf("%.12lf\n",r1);
  printf("%.12lf\n",r2);
  return 0;
}