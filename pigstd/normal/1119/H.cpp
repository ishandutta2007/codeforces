#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mod Mod
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int mod=998244353;
struct modint{
    int x;modint(int o=0){x=o%mod+mod;(x>=mod)&&(x-=mod);}
    modint &operator = (int o){return x=o,*this;}
    modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
    modint &operator ^=(int b){
        modint a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint &operator /=(modint o){return *this *=o^=mod-2;}
    modint &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint &operator /=(int o){return *this *= ((modint(o))^=mod-2);}
    template<class I>friend modint operator +(modint a,I b){return a+=b;}
    template<class I>friend modint operator -(modint a,I b){return a-=b;}
    template<class I>friend modint operator *(modint a,I b){return a*=b;}
    template<class I>friend modint operator /(modint a,I b){return a/=b;}
    friend modint operator ^(modint a,int b){return a^=b;}
    friend bool operator ==(modint a,int b){return a.x==b;}
    friend bool operator !=(modint a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint operator - () {return x?mod-x:0;}
};


const int M=1e6+10;
int n,m,x,y,z,sum,ans[M];
int a[M],b[M],c[M];

struct poly
{
	modint f[M];
}f,f1,f2,f3;

poly operator * (poly a,poly b)
{
	for (int i=0;i<n;i++)a.f[i]=a.f[i]*b.f[i];
	return a;
}

void XOR(poly &a,modint x)
{
	for (int o=2,k=1;o<=n;o<<=1,k<<=1)
		for (int i=0;i<n;i+=o)
			for (int j=0;j<k;j++)
			{
				modint x1=a.f[i+j],x2=a.f[i+j+k];
				a.f[i+j]=x1+x2,a.f[i+j+k]=x1-x2;
				a.f[i+j]*=x,a.f[i+j+k]*=x;
			}
}

signed main()
{
	m=read(),n=1<<read(),x=read(),y=read(),z=read();
	for (int i=1;i<=m;i++)
	{
		a[i]=read(),b[i]=read(),c[i]=read();
		b[i]^=a[i],c[i]^=a[i],sum^=a[i],a[i]=0;
		f1.f[b[i]]+=1,f2.f[c[i]]+=1,f3.f[b[i]^c[i]]+=1;
	}
//	for (int i=0;i<n;i++)
//		printf("%lld %lld %lld\n",f1.f[i],f2.f[i],f3.f[i]);puts("");
	XOR(f1,1),XOR(f2,1),XOR(f3,1);
//	for (int i=0;i<n;i++)
//		printf("%lld %lld %lld\n",f1.f[i],f2.f[i],f3.f[i]);puts("");
	for (int i=0;i<n;i++)
	{
		modint s1=f1.f[i],s2=f2.f[i],s3=f3.f[i];
		modint w1=s1+s2+s3+m,w2=s1-s2-s3+m,w3=-s1+s2-s3+m,w4=-s1-s2+s3+m;
		w1/=4,w2/=4,w3/=4,w4/=4;
		modint x1=x+y+z,x2=x+y-z,x3=x-y+z,x4=x-y-z;
		x1=x1^w1.x,x2=x2^w2.x,x3=x3^w3.x,x4=x4^w4.x;
		f.f[i]=x1*x2*x3*x4;
	}
	XOR(f,modint(1)/2);
	for (int i=0;i<n;i++)
		ans[i]=f.f[i^sum].x;
	for (int i=0;i<n;i++)
		cout<<ans[i]<<' ';
	return 0;
}