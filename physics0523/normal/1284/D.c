//set many funcs template
//Ver.20190820
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<assert.h>
#include<sys/time.h>
#define ac 64
 
void llswap(long long *a,long long *b){long long c;c=(*a);(*a)=(*b);(*b)=c;}
 
unsigned long long seed;
 
unsigned long long xorshift(){
  seed=seed^(seed<<13);
  seed=seed^(seed>>7);
  seed=seed^(seed<<17);
  return seed;
}
 
void getperm(long long a[],long long n){
  long long i,p;
  for(i=0;i<n;i++){
    a[i]=i;
  }
  for(i=n-1;i>=1;i--){
    p=xorshift()%(i+1);
    llswap(&a[p],&a[i]);
  }
}
 
typedef struct{
long long val;
long long kind;
long long id;
}sd;
 
int sdsortfnc(const void *a,const void *b){
if(((sd*)a)->val < ((sd*)b)->val){return -1;}
if(((sd*)a)->val > ((sd*)b)->val){return 1;}
if(((sd*)a)->kind < ((sd*)b)->kind){return -1;}
if(((sd*)a)->kind > ((sd*)b)->kind){return 1;}
return 0;
}
 
int main(void){
  struct timeval tv;
  gettimeofday(&tv, NULL);
  seed=(tv.tv_sec*1000000+tv.tv_usec);
  long long i,j,n,m,k,a,b,c,d,h,w,r=0,l,t;
  long long perm[262144],st;
  unsigned long long **seed=malloc(sizeof(unsigned long long*)*131072);
  unsigned long long **av=malloc(sizeof(unsigned long long*)*131072);
  unsigned long long **bv=malloc(sizeof(unsigned long long*)*131072);
  for(i=0;i<131072;i++){
    seed[i]=malloc(sizeof(unsigned long long)*ac);
    av[i]=malloc(sizeof(unsigned long long)*ac);
    bv[i]=malloc(sizeof(unsigned long long)*ac);
  }
  unsigned long long ns[ac],nf[ac],tx[ac]={0};
  sd ad[262144],bd[262144];
  scanf("%lld",&n);
  getperm(perm,2*n);
  for(i=0;i<n;i++){
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    a*=2;
    b*=2;b++;
    c*=2;
    d*=2;d++;
    for(j=0;j<ac;j++){
      seed[i][j]=xorshift();
      tx[j]^=seed[i][j];
    }
    ad[perm[i]].val=a;
    ad[perm[i]].kind=0;
    ad[perm[i]].id=i;
    ad[perm[n+i]].val=b;
    ad[perm[n+i]].kind=1;
    ad[perm[n+i]].id=i;
    bd[perm[i]].val=c;
    bd[perm[i]].kind=0;
    bd[perm[i]].id=i;
    bd[perm[n+i]].val=d;
    bd[perm[n+i]].kind=1;
    bd[perm[n+i]].id=i;
  }
  qsort(ad,2*n,sizeof(ad[0]),sdsortfnc);
  qsort(bd,2*n,sizeof(bd[0]),sdsortfnc);
  ad[2*n].val=-1;
  bd[2*n].val=-1;
 
  for(i=0;i<ac;i++){
    ns[i]=tx[i];
    nf[i]=0;
  }
  st=0;
  for(i=0;i<2*n;i++){
    if(ad[i].val==ad[i+1].val && ad[i].kind==ad[i+1].kind){continue;}
    if(ad[i].kind==0){
      for(j=st;j<=i;j++){
        for(k=0;k<ac;k++){
          av[ad[j].id][k]=nf[k];
        }
      }
      for(j=st;j<=i;j++){
        for(k=0;k<ac;k++){
          ns[k]^=seed[ad[j].id][k];
        }
      }
    }
    else{
      for(j=st;j<=i;j++){
        for(k=0;k<ac;k++){
          av[ad[j].id][k]^=ns[k];
        }
      }
      for(j=st;j<=i;j++){
        for(k=0;k<ac;k++){
          nf[k]^=seed[ad[j].id][k];
        }
      }
    }
    st=i+1;
  }
 
  for(i=0;i<ac;i++){
    ns[i]=tx[i];
    nf[i]=0;
  }
  st=0;
  for(i=0;i<2*n;i++){
    if(bd[i].val==bd[i+1].val && bd[i].kind==bd[i+1].kind){continue;}
    if(bd[i].kind==0){
      for(j=st;j<=i;j++){
        for(k=0;k<ac;k++){
          bv[bd[j].id][k]=nf[k];
        }
      }
      for(j=st;j<=i;j++){
        for(k=0;k<ac;k++){
          ns[k]^=seed[bd[j].id][k];
        }
      }
    }
    else{
      for(j=st;j<=i;j++){
        for(k=0;k<ac;k++){
          bv[bd[j].id][k]^=ns[k];
        }
      }
      for(j=st;j<=i;j++){
        for(k=0;k<ac;k++){
          nf[k]^=seed[bd[j].id][k];
        }
      }
    }
    st=i+1;
  }
  
  for(i=0;i<n;i++){
    for(j=0;j<ac;j++){
      if(av[i][j]!=bv[i][j]){
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("YES\n");
  return 0;
}