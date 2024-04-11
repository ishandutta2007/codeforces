//set many funcs template
//Ver.20180717
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<math.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384
#define eps 0.000000001
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

long long px[131072],py[131072],n;

double maxd(double t){
  long long i;
  double res=-llinf,dx,dy,del,mx,my,k,v,nx,ny;
  for(i=0;i<n;i++){
    dx=px[i];
    dy=py[i];
    del=dy/(dx-t);
    if(dbzt(dx,t)<eps){
      res=dbmax(res,(dbzt(0.0f,dy)/2.0f));
    }
    del=(-1.0f)/del;
    mx=(t+dx)/2.0f;
    my=dy/2.0f;
    k=t-mx;
    v=my+del*k;
    res=dbmax(res,v);
  }
  return res;
}

int main(void){
    long long i,j,m,k,a[524288],b,c,h,w,r=0,l,t;
    double st,fi,te,v1,v2,f1,f2;
    char s[524288];
    scanf("%lld",&n);
    //l=strlen(s);
    k=0;
    for(i=0;i<n;i++){
      scanf("%lld%lld",&px[i],&py[i]);
      if(py[i]>0){k|=1;}
      if(py[i]<0){k|=2;}
      if(k==3){printf("-1\n");return 0;}
    }
    if(k==2){
      for(i=0;i<n;i++){py[i]*=-1;}
    }
    st=-12345678.90f;
    fi=12345678.90f;
    for(i=0;i<200;i++){
      te=(st+fi)/2.0f;
      v1=(st+te)/2.0f;
      v2=(te+fi)/2.0f;
      f1=maxd(v1);
      f2=maxd(v2);
      if(f1>f2){st=v1;}else{fi=v2;}
    }
    printf("%.12lf\n",maxd((st+fi)/2.0f));
    return 0;
}