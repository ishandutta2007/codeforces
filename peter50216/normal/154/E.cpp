#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
const double eps=1e-9;
inline double ABS(double a){
    if(a<eps&&a>-eps)return 0;
    return a<0?-a:a;
}
inline double SA(double a,double b){return ABS(a-b)<eps;}
struct XD{
    double x,y;
    XD(double xx=0,double yy=0):x(xx),y(yy){}
    void get(){
        scanf("%lf%lf",&x,&y);
    }
    XD operator-(const XD& b)const{
        return XD(x-b.x,y-b.y);
    }
    double operator*(const XD& b)const{
        return x*b.x+y*b.y;
    }
    double operator^(const XD& b)const{
        return x*b.y-y*b.x;
    }
    bool operator<(const XD& b)const{
        return SA(y,b.y)?x<b.x:y<b.y;
    }
    double len(){
        return sqrt(x*x+y*y);
    }
}in[100100];
int stk[101000],sc;
inline bool f(int a,int b,int c){
    return ((in[b]-in[a])^(in[c]-in[a]))>0;
}
int too[101000],tc;
double r;
inline bool cyci(int a,int b,int c){
    double d=(in[c]-in[a]).len();
    double cd=-sqrt(r*r-d*d/4)/r;
    double l1=(in[c]-in[b]).len();
    double l2=(in[a]-in[b]).len();
    double cd2=((in[c]-in[b])*(in[a]-in[b]))/l1/l2;
  //  printf("cd=%lf cd2=%lf\n",cd,cd2);
    return cd2<cd-eps;
}
int nex[101000],pre[101000];
const double pi=acos(-1);
inline double qq(double d){
    double a1=d/2*sqrt(r*r-d*d/4);
    double th=asin(d/2/r);
//    printf("%lf %lf %lf %lf\n",d,th,r*r*th/2,a1);
    return r*r*th-a1;
}
inline double q(int a,int b){
    double d=(in[a]-in[b]).len();
    return qq(d);
}
int main(){
    int n,i,j;
    scanf("%d%lf",&n,&r);
    for(i=0;i<n;i++)in[i].get();
    sort(in,in+n);
    sc=0;
    stk[sc++]=0;
    for(i=1;i<n;i++){
        while(sc>1&&!f(stk[sc-2],stk[sc-1],i))sc--;
        stk[sc++]=i;
    }
    tc=0;
    for(i=0;i<sc;i++)too[tc++]=stk[i];
    sc=0;
    stk[sc++]=n-1;
    for(i=n-2;i>=0;i--){
        while(sc>1&&!f(stk[sc-2],stk[sc-1],i))sc--;
        stk[sc++]=i;
    }
    for(i=1;i<sc-1;i++)too[tc++]=stk[i];
    for(i=0;i<tc;i++){
   //     printf("#%d %d %lf %lf\n",i,too[i],in[too[i]].x,in[too[i]].y);
        nex[i]=i+1;
        pre[i]=i-1;
    }
    nex[tc-1]=0;
    pre[0]=tc-1;
    int lf1=0,p=0,ex=0;
    while(1){
        if(p!=lf1)ex=1;
        int p2=nex[p];
        int p3=nex[p2];
        if(p3==p)break;
        if(cyci(too[p],too[p2],too[p3])){
      //      printf("%d %d %d\n",p,p2,p3);
            nex[p]=p3;
            pre[p2]=nex[p2]=-1;
            pre[p3]=p;
            lf1=p;
            ex=0;
        }else{
            if(p==lf1&&ex)break;
            p=nex[p];
        }
    }
    int pp=p;
    double ans=0;
    for(i=nex[p];i!=p;i=nex[i]){
        //printf("%d\n",i);
        double aa=0;
        aa+=(in[too[i]].x*in[too[nex[i]]].y-in[too[i]].y*in[too[nex[i]]].x)/2;
        aa+=q(too[i],too[nex[i]]);
//        printf("   %lf\n",q(i,nex[i]));
        ans+=aa;
    }
   // printf("%d\n",p);
    double aa=0;
    aa+=(in[too[p]].x*in[too[nex[p]]].y-in[too[p]].y*in[too[nex[p]]].x)/2;
    aa+=q(too[p],too[nex[p]]);
//    printf("   %lf\n",q(p,nex[p]));
    ans+=aa;
    printf("%.10lf\n",ans);
    //for(i=0;i<tc;i++)printf("%d %lf %lf\n",too[i],in[too[i]].x,in[too[i]].y);
}