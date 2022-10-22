#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define itn int
using namespace std;
 
const int Mod=998244353;
const int mod=998244353;
struct modint{
    int x;
    modint(int o=0){x=o;}
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
 
const int M=3e6+10;
const modint G=3,Ginv=modint(1)/3;
int n,k,q,Q[M],a[M],b[10],t[M];
modint ans[M];
struct poly
{
	vector<modint>a;
	modint&operator[](int i){return a[i];}
	int size(){return a.size();}
	void resize(int n){a.resize(n);}
}x,y;int rev[M];
int ext(int n){int k=0;while((1<<k)<n)k++;return k;}
void init(int k)
{
	int n=1<<k;
	for (int i=0;i<n;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	
}
 
void NTT(poly &a,int k,int opt)
{
	int n=1<<k;
	for (int i=0;i<n;i++)
		if (i<rev[i])swap(a[i],a[rev[i]]);
	for (int mid=1;mid<n;mid<<=1)
	{
		modint Wn=(opt==1?G:Ginv)^((mod-1)/(mid<<1));
		for (int j=0;j<n;j+=mid<<1)
		{
			modint w=1;
			for (int k=0;k<mid;k++,w=w*Wn)
			{
				modint x=a[j+k],y=w*a[j+k+mid];
				a[j+k]=x+y,a[j+k+mid]=x-y;
			}
		}
	}
	if (opt==-1)
	{
		modint inv=modint(1)/n;
		for(int i=0;i<n;i++)
		//For(i,0,n-1)
			a[i]*=inv;
	
	
	}
}
 
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
 
 
modint fac[M],inv[M];
 
void init()
{
	fac[0]=inv[0]=1;
	for (int i=1;i<M;i++)
		fac[i]=fac[i-1]*i,
		inv[i]=1/fac[i];
}
 
modint C(int m,int n)
{
	return fac[m]*inv[n]*inv[m-n];
}
 
void work(int l)
{
	int p1=0,p2=0;
	for (int i=1;i<l;i++)
		if (t[i]==1)p1++;
		else if (t[i]>=2)p2++;
	int k=ext(p1+p2*2)+1;init(k);
	x.a.clear();y.a.clear();
	x.resize(1<<k),y.resize(1<<k);
	for (int i=0;i<=p1;i++)
		x[i]=(modint(2)^i)*C(p1,i);
	for (int i=0;i<=p2*2;i++)
		y[i]=C(p2*2,i);
	NTT(x,k,1),NTT(y,k,1);
	for (int i=0;i<(1<<k);i++)
		x[i]=y[i]*x[i];
	NTT(x,k,-1);
	for (int i=1;i<=q;i++)
		if (Q[i]>=l&&(Q[i]-l)<x.size())
			ans[i]=ans[i]+x[Q[i]-l].x;
}
 
signed main()
{
	init();
	n=read(),k=read();
	//n=300000,k=5;
	for (int i=1;i<=n;i++)t[a[i]=read()]++;
	for (itn i=1;i<=k;i++)
		b[i]=read();
	q=read();
	for (int i=1;i<=q;i++)
		Q[i]=read()/2-1;
	for (int i=1;i<=k;i++)
		work(b[i]);
	for (int i=1;i<=q;i++)
		printf("%d\n",ans[i].x);
	return 0;
}