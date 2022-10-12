//set many funcs template
//Ver.20190820
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

void prarr(long long arr[],long long n){
  long long i;
  for(i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << arr[i];
  }
  cout << '\n';
  return;
}

long long sig(long long ct,long long le){
  long long fe=le-ct+1;
  return ((fe+le)*ct)/2;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long i,j,n,m,k,a[1048576],b[1048576],c,h,w,r=0,l,t;
  long long st,fi,te;
  scanf("%lld",&n);
  for(i=0;i<n;i++){
    scanf("%lld",&a[i]);
    r+=a[i];
  }
  st=n-1;fi=2000000000000;
  while(st<=fi){
    te=(st+fi)/2;
    if(r>=sig(n,te)){st=te+1;}
    else{fi=te-1;}
  }
  r-=sig(n,fi);
  for(i=n-1;i>=0;i--){
    b[i]=fi;fi--;
  }
  for(i=0;i<r;i++){b[i]++;}
  prarr(b,n);
  return 0;
}