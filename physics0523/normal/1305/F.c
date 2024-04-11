//set many funcs template
//Ver.20190820
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<assert.h>
#include<sys/time.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

unsigned long long seed;

unsigned long long xorshift(){
  seed=seed^(seed<<13);
  seed=seed^(seed>>7);
  seed=seed^(seed<<17);
  return seed;
}

long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}
long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}
void llswap(long long *a,long long *b){long long c;c=(*a);(*a)=(*b);(*b)=c;}

void getperm(int a[],int n){
  int i,p;
  for(i=0;i<n;i++){
    a[i]=i;
  }
  for(i=n-1;i>=1;i--){
    p=xorshift()%(i+1);
    llswap(&a[p],&a[i]);
  }
}

bool *plfl;
long long lim=1000005;

void sieve_of_erat(){
  plfl=malloc(sizeof(bool)*(lim+5));
  long long i,j;
  for(i=0;i<lim+5;i++){plfl[i]=true;}
  plfl[0]=false;
  plfl[1]=false;
  for(i=2;i<lim;i++){
    if(!plfl[i]){continue;}
    for(j=2*i;j<lim;j+=i){
      plfl[j]=false;
    }
  }
  return;
}

long long delta(long long x,long long p){
  if(x<p){return p-x;}
  return llmin(x%p,p-x%p);
}

int main(void){
  sieve_of_erat();
  struct timeval tv;
  gettimeofday(&tv, NULL);
  seed=(tv.tv_sec*1000000+tv.tv_usec);
  long long i,j,n,m,k,a[524288],b,c,h,w,r=0,l,t;
  long long ma=llinf;
  long long perm[524288];
  long long st,fi;
  long long kv[524288];
  scanf("%lld",&n);
  for(i=0;i<n;i++){
    scanf("%lld",&a[i]);
    ma=llmin(a[i],ma);
    if(a[i]%2==1){r++;}
  }
  getperm(perm,n);
  for(i=3;i<1000005;i+=2){
    if(plfl[i]==false){continue;}
    c=0;
    for(j=0;j<n;j++){
      c+=delta(a[j],i);
      if(c>=r){break;}
    }
    r=llmin(r,c);
  }
  getperm(perm,n);
  st=llmax(1000000,ma-r);
  fi=ma+r;
  if(st<=fi){
    for(i=st;i<=fi;i++){
      kv[i-st]=i;
    }
    for(i=2;i<1000005;i++){
      if(plfl[i]==false){continue;}
      for(j=i*llceil(st,i);j<=fi;j+=i){
        while(kv[j-st]%i==0){kv[j-st]/=i;}
      }
    }
    for(i=st;i<=fi;i++){
      if(kv[i-st]<1000000){continue;}
      c=0;
      for(j=0;j<n;j++){
        c+=delta(a[j],kv[i-st]);
        if(c>=r){break;}
      }
      r=llmin(r,c);
    }
  }
  printf("%lld\n",r);
  return 0;
}