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

int res[32768][4],rc=0;

void addres(int a,int b,int c){
    res[rc][0]=a;
    res[rc][1]=b;
    res[rc][2]=c;
    rc++;
}

void outres(){
    printf("%d\n",rc);
    int i;
    for(i=0;i<rc;i++){
        printf("%d %d %d\n",res[i][0],res[i][1]+1,res[i][2]+1);
    }
}

int main(void){
    int i,j,n,m,k,a[4][512],b=-1,c=-1,w,r=0,l,t;
    int ex[512][2];
    int sx,sy,tx,ty;
    double d;
    char s[524288];
    scanf("%d%d",&n,&k);
    //l=strlen(s);
    for(j=0;j<4;j++){for(i=0;i<n;i++){scanf("%d",&a[j][i]);}}
    for(i=1;i<3;i++){
        for(j=0;j<n;j++){
            if(i==1){
                if(a[0][j]!=0&&a[i][j]==a[0][j]){
                    addres(a[i][j],0,j);
                    a[i][j]=0;r++;
                }
            }
            if(i==2){
                if(a[3][j]!=0&&a[i][j]==a[3][j]){
                    addres(a[i][j],3,j);
                    a[i][j]=0;r++;
                }
            }
            if(a[i][j]==0){b=i;c=j;}
        }
    }
    if(b==-1){
        printf("-1\n");return 0;
    }
    if(r==k){outres();return 0;}
    for(i=0;i<n;i++){ex[i][0]=1;ex[i][1]=i;}
    for(i=0;i<n;i++){ex[n+i][0]=2;ex[n+i][1]=n-i-1;}
    ex[2*n][0]=1;ex[2*n][1]=0;
    while(1){
        for(i=0;i<2*n;i++){
            sx=ex[i][0];
            sy=ex[i][1];
            tx=ex[i+1][0];
            ty=ex[i+1][1];
            if(a[sx][sy]!=0){continue;}
            if(a[tx][ty]==0){continue;}
            //printf("%d %d %d\n",a[tx][ty],sx,sy);
            addres(a[tx][ty],sx,sy);
            a[sx][sy]=a[tx][ty];
            a[tx][ty]=0;
            if(sx==1){
                if(a[0][sy]!=0&&a[sx][sy]==a[0][sy]){
                    addres(a[sx][sy],0,sy);
                    a[sx][sy]=0;r++;
                }
            }
            if(sx==2){
                if(a[3][sy]!=0&&a[sx][sy]==a[3][sy]){
                    addres(a[sx][sy],3,sy);
                    a[sx][sy]=0;r++;
                }
            }
            if(r==k){outres();return 0;}
        }
    }
    //shuffledget(a,n);
    //qsort(a,n,sizeof(int),sortfncsj);
    //printf("%d\n",r);
    return 0;
}