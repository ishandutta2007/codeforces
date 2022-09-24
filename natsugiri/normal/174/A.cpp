#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;


int n;
double a[111],b;


int main(){
  scanf("%d%lf",&n,&b);
  double s=b;  
  for(int i=0;i<n;i++)scanf("%lf",a+i),s+=a[i];
  s/=n;
  for(int i=0;i<n;i++)
    if(a[i]>s){puts("-1");return 0;}

  for(int i=0;i<n;i++)
    printf("%f\n",s-a[i]);
  
  return 0;
}