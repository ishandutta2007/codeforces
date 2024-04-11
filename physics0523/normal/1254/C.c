#include<stdio.h>
#include<stdlib.h>

typedef struct{
long long key;
long long val;
long long node;
}sd;

int sdsortfnc(const void *a,const void *b){
  if(((sd*)a)->key < ((sd*)b)->key){return -1;}
  if(((sd*)a)->key > ((sd*)b)->key){return 1;}
  if(((sd*)a)->key < 0){
    if(((sd*)a)->val < ((sd*)b)->val){return -1;}
    if(((sd*)a)->val > ((sd*)b)->val){return 1;}
  }
  else{
    if(((sd*)a)->val < ((sd*)b)->val){return 1;}
    if(((sd*)a)->val > ((sd*)b)->val){return -1;}
  }
  return 0;
}

int main(void){
  long long i,j,n,m,k,a,b,c,h,w,r=0,l,t;
  sd dat[1024];
  scanf("%lld",&n);
  a=2;
  for(i=3;i<=n;i++){
    printf("2 1 %lld %lld\n",a,i);
    fflush(stdout);
    scanf("%lld",&r);
    if(r==-1){
      a=i;
    }
  }
  t=0;
  for(j=2;j<=n;j++){
    dat[j].node=j;
    if(j==a){dat[j].val=0;continue;}
    printf("1 1 %lld %lld\n",a,j);
    fflush(stdout);
    scanf("%lld",&dat[j].val);
  }
  a=2;
  for(j=3;j<=n;j++){
    if(dat[j].val>dat[a].val){
      a=j;
    }
  }
  for(j=2;j<=n;j++){
    if(a==j){dat[j].key=0;continue;}
    printf("2 1 %lld %lld\n",a,j);
    fflush(stdout);
    scanf("%lld",&dat[j].key);
  }
  qsort(&dat[2],n-1,sizeof(dat[2]),sdsortfnc);
  printf("0 1");
  for(j=2;j<=n;j++){
    printf(" %lld",dat[j].node);
  }
  printf("\n");
  fflush(stdout);
  return 0;
}