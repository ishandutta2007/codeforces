//CF-fastIO
//CFR632-E
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

int key[8][8]={
  {4,3,6,12},
  {7,5,9,15},
  {14,1,11,10},
  {13,8,16,2}
};

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int i,j,n,m,k,b,c,h,w,r=0,l,t;
  int a[512][512];
  scanf("%d",&n);
  if(n<=2){printf("-1\n");return 0;}
  if(n==3){
    printf("6 5 8\n");
    printf("7 3 4\n");
    printf("1 2 9\n");
    return 0;
  }
  t=n*n-4*4;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      a[i][j]=key[i][j]+t;
    }
  }
  if(n!=4){
    a[4][1]=t;t--;
    a[4][0]=t;t--;
    a[4][2]=t;t--;
    a[4][3]=t;t--;
    a[4][4]=t;t--;
    a[3][4]=t;t--;
    a[2][4]=t;t--;
    a[1][4]=t;t--;
    a[0][4]=t;t--;
  }
  for(i=5;i<n;i++){
    if(i%2==1){
      for(j=0;j<=i;j++){
        a[j][i]=t;t--;
      }
      for(j=i-1;j>=0;j--){
        a[i][j]=t;t--;
      }
    }
    else{
      for(j=0;j<=i;j++){
        a[i][j]=t;t--;
      }
      for(j=i-1;j>=0;j--){
        a[j][i]=t;t--;
      }
    }
  }

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(j!=0){cout << ' ';}
      cout << a[i][j];
    }cout << '\n';
  }
  return 0;
}