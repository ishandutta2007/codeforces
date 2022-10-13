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

long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}

long long st[128],ko[128];
long long qc=0;
long long dt[128]={0};

long long ask(long long a){
  printf("+ %lld\n",a);
  dt[a]++;
  fflush(stdout);
  qc++;
  scanf("%lld%lld",&ko[qc],&st[qc]);
  return qc;
}

long long find(long long x){
  long long i;
  for(i=0;;i++){
    if(llnCr(i+1,3)-llnCr(i,3)==x){return i;}
  }
}

int main(void){
  long long n,i;
  long long res[128],um[128]={0};
  scanf("%lld",&n);
  scanf("%lld%lld",&ko[0],&st[0]);

  ask(1);
  res[1]=find(ko[1]-ko[0]);
  ask(2);
  res[2]=find(ko[2]-ko[1]);
  if((st[2]-st[1])!=0){um[3]=1;}else{um[3]=0;}
  ask(3);
  res[3]=find(ko[3]-ko[2]);
  if(res[3]==0 && um[3]==1){res[3]=1;}

  ask(1);
  if(res[1]==0){
    if(ko[4]-ko[3]!=0){res[1]=1;}
  }
  if(res[2]==0){res[2]=((st[4]-st[3])/(res[3]+1))-1;}

  if((st[3]-st[2]-(res[1]+1)*(res[2]+1))!=0){um[4]=1;}else{um[4]=0;}

  for(i=4;i<n;i++){
    ask(i);
    res[i]=find(ko[qc]-ko[qc-1]);
    if(res[i]==0 && um[i]==1){res[i]=1;}
    if((st[qc]-st[qc-1]-(res[i-1]+1)*(res[i-2]+1))!=0){um[i+1]=1;}else{um[i+1]=0;}
  }
  if(n==4){qc--;}
  res[n]=((st[qc]-st[qc-1])-(res[n-3]+1)*(res[n-2]+1))/(res[n-2]+1);

  printf("!");
  for(i=1;i<=n;i++){
    printf(" %lld",res[i]);
  }
  printf("\n");
  fflush(stdout);
  return 0;
}