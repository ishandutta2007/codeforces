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

typedef struct{
    int st;
    int fi;
    int kr;
}rs;

typedef struct{
    int st;
    int kz;
}mkj;

int sortfnc(const void *a,const void *b){
if(((rs*)a)->st > ((rs*)b)->st){return 1;}
if(((rs*)a)->st < ((rs*)b)->st){return -1;}
return 0;
}

void makemkj(rs g[],mkj x[],int n){
    int i,ms=0,nst=g[0].st;
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

int q[1048576];
int qp=0,qqp=0;

void qpush(int x){
    qp++;q[qp]=x;
}

int qpop(){
    qqp++;
    return q[qqp];
}

int a[524288],dp[524288],vc[524288];
int resper[524288];
int hands[1048576],hc=0;
rs g[524288];
mkj x[524288];

void rep(int v,int jt,int ps,int pf){
  int i;
  resper[ps]=v;
  //printf("%d %d %d\n",v,ps,jt);
  for(i=0;i<jt;i++){
    hands[hc]=v;hc++;
  }
  ps++;
  if(dp[v]==1){return;}
  sd *dat=malloc(sizeof(sd)*x[v].kz);
  for(i=0;i<x[v].kz;i++){
    dat[i].node=g[i+x[v].st].fi;
    dat[i].val=dp[dat[i].node];
    //printf("%d<%d %d>\n",v,dat[i].node,dat[i].val);
  }
  qsort(dat,x[v].kz,sizeof(sd),sdsortfnc);
  for(i=0;i<x[v].kz;i++){
    if(i==0){rep(dat[i].node,0,ps,ps+vc[dat[i].node]-1);}
    else{rep(dat[i].node,dat[i-1].val,ps,ps+vc[dat[i].node]-1);}
    ps+=vc[dat[i].node];
  }
  free(dat);
  return;
}

int main(void){
  srand(time(0));
  int i,j,n,m,k,b,c[524288],h,w,r=0,l,t,per[524288];
  scanf("%d",&n);
  getperm(per,(n-1));
  for(i=0;i<n-1;i++){
    scanf("%d",&a[i+1]);
    g[per[i]].st=a[i+1];
    g[per[i]].fi=i+1;
    c[a[i+1]]++;
  }
  qsort(g,n-1,sizeof(rs),sortfnc);
  makemkj(g,x,n-1);
  //for(i=0;i<n-1;i++){printf("[%d %d]\n",g[i].st,g[i].fi);}
  for(i=0;i<n;i++){
    dp[i]=1;
    vc[i]=1;
    if(i!=0 && c[i]==0){qpush(i);}
  }
  while(qp!=qqp){
    w=qpop();
    //printf("<%d %d %d>\n",w,a[w],c[a[w]]);
    dp[a[w]]=max(dp[w]+1,dp[a[w]]);
    vc[a[w]]+=vc[w];
    c[a[w]]--;
    if(a[w]!=0 && c[a[w]]==0){qpush(a[w]);}
  }
  //for(i=0;i<n;i++){printf("%d %d %d\n",i,dp[i],vc[i]);}
  rep(0,0,0,n-1);
  prarr(resper,n);
  printf("%d\n",hc);
  prarr(hands,hc);
  return 0;
}