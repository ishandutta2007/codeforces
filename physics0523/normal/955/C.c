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

long long power(long long a, long long b){
	long long x = 1, y = a;
	while (b > 0){
		if(b%2){
			x = (x*y);
		}
		y = (y*y);
		b /= 2;
	}
	return x;
}

long long pmap[64]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
long long db[32]={6,10,14,22,26,34,38,46,58,62,15,21,33,39,51,57,35,55};
long long tr[2]={30,42};
double njkr[64];
long long kj(long long maxi,long long p){
    if(maxi<=1){return 0;}
    long long st,fi,te,iu;
    double njk=1;
    njk/=p;
    st=1;
    fi=njkr[p];
    while(st<=fi){
        te=(st+fi)/2;
        iu=power(te,p);
        if(iu<=maxi){st=te+1;}else{fi=te-1;}
    }
    return fi-1;
}

void mnjk(){
    long long i;
    double d;
    for(i=2;i<64;i++){
        d=1;d/=i;
        njkr[i]=pow(2000000000000000000,d);
    }
}

int main(void){
    mnjk();
    long long i,j,n,m,k,a[262144],b,c,w,r=0,l,t,q,lc,rc;
    double d;
    char s[262144];
    scanf("%lld",&q);
    //l=strlen(s);
    for(i=0;i<q;i++){
        scanf("%lld%lld",&l,&r);
        lc=0;rc=0;
        if(l==1){rc++;}
        l--;
        for(j=0;j<18;j++){
            //printf("<%lld:%lld>",pmap[j],kj(r,pmap[j]));
            lc+=kj(l,pmap[j]);
            rc+=kj(r,pmap[j]);
        }
        for(j=0;j<18;j++){
            //printf("<%lld:%lld>",pmap[j],kj(r,pmap[j]));
            lc-=kj(l,db[j]);
            rc-=kj(r,db[j]);
        }
        for(j=0;j<2;j++){
            //printf("<%lld:%lld>",pmap[j],kj(r,pmap[j]));
            lc+=kj(l,tr[j]);
            rc+=kj(r,tr[j]);
        }
        printf("%lld\n",rc-lc);
    }
    //qsort(a,n,sizeof(int),sortfncsj);
    //printf("%d\n",r);
    return 0;
}