//set many funcs template
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
int fact(int a){int i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}
long long llzt(long long a,long long b){return llmax(a,b)-llmin(a,b);}
long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}
long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}
long long lllcm(long long a,long long b){long long c=llgcd(a,b);a/=c;return a*b;}
long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
long long llfact(long long a){long long i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
long long llpow(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
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

typedef struct{
long long num;
long long typ;
long long pod;
}data;

int sortfnc(const void *a,const void *b){
if(((data*)a)->typ < ((data*)b)->typ){return -1;}
if(((data*)a)->typ > ((data*)b)->typ){return 1;}
if(((data*)a)->num < ((data*)b)->num){return -1;}
if(((data*)a)->num > ((data*)b)->num){return 1;}
if(((data*)a)->pod < ((data*)b)->pod){return -1;}
if(((data*)a)->pod > ((data*)b)->pod){return 1;}
return 0;
}

int main(void){
    long long cr=0,nm,ny,fl,i,j,n,m,k,a[262144],b,c,w,r[262144]={0},l,t,nst;
    double d;
    char s[262144];
    data x[262144];
    scanf("%lld",&n);
    //l=strlen(s);
    for(i=0;i<n;i++){scanf("%lld",&a[i]);
        x[i].num=a[i];
        x[i].pod=i;
        while(a[i]%2==0){a[i]/=2;}
        x[i].typ=a[i];
    }
    qsort(x,n,sizeof(data),sortfnc);
    x[n].typ=llinf;
    nst=0;
    for(i=1;i<=n;i++){
        if(x[i].typ!=x[i-1].typ){
            ny=i-nst;
            nm=x[nst].num;
            while(nm<=1000000000000000){
                for(j=nst;j<nst+ny;j++){
                    if(x[j].num==nm && x[j+1].num==nm){
                        x[j].typ=llinf;x[j].num=llinf;x[j+1].num=nm*2;
                    }
                }
                nm*=2;
                qsort(&x[nst],ny,sizeof(data),sortfnc);
            }
            nst=i;
        }
    }
    for(i=0;i<n;i++){
        if(x[i].typ!=llinf){cr++;r[x[i].pod]=x[i].num;}
    }
    printf("%lld\n",cr);
    cr=0;
    for(i=0;i<n;i++){
        if(r[i]!=0){if(cr){printf(" ");}cr=1;printf("%lld",r[i]);}
    }printf("\n");
    return 0;
}