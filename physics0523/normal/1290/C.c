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
    int par;
    int dep;
    int size;
    int flag;
}node;

node uft[1048576];

void resuf(){
  int i;
  for(i=0;i<1048576;i++){
    uft[i].par=i;
    uft[i].dep=0;
    uft[i].size=i%2;
    uft[i].flag=0;
  }
  return;
}

int find(int x){
  if(uft[x].par==x){return x;}
  else{
    uft[x].par=find(uft[x].par);
    return uft[x].par;
  }
}

void uni(int x,int y){
  int xp,yp;
  xp=find(x);yp=find(y);
  if(xp==yp){return;}
  if(uft[xp].dep>uft[yp].dep){
    uft[yp].par=xp;
    uft[xp].size+=uft[yp].size;
    uft[xp].flag|=uft[yp].flag;
  }
  else{
    uft[xp].par=yp;
    uft[yp].size+=uft[xp].size;
    if(uft[xp].dep==uft[yp].dep){uft[yp].dep++;}
    uft[yp].flag|=uft[xp].flag;
  }
  return;
}

int size(int x){
  x=find(x);
  return uft[x].size;
}

int getflag(int x){
  x=find(x);
  return uft[x].flag;
}

void addflag(int x,int k){
  x=find(x);
  uft[x].flag|=k;
}

int main(void){
  resuf();
  int i,j,n,m,k,a[524288],b,c,h,w,r=0,l,t,p,q;
  int ba[524288][2]={0};
  int kill,live;
  char s[524288];
  scanf("%d%d",&n,&k);
  scanf("%s",s);
  for(i=1;i<=k;i++){
    scanf("%d",&c);
    for(j=0;j<c;j++){
      scanf("%d",&w);
      w--;
      if(ba[w][0]==0){ba[w][0]=i;}
      else{ba[w][1]=i;}
    }
  }
  r=0;
  for(i=0;i<n;i++){
    p=ba[i][0];
    q=ba[i][1];
    //printf("<%d %d>",p,q);
    if(ba[i][0]==0){
      printf("%d\n",r);
      continue;
    }
    if(ba[i][1]==0){
      if(s[i]=='0'){
        kill=2*p;
        live=2*p+1;
      }
      else{
        kill=2*p+1;
        live=2*p;
      }

      if((getflag(kill)&1)==1){
        r-=size(kill);
        uft[find(kill)].flag^=1;
      }
      addflag(kill,2);
      if((getflag(live)&1)==0){
        r+=size(live);
        uft[find(live)].flag^=1;
      }
    }
    else{
      if(find(2*p)==find(2*q) || find(2*p)==find(2*q+1)){printf("%d\n",r);continue;}
      //printf("[[%d %d]]\n",getflag(2*p+1),getflag(2*q+1));
      if((getflag(2*p)&1)==1){
        r-=size(2*p);
        //printf("<<%d %d>>\n",2*p,size(2*p));
        uft[find(2*p)].flag^=1;
      }
      if((getflag(2*p+1)&1)==1){
        r-=size(2*p+1);
        //printf("<<%d %d>>\n",2*p+1,size(2*p+1));
        uft[find(2*p+1)].flag^=1;
      }
      if((getflag(2*q)&1)==1){
        r-=size(2*q);
        //printf("<<%d %d>>\n",2*q,size(2*q));
        uft[find(2*q)].flag^=1;
      }
      if((getflag(2*q+1)&1)==1){
        r-=size(2*q+1);
        //printf("<<%d %d>>\n",2*q+1,size(2*q+1));
        uft[find(2*q+1)].flag^=1;
      }
      //printf("[%d]\n",r);
      if(s[i]=='0'){
        uni(2*p,2*q+1);
        uni(2*p+1,2*q);
      }
      else{
        uni(2*p,2*q);
        uni(2*p+1,2*q+1);
      }

      c=inf;h=-1;
      if((getflag(2*p)&2)==0){
        if(size(2*p)<c){
          c=size(2*p);
          h=find(2*p);
        }
      }
      if((getflag(2*p+1)&2)==0){
        if(size(2*p+1)<c){
          c=size(2*p+1);
          h=find(2*p+1);
        }
      }
      //printf("%d\n",c);
      r+=c;
      uft[h].flag|=1;
    }
    printf("%d\n",r);
  }
  return 0;
}