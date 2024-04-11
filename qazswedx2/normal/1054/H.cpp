#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long double ld;
typedef long long ll;
#define pi 3.14159265358979323846l
const int mod=490019,mod1=mod-1;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,ll y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
struct complx
{
	ld x,y;
	complx(ld x=0,ld y=0):x(x),y(y){}
};
complx operator+(const complx &a,const complx &b)
{
	return complx(a.x+b.x,a.y+b.y);
}
complx operator-(const complx &a,const complx &b)
{
	return complx(a.x-b.x,a.y-b.y);
}
complx operator*(const complx &a,const complx &b)
{
	return complx(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}
complx operator/(const complx &a,const ld b)
{
	return complx(a.x/b,a.y/b);
}
int lim,len,rev[1100005];
complx w[2200005];
void getlim(int dep)
{
	lim=1,len=0;
	while(lim<=dep) lim<<=1,len++;
	for(int i=1;i<lim;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
	for(int k=1;k<lim;k<<=1)
	{
		for(int j=0;j<k;j++)
		{
			w[j+k]=complx(cos(pi*j/k),sin(pi*j/k));
	//		if(k<=8) printf("j=%d,k=%d,w=%f,%f\n",j,k,(double)w[j+k].x,(double)w[j+k].y);
		}
	}
}
void fft(complx *a,int fl)
{
	for(int i=1;i<lim;i++)
		if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int k=1;k<lim;k<<=1)
		for(int i=0;i<lim;i+=(k<<1))
			for(int j=0;j<k;j++)
			{
				complx y=a[i+j+k]*w[j+k];
				a[i+j+k]=a[i+j]-y;
				a[i+j]=a[i+j]+y;
			}
	if(fl==-1)
	{
		reverse(a+1,a+lim);
		for(int i=0;i<lim;i++)
			a[i]=a[i]/lim;
	}
}
int n,m,c,a[100005],b[100005],tmp[1100005];
complx A[1100005],B[1100005];
int main()
{
	scanf("%d%d%d",&n,&m,&c);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<m;i++)
		scanf("%d",&b[i]);
	for(int i=0;i<n;i++)
	{
		int u=1ll*i*i%mod1,v;
		v=1ll*a[i]*fpow(c,mod1-1ll*u*(u-1)/2%mod1)%mod;
		tmp[u]=addmod(tmp[u]+v);
	}
/*	for(int i=0;i<50;i++)
		printf("%d ",tmp[i]);
	printf("\n");*/
	for(int i=0;i<mod1;i++)
		A[i].x=tmp[i];
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<m;i++)
	{
		int u=1ll*i*i%mod1*i%mod1,v;
		v=1ll*b[i]*fpow(c,mod1-1ll*u*(u-1)/2%mod1)%mod;
		tmp[u]=addmod(tmp[u]+v);
	}
/*	for(int i=0;i<50;i++)
		printf("%d ",tmp[i]);
	printf("\n");*/
	for(int i=0;i<mod1;i++)
		B[i].x=tmp[i];
	getlim(2*mod1);
//	getlim(200);
	fft(A,1);
	fft(B,1);
	for(int i=0;i<lim;i++)
		A[i]=A[i]*B[i];
	fft(A,-1);
	int ans=0;
	for(int i=0;i<lim;i++)
	{
		int v=((ll)(A[i].x+0.5))%mod;
	//	if(i<=50) printf("i=%d,v=%d,%f,%f\n",i,v,(double)A[i].x,(double)A[i].y);
		ans=addmod(ans+1ll*v*fpow(c,1ll*i*(i-1)/2%mod1)%mod);
	}
	printf("%d\n",ans);
	return 0;
}