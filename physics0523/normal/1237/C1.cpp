//set many funcs template
//Ver.20190820
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
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
 
typedef struct{
long long node;
long long cost;
}data;
 
data heap[262144];
long long hsize=0;
 
void resheap(){
    long long i;
    heap[0].node=-1;
    heap[0].cost=-inf;
    for(i=1;i<262144;i++){
        heap[i].node=-1;
        heap[i].cost=inf;
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
    heap[hsize].cost=inf;
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
 
typedef struct{
long long x;
long long y;
long long z;
long long id;
}sd;

int xysortfnc(const void *a,const void *b){
if(((sd*)a)->x < ((sd*)b)->x){return -1;}
if(((sd*)a)->x > ((sd*)b)->x){return 1;}
if(((sd*)a)->y < ((sd*)b)->y){return -1;}
if(((sd*)a)->y > ((sd*)b)->y){return 1;}
if(((sd*)a)->z < ((sd*)b)->z){return -1;}
if(((sd*)a)->z > ((sd*)b)->z){return 1;}
return 0;
}

int xzsortfnc(const void *a,const void *b){
if(((sd*)a)->x < ((sd*)b)->x){return -1;}
if(((sd*)a)->x > ((sd*)b)->x){return 1;}
if(((sd*)a)->z < ((sd*)b)->z){return -1;}
if(((sd*)a)->z > ((sd*)b)->z){return 1;}
if(((sd*)a)->y < ((sd*)b)->y){return -1;}
if(((sd*)a)->y > ((sd*)b)->y){return 1;}
return 0;
}

int yzsortfnc(const void *a,const void *b){
if(((sd*)a)->y < ((sd*)b)->y){return -1;}
if(((sd*)a)->y > ((sd*)b)->y){return 1;}
if(((sd*)a)->z < ((sd*)b)->z){return -1;}
if(((sd*)a)->z > ((sd*)b)->z){return 1;}
if(((sd*)a)->x < ((sd*)b)->x){return -1;}
if(((sd*)a)->x > ((sd*)b)->x){return 1;}
return 0;
}

int sdsortfnc(const void *a,const void *b){
if(((sd*)a)->z < ((sd*)b)->z){return -1;}
if(((sd*)a)->z > ((sd*)b)->z){return 1;}
if((((sd*)a)->z)%2==0){
  if(((sd*)a)->y < ((sd*)b)->y){return -1;}
  if(((sd*)a)->y > ((sd*)b)->y){return 1;}
}
else{
  if(((sd*)a)->y < ((sd*)b)->y){return 1;}
  if(((sd*)a)->y > ((sd*)b)->y){return -1;}
}
return 0;
}
 
typedef struct{
long long val;
long long node;
}cd;
 
int cdsortfnc(const void *a,const void *b){
if(((cd*)a)->val < ((cd*)b)->val){return -1;}
if(((cd*)a)->val > ((cd*)b)->val){return 1;}
return 0;
}
 
void coordinate_comp(long long a[],long long n){
  long long i,c=0;
  cd dat[524288];
  for(i=0;i<n;i++){
    dat[i].val=a[i];
    dat[i].node=i;
  }
  qsort(dat,n,sizeof(dat[0]),cdsortfnc);
  a[dat[0].node]=c;
  for(i=1;i<n;i++){
    if(dat[i-1].val!=dat[i].val){c++;}
    a[dat[i].node]=c;
  }
}
 
int main(void){
  srand(time(0));
  resheap();
  long long i,j,n,m,k,a,b,c,h,w=-1,r=0,l,t,p[262144];
  long long xa[262144],za[262144],mp;
  long long mfl[262144];
  sd dat[262144];
  data pd,od,mem[262144];
  scanf("%lld",&n);
  getperm(p,n);
  for(i=0;i<n;i++){
    scanf("%lld%lld%lld",&dat[p[i]].x,&dat[p[i]].y,&dat[p[i]].z);
    xa[p[i]]=dat[p[i]].x;
    za[p[i]]=dat[p[i]].z;
    dat[p[i]].y+=100000000;
    dat[p[i]].id=i+1;
  }
  coordinate_comp(xa,n);
  coordinate_comp(za,n);
  for(i=0;i<n;i++){
    dat[p[i]].x=xa[p[i]];
    dat[p[i]].z=za[p[i]];
  }

  qsort(dat,n,sizeof(dat[0]),xysortfnc);
  c=0;i=0;
  while(i<n){
    if(i!=n-1 && dat[i].x==dat[i+1].x && dat[i].y==dat[i+1].y){
      printf("%lld %lld\n",dat[i].id,dat[i+1].id);
      i+=2;
      c+=2;
    }
    else{
      dat[i-c]=dat[i];
      i++;
    }
  }
  n-=c;

  qsort(dat,n,sizeof(dat[0]),xzsortfnc);
  c=0;i=0;
  while(i<n){
    if(i!=n-1 && dat[i].x==dat[i+1].x && dat[i].z==dat[i+1].z){
      printf("%lld %lld\n",dat[i].id,dat[i+1].id);
      i+=2;
      c+=2;
    }
    else{
      dat[i-c]=dat[i];
      i++;
    }
  }
  n-=c;

  qsort(dat,n,sizeof(dat[0]),yzsortfnc);
  c=0;i=0;
  while(i<n){
    if(i!=n-1 && dat[i].y==dat[i+1].y && dat[i].z==dat[i+1].z){
      printf("%lld %lld\n",dat[i].id,dat[i+1].id);
      i+=2;
      c+=2;
    }
    else{
      dat[i-c]=dat[i];
      i++;
    }
  }
  n-=c;

  for(i=0;i<n;i++){dat[i].z=0;}
  
  qsort(dat,n,sizeof(dat[0]),sdsortfnc);
  dat[n].z=llinf;
  dat[n].y=llinf;
  for(i=0;i<n;i++){
    pd.node=dat[i].id;
    pd.cost=dat[i].x;
    pqpush(pd);
    if((dat[i].y==dat[i+1].y) && (dat[i].z==dat[i+1].z)){continue;}
    mp=0;
    while(hsize>0){
      od=pqpop();
      mem[mp]=od;
      mfl[mp]=0;
      mp++;
    }
    c=0;
    if(w!=-1){
      for(j=0;j<mp;j++){
        if(mem[j].node==w){
          if(j==0){
            printf("%lld %lld\n",mem[j].node,mem[j+1].node);
            mfl[j]=1;
            mfl[j+1]=1;
          }
          else if(j==mp-1){
            printf("%lld %lld\n",mem[j].node,mem[j-1].node);
            mfl[j]=1;
            mfl[j-1]=1;
          }
          else if(mem[j].cost==mem[j+1].cost){
            printf("%lld %lld\n",mem[j].node,mem[j+1].node);
            mfl[j]=1;
            mfl[j+1]=1;
          }
          else{
            printf("%lld %lld\n",mem[j].node,mem[j-1].node);
            mfl[j]=1;
            mfl[j-1]=1;
          }
          c+=2;
        }
      }
    }
    for(j=0;j<mp-1;j++){
      //printf("%lld %lld:[%lld]\n",i,j,mem[j].node);
      if(mfl[j]==1 || mfl[j+1]==1){continue;}
      if(mem[j].cost==mem[j+1].cost){
        printf("%lld %lld\n",mem[j].node,mem[j+1].node);
        c+=2;
        mfl[j]=1;
        mfl[j+1]=1;
      }
    }
    for(j=0;j<mp;j++){
      if(mfl[j]==1){continue;}
      if(c%2==0){
        if(c==mp-1){
          w=mem[j].node;
          pqpush(mem[j]);
          break;
        }
        printf("%lld",mem[j].node);
      }
      else{printf(" %lld\n",mem[j].node);}
      c++;
    }
  }
  return 0;
}