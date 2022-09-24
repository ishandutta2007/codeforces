#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int n;

typedef long long LL;

int main(){

  cin>>n;
  LL x;
  for(x=1; ; x++) {
    LL z=x*(x+1);
    if(z>n)break;
    LL Y=-2*n+z;
    LL t=(int)(sqrt(1-4*Y)+0.5);
    if(t*t==1-4*Y && t%2==1){
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}