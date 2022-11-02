#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=800010;
int k,pos[N];
namespace FFT{
	struct comp{
	long double r,i;comp(long double _r=0,long double _i=0){r=_r;i=_i;}
	comp operator+(const comp x){return comp(r+x.r,i+x.i);}
	comp operator-(const comp x){return comp(r-x.r,i-x.i);}
	comp operator*(const comp x){return comp(r*x.r-i*x.i,r*x.i+i*x.r);}
	comp conj(){return comp(r,-i);}
	}A[N],B[N];
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
	void mul(int*a,int*b,int*c){
		int i,j;
		for(i=0;i<k;i++)A[i]=comp(a[i],b[i]);
		FFT(A,k,1);
		for(i=0;i<k;i++){
			j=(k-i)&(k-1);
			B[i]=(A[i]*A[i]-(A[j]*A[j]).conj())*comp(0,-0.25);
		}
		FFT(B,k,-1);
		for(i=0;i<k;i++)c[i]=(long long)(B[i].r+0.5);
	}
}
int a[N],b[N],c[N],n,X,Y,q;
int main()
{
	scanf("%d%d%d",&n,&X,&Y);
	rep(i,n+1){int x;scanf("%d",&x);a[x]=1;b[X-x]=1;}
	for(k=1;k<X;k<<=1);k<<=1;
	int j=__builtin_ctz(k)-1;
	for(int i=0;i<k;i++)pos[i]=pos[i>>1]>>1|((i&1)<<j);
	FFT::mul(a,b,c);
	scanf("%d",&q);
	rep(i,q)
	{
		int x;
		scanf("%d",&x);
		int top=(int)sqrt(x),ans=-1;
		rep(j,top)
		if(x%j==0)
		{
			int now=x/j-2*Y;
			if(now<=0)break;
			if(!(now&1)&&c[now/2+X]){ans=x/j;break;}
			now=j-2*Y;
			if(now>0&&!(now&1)&&c[now/2+X])ans=j;
		}
		printf("%d%c",ans," \n"[i==q]);
	}
	return 0;
}