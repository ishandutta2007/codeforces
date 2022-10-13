//CF-fastIO-2
//CFR632-F
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

void prarr(int arr[],int n){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int i;
  for(i=0;i<n;i++){
    if(i){cout << ' ';}
    cout << arr[i];
  }
  cout << '\n';
  return;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int i,j,n,m,k,a,b,c,h,w,r=0,l,t;
  int res[524288];
  int fl[524288]={0};
  scanf("%d",&n);
  c=n-2;
  res[c]=n/2;
  for(i=n/2;i>=1;i--){
    for(j=2*i;j<=n;j+=i){
      if(fl[j]==1){continue;}
      fl[j]=1;
      c--;
      res[c]=i;
      if(c==0){break;}
    }
    if(c==0){break;}
    res[c]=i-1;
  }
  res[0]=1;
  prarr(res,n-1);
  return 0;
}