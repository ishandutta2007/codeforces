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

void shuffledget(int x[],int n){
    int i,b[524288],p,c;
    for(i=0;i<n;i++){
        b[i]=i;
    }
    for(i=n;i>=1;i--){
        p=rand()%i;
        c=b[i-1];b[i-1]=b[p];b[p]=c;
    }
    for(i=0;i<n;i++){
        scanf("%d",&x[b[i]]);
    }
}

int dx4[4]={1,-1,0,0};
int dy4[4]={0,0,1,-1};
int dx8[8]={-1,-1,-1,0,0,1,1,1};
int dy8[8]={-1,0,1,-1,1,-1,0,1};

int search(int x,int a[],int n){
    int st=0,fi=n-1,te;
    while(st<=fi){
        te=(st+fi)/2;
        if(a[te]<x){st=te+1;}else{fi=te-1;}
    }
    return st;
}

void prarr(long long arr[],long long n){
  long long i;
  for(i=0;i<n;i++){
    if(i){printf(" ");}
    printf("%lld",arr[i]);
  }
  printf("\n");
  return;
}

void getperm(int a[],int n){
  int i,p;
  for(i=0;i<n;i++){
    a[i]=i;
  }
  for(i=n-1;i>=1;i--){
    p=rand()%(i+1);
    swap(&a[p],&a[i]);
  }
}

typedef struct{
int val;
int node;
}sd;

int sdsortfnc(const void *a,const void *b){
if(((sd*)a)->val < ((sd*)b)->val){return -1;}
if(((sd*)a)->val > ((sd*)b)->val){return 1;}
return 0;
}

void coordinate_comp(int a[],int n){
  int i,c=0;
  sd dat[524288];
  for(i=0;i<n;i++){
    dat[i].val=a[i];
    dat[i].node=i;
  }
  qsort(dat,n,sizeof(dat[0]),sdsortfnc);
  a[dat[0].node]=c;
  for(i=1;i<n;i++){
    if(dat[i-1].val!=dat[i].val){c++;}
    a[dat[i].node]=c;
  }
}

long long q[1048576];
long long qp=0,qqp=0;

void qpush(long long x){
    //printf("<%lld>\n",x);
    qp++;q[qp]=x;
}

long long qpop(){
    qqp++;
    return q[qqp];
}

typedef struct{
    long long st;
    long long fi;
    long long kr;
}rs;

typedef struct{
    long long st;
    long long kz;
}mkj;

int sortfnc(const void *a,const void *b){
if(((rs*)a)->st > ((rs*)b)->st){return 1;}
if(((rs*)a)->st < ((rs*)b)->st){return -1;}
return 0;
}

void makemkj(rs g[],mkj x[],long long n){
    long long i,ms=0,nst=g[0].st;
    for(i=1;i<n;i++){
        if(g[i].st!=g[i-1].st){
            x[nst].kz=i-ms;
            x[nst].st=ms;
            nst=g[i].st;ms=i;
        }
    }
    x[nst].kz=n-ms;
    x[nst].st=ms;
}

int main(void){
  long long i,j,n,m,k,a,b[524288],c,h,w,r=0,l,t;
  long long x[524288],y[524288];
  long long lc[524288]={0};
  long long pcf[524288]={0};
  long long fl[524288]={0};
  long long res[524288]={0},rcnt=0;
  rs g[524288];
  mkj dc[524288];
  
  scanf("%lld%lld",&n,&m);
  for(i=1;i<=n;i++){
    scanf("%lld",&b[i]);
    dc[i].kz=0;
  }
  for(i=0;i<m;i++){
    scanf("%lld%lld",&x[i],&y[i]);
    lc[x[i]]++;
    lc[y[i]]++;
    g[2*i].st=x[i];
    g[2*i].fi=i;
    g[2*i+1].st=y[i];
    g[2*i+1].fi=i;
  }
  qsort(g,2*m,sizeof(g[0]),sortfnc);
  makemkj(g,dc,2*m);
  for(i=1;i<=n;i++){
    if(b[i]>=lc[i]){
      pcf[i]=1;
      for(j=dc[i].st;j<dc[i].st+dc[i].kz;j++){qpush(g[j].fi);}
    }
  }
  while(rcnt<m){
    if(qp==qqp){puts("DEAD");return 0;}
    w=qpop();
    if(fl[w]==1){continue;}
    fl[w]=1;
    res[m-rcnt-1]=w+1;
    rcnt++;

    if(pcf[x[w]]==0){
      lc[x[w]]--;
      if(b[x[w]]>=lc[x[w]]){
        pcf[x[w]]=1;
        for(j=dc[x[w]].st;j<dc[x[w]].st+dc[x[w]].kz;j++){qpush(g[j].fi);}
      }
    }
    if(pcf[y[w]]==0){
      lc[y[w]]--;
      if(b[y[w]]>=lc[y[w]]){
        pcf[y[w]]=1;
        for(j=dc[y[w]].st;j<dc[y[w]].st+dc[y[w]].kz;j++){qpush(g[j].fi);}
      }
    }
  }
  puts("ALIVE");
  prarr(res,m);
  return 0;
}