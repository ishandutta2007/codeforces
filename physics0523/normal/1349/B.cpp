#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<assert.h>
#include<iostream>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int i,j,n,m,k,a[524288],b,c,h,w,r=0,l,t,fl;
  
  scanf("%d",&t);
  while(t>0){
    t--;
    scanf("%d%d",&n,&k);
    if(n==1){
      scanf("%d",&a[0]);
      if(a[0]==k){cout << "yes\n";}
      else{cout << "no\n";}
      continue;
    }
    
    fl=1;
    for(i=0;i<n;i++){
      scanf("%d",&a[i]);
      if(a[i]>k){a[i]=1;}
      else if(a[i]==k){a[i]=1;fl=0;}
      else{a[i]=-1;}
    }
    if(fl==1){
      cout << "no\n";
      continue;
    }
    
    fl=0;
    for(i=0;i<n-1;i++){
      if(a[i]==1 && a[i+1]==1){fl=1;break;}
    }
    for(i=0;i<n-2;i++){
      if(a[i]==1 && a[i+2]==1){fl=1;break;}
    }
    if(fl==1){
      cout << "yes\n";
    }
    else{
      cout << "no\n";
    }
  }
  
  return 0;
}