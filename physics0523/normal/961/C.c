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

int main(void){
    int i,j,k,l,n,m,b,c,w,r=inf,t,nr1,nr2;
    int pp[4];
    double d;
    char a[4][128][128];
    scanf("%d",&n);
    //l=strlen(s);
    for(i=0;i<n;i++){
        scanf("%s",a[0][i]);
    }
    for(i=0;i<n;i++){
        scanf("%s",a[1][i]);
    }
    for(i=0;i<n;i++){
        scanf("%s",a[2][i]);
    }
    for(i=0;i<n;i++){
        scanf("%s",a[3][i]);
    }
    for(pp[0]=0;pp[0]<4;pp[0]++){
        for(pp[1]=0;pp[1]<4;pp[1]++){if(pp[0]==pp[1]){continue;}
            for(pp[2]=0;pp[2]<4;pp[2]++){if(pp[0]==pp[2] || pp[1]==pp[2]){continue;}
                for(pp[3]=0;pp[3]<4;pp[3]++){if(pp[0]==pp[3] || pp[1]==pp[3] || pp[2]==pp[3]){continue;}
                    nr1=0;nr2=0;
                    for(i=0;i<n;i++){
                        for(j=0;j<n;j++){
                            if(((i+j)%2)==0 && a[pp[0]][i][j]=='1'){nr1++;}
                            if(((i+j)%2)==0 && a[pp[3]][i][j]=='1'){nr1++;}
                            if(((i+j)%2)==1 && a[pp[0]][i][j]=='0'){nr1++;}
                            if(((i+j)%2)==1 && a[pp[3]][i][j]=='0'){nr1++;}
                            if(((i+j)%2)==0 && a[pp[1]][i][j]=='0'){nr2++;}
                            if(((i+j)%2)==0 && a[pp[2]][i][j]=='0'){nr2++;}
                            if(((i+j)%2)==1 && a[pp[1]][i][j]=='1'){nr2++;}
                            if(((i+j)%2)==1 && a[pp[2]][i][j]=='1'){nr2++;}
                        }
                    }
                    //printf("<%d %d %d %d:%d %d>\n",pp[0],pp[1],pp[2],pp[3],nr1,nr2);
                    r=min(r,nr1+nr2);r=min(r,4*n*n-nr1-nr2);
                }
            }
        }
    }
    //qsort(a,n,sizeof(int),sortfncsj);
    printf("%d\n",r);
    return 0;
}