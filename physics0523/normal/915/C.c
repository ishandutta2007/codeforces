//set many funcs template
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
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

int main(void){
    //printf("%lld\n",atoll("12345678901234"));
    long long f,p,x,i,j,n,m,k,a,b,r=0,l,ab[128]={0};
    double d;
    char s[32],t[32],q[32]={0};
    scanf("%lld%lld",&a,&b);
    sprintf(s,"%lld",a);
    sprintf(t,"%lld",b);
    l=strlen(s);
    if(strlen(s)<strlen(t)){
        b=llpow(10,strlen(s))-1;
        sprintf(t,"%lld",b);
    }
    for(i=0;i<l;i++){ab[s[i]]++;}
    f=1;
    for(i=0;i<l;i++){
        for(j='9';j>='0';j--){
            if(t[i]<=j || ab[j]==0){continue;}
            ab[j]--;q[i]=j;p=i+1;
            for(k='9';k>='0';k--){
                for(x=1;x<=ab[k];x++){q[p]=k;p++;}
            }
            //printf("[%lld:%lld]\n",i,atoll(q));
            r=llmax(r,atoll(q));
            ab[j]++;
        }
        if(ab[t[i]]!=0){
            ab[t[i]]--;q[i]=t[i];
            if(f==1&&i==l-1){r=llmax(r,atoll(q));}
        }
        else{
        if(f==1){
            for(j=t[i]-1;j>='0'-1;j--){
                if(ab[j]!=0){ab[j]--;q[i]=j;}
                if(j<='0'){printf("%lld\n",r);return 0;}
            }
        }
        else{
            for(j='9';j>='0'-1;j--){
                if(ab[j]!=0){ab[j]--;q[i]=j;}
                if(j<='0'){printf("%lld\n",r);return 0;}
            }
        }
            f=0;
        }
    }
    printf("%lld\n",r);
    return 0;
}