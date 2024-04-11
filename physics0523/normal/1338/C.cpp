//CF-fastIO
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

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

void ftrip(long long n,long long res[]){
  long long d=1,k=1,t;
  while(n>k){n-=k;k*=4;d++;}
  res[0]=k+n-1;
  res[1]=2*k;
  t=res[0]-k;
  k=1;
  while(t>0){
    if(t%4==0){res[1]+=0*k;}
    if(t%4==1){res[1]+=2*k;}
    if(t%4==2){res[1]+=3*k;}
    if(t%4==3){res[1]+=1*k;}
    t/=4;k*=4;
  }
  res[2]=res[0]^res[1];
  return;
}

long long ask(long long n){
  long long res[4];
  if(n==1){return 1;}
  if(n==2){return 2;}
  if(n==3){return 3;}
  ftrip(llceil(n,3),res);
  if(n%3==1){return res[0];}
  else if(n%3==2){return res[1];}
  else{return res[2];}
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long i,j,n,m,k,a,b,c,h,w,r=0,l,t;
  scanf("%lld",&t);
  while(t>0){
    t--;
    scanf("%lld",&n);
    cout << ask(n) << '\n';
  }
  return 0;
}