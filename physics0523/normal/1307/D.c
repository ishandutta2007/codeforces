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

typedef struct{
long long ov;
long long nv;
}sd;

int sdsortfnc(const void *a,const void *b){
if(((sd*)a)->ov < ((sd*)b)->ov){return -1;}
if(((sd*)a)->ov > ((sd*)b)->ov){return 1;}
if(((sd*)a)->nv > ((sd*)b)->nv){return -1;}
if(((sd*)a)->nv < ((sd*)b)->nv){return 1;}
return 0;
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

//Dynamic Array

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

//Heap and Priority_queue

typedef struct{
long long node;
long long cost;
}data;

data heap[524288];
long long hsize=0;

void resheap(){
    hsize=0;
    long long i;
    heap[0].node=-1;
    heap[0].cost=-llinf;
    for(i=1;i<524288;i++){
        heap[i].node=-1;
        heap[i].cost=llinf;
    }
}

int swjud(data high,data low){
    if(high.cost > low.cost){return 1;}
    return -1;
}

void pqpush(data x){
    long long a,b;
    data m;
    hsize++;
    heap[hsize]=x;
    a=hsize;
    while(1){
        b=a/2;
        if(swjud(heap[b],heap[a]) == 1){
            m=heap[a];heap[a]=heap[b];heap[b]=m;
        }
        else{break;}
        a=b;
    }
}

data pqpop(){
    long long a,b,c;
    data m,sw;
    m=heap[1];
    heap[1]=heap[hsize];
    heap[hsize].node=-1;
    heap[hsize].cost=llinf;
    hsize--;
    a=1;
    while(1){
        b=a*2;c=a*2+1;
        if(swjud(heap[a],heap[b])==-1 && swjud(heap[a],heap[c])==-1){break;}
        if(swjud(heap[b],heap[c])==-1){
            sw=heap[a];heap[a]=heap[b];heap[b]=sw;
            a=b;
        }
        else{
            sw=heap[a];heap[a]=heap[c];heap[c]=sw;
            a=c;
        }
    }
    return m;
}

void dijkstra(long long a,long long vc,long long dist[],rs g[],mkj x[]){
  resheap();
  long long i,j,nv;
  for(i=0;i<=vc;i++){
    dist[i]=llinf;
  }
  data pd,od;
  pd.node=a;
  pd.cost=0;
  pqpush(pd);
  while(hsize>0){
    od=pqpop();
    nv=od.node;
    if(dist[nv]!=llinf){continue;}
    dist[nv]=od.cost;
    for(i=x[nv].st;i<x[nv].st+x[nv].kz;i++){
      if(dist[g[i].fi]!=llinf){continue;}
      pd.node=g[i].fi;
      pd.cost=od.cost+g[i].kr;
      pqpush(pd);
    }
  }
  return;
}

int main(void){
  srand(time(0));
  long long i,j,n,m,k,a,b,c,h,w,r,l,t;
  long long sp[524288];
  long long perm[524288];
  long long od[524288],nd[524288];
  long long barr[524288];
  sd dat[524288];
  rs g[524288];
  mkj x[524288];
  
  scanf("%lld%lld%lld",&n,&m,&k);
  for(i=0;i<k;i++){
    scanf("%lld",&sp[i]);
  }
  getperm(perm,2*m);
  for(i=0;i<m;i++){
    scanf("%lld%lld",&g[perm[2*i]].st,&g[perm[2*i]].fi);
    g[perm[2*i]].kr=1;
    g[perm[2*i+1]].st=g[perm[2*i]].fi;
    g[perm[2*i+1]].fi=g[perm[2*i]].st;
    g[perm[2*i+1]].kr=1;
  }
  qsort(g,2*m,sizeof(g[0]),sortfnc);
  makemkj(g,x,2*m);
  dijkstra(1,n,od,g,x);
  dijkstra(n,n,nd,g,x);
  w=od[n];

  getperm(perm,k);
  for(i=0;i<k;i++){
    dat[perm[i]].ov=od[sp[i]];
    dat[perm[i]].nv=nd[sp[i]];
  }
  qsort(dat,k,sizeof(dat[0]),sdsortfnc);
  
  barr[k]=-llinf;
  for(i=k-1;i>=0;i--){
    barr[i]=llmax(dat[i].nv,barr[i+1]);
  }

  r=-llinf;
  for(i=0;i<k-1;i++){
    r=llmax(r,1+dat[i].ov+barr[i+1]);
  }
  
  printf("%lld\n",llmin(r,w));
  return 0;
}