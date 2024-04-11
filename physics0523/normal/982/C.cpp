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
int node;
int cost;
}data;

data heap[524288];
int hsize=0;

void resheap(){
    int i;
    heap[0].node=-1;
    heap[0].cost=inf;
    for(i=1;i<524288;i++){
        heap[i].node=-1;
        heap[i].cost=-inf;
    }
}

int swjud(data high,data low){
    if(high.cost < low.cost){return 1;}
    return -1;
}

void pqpush(data x){
    int a,b;
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
    int a,b,c;
    data m,sw;
    m=heap[1];
    heap[1]=heap[hsize];
    heap[hsize].node=-1;
    heap[hsize].cost=-inf;
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

int datasortfnc(const void *a,const void *b){
if(((data*)a)->cost == ((data*)b)->cost){return 0;}
if(((data*)a)->cost < ((data*)b)->cost){return -1;}
return 1;
}

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
if(((rs*)a)->st == ((rs*)b)->st){return 0;}
if(((rs*)a)->st < ((rs*)b)->st){return -1;}
return 1;
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

rs g[262144];
mkj x[262144];
data tn[262144],od;

void rep(int nv,int nd){
    int i;
    tn[nv].cost=nd;
    for(i=x[nv].st;i<x[nv].st+x[nv].kz;i++){
        if(tn[g[i].fi].cost!=inf){continue;}
        rep(g[i].fi,nd+1);
    }
}

int main(void){
    resheap();
    int i,j,n,m,k,a[262144],b,c,w,r=0,l,t,nv;
    int cnt[262144];
    double d;
    char s[262144];
    bool fl[262144]={0};
    scanf("%d",&n);
    //l=strlen(s);
    for(i=0;i<n-1;i++){scanf("%d%d",&g[2*i].st,&g[2*i].fi);
        g[2*i+1].st=g[2*i].fi;
        g[2*i+1].fi=g[2*i].st;
    }
    for(i=1;i<=n;i++){
        tn[i].node=i;
        tn[i].cost=inf;
        cnt[i]=1;
    }
    if(n%2){printf("-1\n");return 0;}
    qsort(g,2*(n-1),sizeof(rs),sortfnc);
    makemkj(g,x,2*(n-1));
    rep(1,0);
    for(i=1;i<=n;i++){
        //printf("[%d %d]\n",tn[i].node,tn[i].cost);
        pqpush(tn[i]);
    }
    while(hsize>0){
        od=pqpop();
        nv=od.node;
        fl[nv]=1;
        //printf("<%d %d %d>\n",od.node,od.cost,cnt[nv]);
        if(cnt[nv]%2==0){cnt[nv]=0;r++;}
        for(i=x[nv].st;i<x[nv].st+x[nv].kz;i++){
            if(fl[g[i].fi]==1){continue;}
            cnt[g[i].fi]+=cnt[nv];
        }
    }
    printf("%d\n",r-1);
    return 0;
}