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
int zt(int a,int b){return max(a,b)-min(a,b);}
int round(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
int gcd(int a,int b){int c;while(b!=0){c=a%b;a=b;b=c;}return a;}
int lcm(int a,int b){int c=gcd(a,b);a/=c;return a*b;}
int nCr(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
int nHr(int a,int b){return nCr(a+b-1,b);}
int fact(int a){int i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
int dsum(int x){int r=0;while(x){r+=(x%10);x/=10;}return r;}
int dsumb(int x,int b){int r=0;while(x){r+=(x%b);x/=b;}return r;}
int sankaku(int x){return ((1+x)*x)/2;}
void swap(int *a,int *b){int c;c=(*a);(*a)=(*b);(*b)=c;}
long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}
long long llzt(long long a,long long b){return llmax(a,b)-llmin(a,b);}
long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}
long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}
long long lllcm(long long a,long long b){long long c=llgcd(a,b);a/=c;return a*b;}
long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
long long llnHr(long long a,long long b){return llnCr(a+b-1,b);}
long long llfact(long long a){long long i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
long long llpow(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
long long lldsum(long long x){long long r=0;while(x){r+=(x%10);x/=10;}return r;}
long long lldsumb(long long x,long long b){long long r=0;while(x){r+=(x%b);x/=b;}return r;}
long long llsankaku(long long x){return ((1+x)*x)/2;}
void llswap(long long *a,long long *b){long long c;c=(*a);(*a)=(*b);(*b)=c;}
double dbmax(double a,double b){if(a>b){return a;}return b;}
double dbmin(double a,double b){if(a<b){return a;}return b;}
double dbzt(double a,double b){return dbmax(a,b)-dbmin(a,b);}
void dbswap(double *a,double *b){double c;c=(*a);(*a)=(*b);(*b)=c;}
void chswap(char *a,char *b){char c;c=(*a);(*a)=(*b);(*b)=c;}
int sortfncsj(const void *a,const void *b){if(*(int *)a>*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int sortfnckj(const void *a,const void *b){if(*(int *)a<*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int llsortfncsj(const void *a,const void *b){if(*(long long *)a>*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int llsortfnckj(const void *a,const void *b){if(*(long long *)a<*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int dbsortfncsj(const void *a,const void *b){if(*(double *)a>*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int dbsortfnckj(const void *a,const void *b){if(*(double *)a<*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int strsortfncsj(const void *a,const void *b){return strcmp((char *)a,(char *)b);}
int strsortfnckj(const void *a,const void *b){return strcmp((char *)b,(char *)a);}
int chsortfncsj(const void *a,const void *b){if(*(char *)a>*(char *)b){return 1;}if(*(char *)a==*(char *)b){return 0;}return -1;}
int chsortfnckj(const void *a,const void *b){if(*(char *)a<*(char *)b){return 1;}if(*(char *)a==*(char *)b){return 0;}return -1;}

long long search(long long x,long long a[],long long n){
  long long st=0,fi=n-1,te;
  while(st<=fi){
      te=(st+fi)/2;
      if(a[te]<x){st=te+1;}else{fi=te-1;}
  }
  return st;
}

void prarr(int arr[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i){printf(" ");}
    printf("%d",arr[i]);
  }
  printf("\n");
  return;
}

void getperm(long long a[],long long n){
  long long i,p;
  for(i=0;i<n;i++){
    a[i]=i;
  }
  for(i=n-1;i>=1;i--){
    p=rand()%(i+1);
    llswap(&a[p],&a[i]);
  }
}

long long ccalc(long long a,long long b,long long c){
  long long res=0;
  res+=(a-b)*(a-b);
  res+=(a-c)*(a-c);
  res+=(b-c)*(b-c);
  return res;
}

long long warr[4][524288];
long long wmem[4],wc[4];

long long calc(long long sm,long long md,long long lg){
  long long i,res=llinf;
  long long a,b,c;
  for(i=1;i<=wc[md]-1;i++){
    b=warr[md][i];
    a=search(b,warr[sm],wc[sm])-1;
    if(warr[sm][a+1]==b){a++;}
    if(warr[sm][a]==-llinf){continue;}
    c=search(b,warr[lg],wc[lg]);
    if(warr[lg][c]==llinf){continue;}
    res=llmin(ccalc(warr[sm][a],b,warr[lg][c]),res);
    //fprintf(stderr,"%lld %lld %lld\n",warr[sm][a],b,warr[lg][c]);
  }
  return res;
}

int main(void){
  srand(time(0));
  long long i,j,n,m,k,a,b,c,h,w,res,l,t;
  long long p[524288];
  scanf("%lld",&t);
  while(t>0){
    t--;
    res=llinf;
    scanf("%lld%lld%lld",&a,&b,&c);

    getperm(p,a);
    for(i=0;i<a;i++){scanf("%lld",&warr[0][p[i]]);}
    warr[0][a]=-llinf;
    warr[0][a+1]=llinf;
    qsort(warr[0],a+2,sizeof(long long),llsortfncsj);
    
    getperm(p,b);
    for(i=0;i<b;i++){scanf("%lld",&warr[1][p[i]]);}
    warr[1][b]=-llinf;
    warr[1][b+1]=llinf;
    qsort(warr[1],b+2,sizeof(long long),llsortfncsj);
    
    getperm(p,c);
    for(i=0;i<c;i++){scanf("%lld",&warr[2][p[i]]);}
    warr[2][c]=-llinf;
    warr[2][c+1]=llinf;
    qsort(warr[2],c+2,sizeof(long long),llsortfncsj);

    wc[0]=a+2;wc[1]=b+2;wc[2]=c+2;
    res=llmin(calc(0,1,2),res);
    res=llmin(calc(0,2,1),res);
    res=llmin(calc(1,0,2),res);
    res=llmin(calc(1,2,0),res);
    res=llmin(calc(2,0,1),res);
    res=llmin(calc(2,1,0),res);
    printf("%lld\n",res);
    //fprintf(stderr,"\n");
  }
  return 0;
}