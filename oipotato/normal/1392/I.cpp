#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=100010;
const int MAX=(int)2e5;
int pos[N<<2];
struct comp{
	long double r,i;
	comp(long double _r=0,long double _i=0){r=_r;i=_i;}
	comp operator+(const comp x){return comp(r+x.r,i+x.i);}
	comp operator-(const comp x){return comp(r-x.r,i-x.i);}
	comp operator*(const comp x){return comp(r*x.r-i*x.i,r*x.i+i*x.r);}
	comp conj(){return comp(r,-i);}
}A[N<<2],B[N<<2],Amin[N<<2],Amax[N<<2],Bmin[N<<2],Bmax[N<<2],ans[N<<2];
namespace FFT{
  const long double pi=acos(-1.0);
  void FFT(comp a[],int n,int t){
    for(int i=1;i<n;i++)if(i<pos[i])swap(a[i],a[pos[i]]);
    for(int d=0;(1<<d)<n;d++){
      int m=1<<d,m2=m<<1;
      long double o=pi*2/m2*t;comp _w(cos(o),sin(o));
      for(int i=0;i<n;i+=m2){
        comp w(1,0);
        for(int j=0;j<m;j++){
          comp&A=a[i+j+m],&B=a[i+j],t=w*A;
          A=B-t;B=B+t;w=w*_w;
        }
      }
    }
    if(t==-1)for(int i=0;i<n;i++)a[i].r/=n;
  }
}
int a[N],b[N],n,m,q;
long long V[N<<1],E1[N<<1],E2[N<<1],Q1[N<<1],Q2[N<<1];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	rep(i,n)scanf("%d",&a[i]),A[a[i]].r++;
	rep(i,m)scanf("%d",&b[i]),B[b[i]].r++;
	rep(i,n-1)Amin[min(a[i],a[i+1])].r++,Amax[max(a[i],a[i+1])].r++;
	rep(i,m-1)Bmin[min(b[i],b[i+1])].r++,Bmax[max(b[i],b[i+1])].r++;
	int len=1;for(;len<MAX;len<<=1);
	int j=__builtin_ctz(len)-1;
	for(int i=0;i<len;i++)pos[i]=pos[i>>1]>>1|((i&1)<<j);
	FFT::FFT(A,len,1);
	FFT::FFT(B,len,1);
	FFT::FFT(Amin,len,1);
	FFT::FFT(Amax,len,1);
	FFT::FFT(Bmin,len,1);
	FFT::FFT(Bmax,len,1);

	rep(i,len)ans[i-1]=A[i-1]*B[i-1];
	FFT::FFT(ans,len,-1);
	rep(i,MAX)V[i]=(long long)(ans[i].r+0.5);
	rep(i,MAX)V[i]+=V[i-1];

	rep(i,len)ans[i-1]=A[i-1]*Bmin[i-1];
	FFT::FFT(ans,len,-1);
	rep(i,MAX)E1[i]+=(long long)(ans[i].r+0.5);
	rep(i,len)ans[i-1]=Amin[i-1]*B[i-1];
	FFT::FFT(ans,len,-1);
	rep(i,MAX)E1[i]+=(long long)(ans[i].r+0.5);
	for(int i=MAX;i;i--)E1[i]+=E1[i+1];

	rep(i,len)ans[i-1]=A[i-1]*Bmax[i-1];
	FFT::FFT(ans,len,-1);
	rep(i,MAX)E2[i]+=(long long)(ans[i].r+0.5);
	rep(i,len)ans[i-1]=Amax[i-1]*B[i-1];
	FFT::FFT(ans,len,-1);
	rep(i,MAX)E2[i]+=(long long)(ans[i].r+0.5);
	rep(i,MAX)E2[i]+=E2[i-1];

	rep(i,len)ans[i-1]=Amin[i-1]*Bmin[i-1];
	FFT::FFT(ans,len,-1);
	rep(i,MAX)Q1[i]=(long long)(ans[i].r+0.5);
	for(int i=MAX;i;i--)Q1[i]+=Q1[i+1];

	rep(i,len)ans[i-1]=Amax[i-1]*Bmax[i-1];
	FFT::FFT(ans,len,-1);
	rep(i,MAX)Q2[i]=(long long)(ans[i].r+0.5);
	rep(i,MAX)Q2[i]+=Q2[i-1];

	rep(i,q)
	{
		int x;scanf("%d",&x);
		printf("%lld\n",(1ll*n*m-V[x-1])+Q1[x]-V[x-1]-Q2[x-1]-E1[x]+E2[x-1]);
	}
    return 0;
}