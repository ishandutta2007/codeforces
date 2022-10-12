#include<bits/stdc++.h>

using namespace std;

int main(){
  long double h,l;
  scanf("%Lf%Lf",&h,&l);
  // x^2 + l^2 = (h+x)^2
  long double st=0,fi=1e12;
  for(int i=0;st<fi && i<200;i++){
    long double te=(st+fi)/2.0;
    // cout << te << " : ";
    // cout << te*te+l*l << " ";
    // cout << (h+te)*(h+te) << "\n";
    if(te*te + l*l < (h+te)*(h+te)){
      fi=te;
    }
    else{
      st=te;
    }
  }
  printf("%.12Lf\n",(st+fi)/2.0);
  return 0;
}