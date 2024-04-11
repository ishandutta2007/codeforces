#include <bits/stdc++.h>
using namespace std;

int main(void){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long long i,j,n,m,k,a[524288],b[524288],c,h,w,r=0,l,t,x=0;
  scanf("%lld",&n);
  for(i=0;i<n;i++){
    scanf("%lld",&b[i]);
  }
  for(i=0;i<n;i++){
    if(i==0){a[i]=b[i];}
    else{
      a[i]=x+b[i];
    }
    if(a[i]>x){x=a[i];}
  }
  for(i=0;i<n;i++){
    if(i!=0){cout << ' ';}
    cout << a[i];
  }printf("\n");
  return 0;
}