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

long long psl3(long long Ax,long long Ay,long long Bx,long long By,long long Cx,long long Cy){
return (Ax*By+Bx*Cy+Cx*Ay)-(Ax*Cy+Bx*Ay+Cx*By);
}

int main(void){
    long long i,j,n,m,k,a,b,c,w,r=0,l,t;
    long long x[262144],y[262144];
    long long bas1=-1,bas2=-1,nh1,nh2,nhc=0;
    double d;
    char s[262144];
    scanf("%lld",&n);
    //l=strlen(s);
    for(i=0;i<n;i++){
        scanf("%lld %lld",&x[i],&y[i]);
    }
    if(n<=4){printf("YES\n");return 0;}
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){if(i==j){continue;}
            for(k=0;k<5;k++){if(i==k || j==k){continue;}
                if(psl3(x[i],y[i],x[j],y[j],x[k],y[k])==0){bas1=i;bas2=j;}
            }
        }
    }
    if(bas1==-1){printf("NO\n");return 0;}
    for(i=0;i<n;i++){
        if(i==bas1 || i==bas2){continue;}
        if(psl3(x[bas1],y[bas1],x[bas2],y[bas2],x[i],y[i])==0){continue;}
        else if(nhc==0){nh1=i;nhc=1;continue;}
        else if(nhc==1){nh2=i;nhc=2;continue;}
        else{
            if(psl3(x[nh1],y[nh1],x[nh2],y[nh2],x[i],y[i])==0){continue;}
            else{printf("NO\n");return 0;}
        }
    }
    //qsort(a,n,sizeof(int),sortfncsj);
    printf("YES\n");
    return 0;
}