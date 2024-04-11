//set many funcs template
//Ver.20181228
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
double dbmax(double a,double b){if(a>b){return a;}return b;}
double dbmin(double a,double b){if(a<b){return a;}return b;}
double dbzt(double a,double b){return dbmax(a,b)-dbmin(a,b);}
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
    srand(time(0));
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

typedef struct{
int id;
int vc;
int lv;
}sd;

int sdsortfnclv(const void *a,const void *b){
if(((sd*)a)->lv < ((sd*)b)->lv){return -1;}
if(((sd*)a)->lv > ((sd*)b)->lv){return 1;}
if(((sd*)a)->vc < ((sd*)b)->vc){return -1;}
if(((sd*)a)->vc > ((sd*)b)->vc){return 1;}
return 0;
}

int sdsortfncvc(const void *a,const void *b){
if(((sd*)a)->vc < ((sd*)b)->vc){return -1;}
if(((sd*)a)->vc > ((sd*)b)->vc){return 1;}
return 0;
}

int isvl(char c){
  if(c=='a'){return 1;}
  if(c=='e'){return 2;}
  if(c=='i'){return 3;}
  if(c=='o'){return 4;}
  if(c=='u'){return 5;}
  return -1;
}

void prstr(int st,int len,char s[]){
  int i;
  for(i=st;i<st+len;i++){
    printf("%c",s[i]);
  }
}

int main(void){
  srand(time(0));
  int i,j,n,m,k,a[524288],b,c,h,w,r=0,l;
  int wst[1048576]={0},wl[1048576]={0};
  int sp[1048576][2]={0},spc=0;
  int wp[1048576][2]={0},wpc=0;
  char s[1048576],t[1048576];
  sd dat[1048576];
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%s",t);
    wst[i]=wst[i-1]+wl[i-1];
    wl[i]=strlen(t);
    dat[i].id=i;
    dat[i].vc=0;
    w=0;
    for(j=0;j<wl[i];j++){
      s[j+wst[i]]=t[j];
      h=isvl(t[j]);
      if(h!=-1){
        dat[i].vc++;
        w=h;
      }
    }
    dat[i].lv=w;
  }
  qsort(&dat[1],n,sizeof(dat[1]),sdsortfnclv);
  i=1;
  while(i<=n-1){
    if(dat[i].lv!=dat[i+1].lv){i++;continue;}
    if(dat[i].vc!=dat[i+1].vc){i++;continue;}
    sp[spc][0]=dat[i].id;
    sp[spc][1]=dat[i+1].id;
    spc++;
    dat[i].vc=inf;
    dat[i+1].vc=inf;
    i+=2;
  }
  qsort(&dat[1],n,sizeof(dat[1]),sdsortfncvc);
  i=1;
  while(i<=n-1){
    if(dat[i].vc==inf){break;}
    if(dat[i].vc!=dat[i+1].vc){i++;continue;}
    wp[wpc][0]=dat[i].id;
    wp[wpc][1]=dat[i+1].id;
    wpc++;
    dat[i].vc=inf;
    dat[i+1].vc=inf;
    i+=2;
  }
  while(spc>wpc){
    wp[wpc][0]=sp[spc-1][0];
    wp[wpc][1]=sp[spc-1][1];
    spc--;
    wpc++;
  }
  printf("%d\n",spc);
  for(i=0;i<spc;i++){
    prstr(wst[wp[i][0]],wl[wp[i][0]],s);
    printf(" ");
    prstr(wst[sp[i][0]],wl[sp[i][0]],s);
    printf("\n");
    prstr(wst[wp[i][1]],wl[wp[i][1]],s);
    printf(" ");
    prstr(wst[sp[i][1]],wl[sp[i][1]],s);
    printf("\n");
  }
  return 0;
}