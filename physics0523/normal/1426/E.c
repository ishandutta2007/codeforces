//set many funcs template
//Ver.20190820
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<assert.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

int max(int a,int b){if(a>b){return a;}return b;}
int min(int a,int b){if(a<b){return a;}return b;}

int main(void){
  int n;
  int a1,a2,a3;
  int b1,b2,b3;
  scanf("%d",&n);
  scanf("%d%d%d",&a1,&a2,&a3);
  scanf("%d%d%d",&b1,&b2,&b3);
  int r1,r2;
  r2=min(a1,b2)+min(a2,b3)+min(a3,b1);
  int c=b1;b1=b2;b2=b3;b3=c;
  r1=max(0,a1-b2-b3)+max(0,a2-b3-b1)+max(0,a3-b1-b2);
  printf("%d %d\n",r1,r2);
  return 0;
}