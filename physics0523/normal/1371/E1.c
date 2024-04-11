#include<stdio.h>

int max(int a,int b){if(a>b){return a;}return b;}

int main(){
  int n,p;
  int st,fi;
  int a[131072],bk[262144]={0},bas=0,i,j;
  int res[131072],rc=0;
  scanf("%d%d",&n,&p);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    bas=max(a[i],bas);
  }
  for(i=0;i<n;i++){bk[max(0,a[i]-bas+n)]++;}
  for(i=1;i<262144;i++){bk[i]+=bk[i-1];}
  for(i=0;i<=n;i++){
    for(j=0;j<n;j++){
      if((bk[i+j]-j)<=0){break;}
      if((bk[i+j]-j)%p==0){break;}
      if(j==n-1){res[rc]=i+(bas-n);rc++;}
    }
  }
  printf("%d\n",rc);
  for(i=0;i<rc;i++){
    if(i){printf(" ");}
    printf("%d",res[i]);
  }printf("\n");
}