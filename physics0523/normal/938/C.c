//not conflict with math.h template
//int -> leading i
//max -> imax
//
//llround -> ll_round

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

int imax(int a,int b){if(a>b){return a;}return b;}
int imin(int a,int b){if(a<b){return a;}return b;}
int izt(int a,int b){return imax(a,b)-imin(a,b);}
int iround(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
int iceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
int igcd(int a,int b){int c;while(b!=0){c=a%b;a=b;b=c;}return a;}
int ilcm(int a,int b){int c=igcd(a,b);a/=c;return a*b;}
int inCr(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
int ifact(int a){int i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
int ipow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}
long long llzt(long long a,long long b){return llmax(a,b)-llmin(a,b);}
long long ll_round(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}
long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}
long long lllcm(long long a,long long b){long long c=llgcd(a,b);a/=c;return a*b;}
long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
long long llfact(long long a){long long i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
long long llpow(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
double dbmax(double a,double b){if(a>b){return a;}return b;}
double dbmin(double a,double b){if(a<b){return a;}return b;}
double dbzt(double a,double b){return dbmax(a,b)-dbmin(a,b);}
int isortfncsj(const void *a,const void *b){if(*(int *)a>*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int isortfnckj(const void *a,const void *b){if(*(int *)a<*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int llsortfncsj(const void *a,const void *b){if(*(long long *)a>*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int llsortfnckj(const void *a,const void *b){if(*(long long *)a<*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int dbsortfncsj(const void *a,const void *b){if(*(double *)a>*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int dbsortfnckj(const void *a,const void *b){if(*(double *)a<*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int strsortfncsj(const void *a,const void *b){return strcmp((char *)a,(char *)b);}
int strsortfnckj(const void *a,const void *b){return strcmp((char *)b,(char *)a);}

long long cvm(long long n,long long r){
    long long st=1,fi=llinf,t;
    while(st<=fi){
        t=(st+fi)/2;
        //printf("[%lld %lld]\n",t,n/t);
        if(n/t == r){
            return t;
        }
        else if(n/t < r){fi=t-1;}
        else{st=t+1;}
    }
    return 0;
}

int main(void){
    long long i,j,n,m,k,a[262144],b,c,w,r=0,l,t,p;
    long long ka,kb;
    double d;
    char s[262144];
    scanf("%lld",&t);
    //l=strlen(s);
    for(i=0;i<t;i++){scanf("%lld",&a[i]);
        if(a[i]==0){printf("1 1\n");continue;}
        for(j=1;j<40000;j++){
            if(j==39999){printf("-1\n");break;}
            if(a[i]%j!=0){continue;}
            p=a[i]/j;
            if(j>p){printf("-1\n");break;}
            ka=p+j;
            if(ka<=0 || ka%2==1){continue;}
            ka/=2;
            kb=p-ka;
            if(kb>ka || kb<=0){continue;}
            //printf("<%lld %lld>\n",ka,kb);
            kb=cvm(ka,kb);
            if(kb==0){continue;}
            printf("%lld %lld\n",ka,kb);break;
        }
    }
    //qsort(a,n,sizeof(int),sortfncsj);
    //printf("%d\n",r);
    return 0;
}