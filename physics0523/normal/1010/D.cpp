//CFR499-D1D
//Waiting 4 System Testing
//Ver.20180717
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

typedef struct{
int par;
int ca;
int cb;
char kind[4];
}sd;

typedef struct{
int nd;
int bit;
}data;

data q[1048576];
int qp=0,qqp=0;

void qpush(data x){
    qp++;q[qp]=x;
}

data qpop(){
    qqp++;
    return q[qqp];
}

int main(void){
    sd node[1048576];
    int i,j,n,m,k,a[1048576],ex[1048576],b,c,h,w,r=0,l,t,fr[1048576];
    double d;
    data pd,od;
    scanf("%d",&n);
    //l=strlen(s);
    for(i=1;i<=n;i++){node[i].par=-1;}
    for(i=1;i<=n;i++){
        fr[i]=-1;ex[i]=-1;
        scanf("%s",node[i].kind);
        if(node[i].kind[0]=='N' || node[i].kind[0]=='I'){
            scanf("%d",&node[i].ca);
            if(node[i].kind[0]=='N'){
                node[node[i].ca].par=i;
            }
        }
        else{
            scanf("%d%d",&node[i].ca,&node[i].cb);
            node[node[i].ca].par=i;
            node[node[i].cb].par=i;
        }
    }
    for(i=1;i<=n;i++){
        if(node[i].kind[0]=='I'){
            pd.nd=i;
            pd.bit=node[i].ca;
            qpush(pd);
        }
    }
    while(qp-qqp>0){
        od=qpop();
        fr[od.nd]=od.bit;
        w=node[od.nd].par;
        if(w!=-1){
            if(node[w].kind[0]=='N'){
                pd.nd=w;pd.bit=1-od.bit;
                qpush(pd);
            }
            else{
                if(fr[node[w].ca]!=-1 && fr[node[w].cb]!=-1){
                    pd.nd=w;
                    if(node[w].kind[0]=='A'){
                        pd.bit=fr[node[w].ca]&fr[node[w].cb];
                    }
                    if(node[w].kind[0]=='O'){
                        pd.bit=fr[node[w].ca]|fr[node[w].cb];
                    }
                    if(node[w].kind[0]=='X'){
                        pd.bit=fr[node[w].ca]^fr[node[w].cb];
                    }
                    qpush(pd);
                }
            }
        }
    }
    qp=0;qqp=0;
    pd.nd=1;
    pd.bit=1;
    qpush(pd);
    while(qp-qqp>0){
        od=qpop();
        //printf("%d\n",od.nd);
        ex[od.nd]=1;
        if(node[od.nd].kind[0]=='N'){
            pd.nd=node[od.nd].ca;
            qpush(pd);
        }
        if(node[od.nd].kind[0]=='X'){
            pd.nd=node[od.nd].ca;
            qpush(pd);
            pd.nd=node[od.nd].cb;
            qpush(pd);
        }
        if(node[od.nd].kind[0]=='A'){
            if(fr[node[od.nd].ca]&fr[node[od.nd].cb]==1){
                pd.nd=node[od.nd].ca;qpush(pd);
                pd.nd=node[od.nd].cb;qpush(pd);
            }
            else if(fr[node[od.nd].ca]==1){
                pd.nd=node[od.nd].cb;qpush(pd);
            }
            else if(fr[node[od.nd].cb]==1){
                pd.nd=node[od.nd].ca;qpush(pd);
            }
        }
        if(node[od.nd].kind[0]=='O'){
            if(fr[node[od.nd].ca]==0&&fr[node[od.nd].cb]==0){
                pd.nd=node[od.nd].ca;qpush(pd);
                pd.nd=node[od.nd].cb;qpush(pd);
            }
            else if(fr[node[od.nd].ca]==0){
                pd.nd=node[od.nd].cb;qpush(pd);
            }
            else if(fr[node[od.nd].cb]==0){
                pd.nd=node[od.nd].ca;qpush(pd);
            }
        }
    }
    //shuffledget(a,n);
    //qsort(a,n,sizeof(int),sortfncsj);
    for(i=1;i<=n;i++){
        if(node[i].kind[0]=='I'){
            if(ex[i]==1){printf("%d",1-fr[1]);}
            else{printf("%d",fr[1]);}
        }
    }
    printf("\n");
    return 0;
}