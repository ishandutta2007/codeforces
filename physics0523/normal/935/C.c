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

int main(void){
    int r,x1,x2,y1,y2;
    double dr,dx1,dy1,dx2,dy2,xs,ys,dst;
    double resx,resy,resr;
    char s[262144];
    scanf("%d%d%d%d%d",&r,&x1,&y1,&x2,&y2);
    if(x1==x2 && y1==y2){
        resr=r;resr/=2.0f;
        resx=x1;
        resy=y1+resr;
        printf("%.12lf %.12lf %.12lf\n",resx,resy,resr);
        return 0;
    }
    dr=r;
    dx1=x1;dy1=y1;
    dx2=x2;dy2=y2;
    xs=dx1-dx2;
    ys=dy1-dy2;
    dst=xs*xs+ys*ys;
    dst=sqrt(dst);
    if(dr+dst<dr*2){
        resr=dr+dst;resr/=2.0f;
        xs/=dst;xs*=resr;
        ys/=dst;ys*=resr;
        resx=dx2+xs;
        resy=dy2+ys;
        printf("%.12lf %.12lf %.12lf\n",resx,resy,resr);
        return 0;
    }
    else{
        resr=dr;
        resx=x1;
        resy=y1;
        printf("%.12lf %.12lf %.12lf\n",resx,resy,resr);
        return 0;
    }
    //qsort(a,n,sizeof(int),sortfncsj);
    //printf("%d\n",r);
    return 0;
}