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
int nHr(int a,int b){return nCr(a+b-1,b);}
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
long long llnHr(long long a,long long b){return llnCr(a+b-1,b);}
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
    int par;
    int dep;
}node;

node uft[524288];

void resuf(){
    int i;
    for(i=0;i<524288;i++){
        uft[i].par=i;uft[i].dep=0;
    }
    return;
}

int find(int x){
    if(uft[x].par==x){return x;}
    else{uft[x].par=find(uft[x].par);return uft[x].par;}
}

void uni(int x,int y){
    int xp,yp;
    xp=find(x);yp=find(y);
    if(xp==yp){return;}
    if(uft[xp].dep>uft[yp].dep){
        uft[yp].par=xp;
    }
    else{
        uft[xp].par=yp;
        if(uft[xp].dep==uft[yp].dep){uft[yp].dep++;}
    }
    return;
}

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

int main(void){
    int i,j,n,m,k,a[16][2],b[16][2],c,w,r=0,l,t;
    int af[16][2]={0};
    int bf[16][2]={0};
    double d;
    char s[524288];
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i][0],&a[i][1]);
        if(a[i][0]>a[i][1]){
            w=a[i][0];
            a[i][0]=a[i][1];
            a[i][1]=w;
        }
    }
    for(i=0;i<m;i++){
        scanf("%d%d",&b[i][0],&b[i][1]);
        if(b[i][0]>b[i][1]){
            w=b[i][0];
            b[i][0]=b[i][1];
            b[i][1]=w;
        }
    }
    //l=strlen(s);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][0]==b[j][0]&&a[i][1]==b[j][1]){continue;}
            if(a[i][0]==b[j][0]){
                af[i][0]=1;
                bf[j][0]=1;
            }
            if(a[i][0]==b[j][1]){
                af[i][0]=1;
                bf[j][1]=1;
            }
            if(a[i][1]==b[j][0]){
                af[i][1]=1;
                bf[j][0]=1;
            }
            if(a[i][1]==b[j][1]){
                af[i][1]=1;
                bf[j][1]=1;
            }
        }
    }
    c=10;
    for(i=0;i<n;i++){
        if(af[i][0]==1&&af[i][1]==1){printf("-1\n");return 0;}
        if(af[i][0]==1){
            if(c==10){c=a[i][0];}
            else if(c!=a[i][0]){c=0;}
        }
        if(af[i][1]==1){
            if(c==10){c=a[i][1];}
            else if(c!=a[i][1]){c=0;}
        }
    }
    for(i=0;i<m;i++){
        if(bf[i][0]==1&&bf[i][1]==1){printf("-1\n");return 0;}
        if(bf[i][0]==1){
            if(c==10){c=b[i][0];}
            else if(c!=b[i][0]){c=0;}
        }
        if(bf[i][1]==1){
            if(c==10){c=b[i][1];}
            else if(c!=b[i][1]){c=0;}
        }
    }
    //shuffledget(a,n);
    //qsort(a,n,sizeof(int),sortfncsj);
    printf("%d\n",c);
    return 0;
}