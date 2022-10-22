#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

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

const int M=4e6+10;
const modint G=3,Ginv=modint(1)/3;
int n,kk;

struct poly
{
    vector<modint>a;
    modint&operator[](int i){return a[i];}
    int size(){return a.size();}
    void resize(int n){a.resize(n);}
}a;int rev[M];
int ext(int n){int k=0;while((1<<k)<n)k++;return k;}
poly one(){poly a;a.a.pb(modint(1));return a;}
poly one2(){poly a;a.a.pb(modint(0)),a.a.pb(modint(1));return a;}
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
        for(int i=0;i<n-1;i++)
            a[i]*=inv;
    }
}
poly operator + (poly a,poly b)
{
    int n=max(a.size(),b.size());a.resize(n),b.resize(n);
    for (int i=0;i<n;i++)a[i]+=b[i];
    return a;
}
poly operator - (poly a,poly b)
{
    int n=max(a.size(),b.size());a.resize(n),b.resize(n);
    for (int i=0;i<n;i++)a[i]-=b[i];
    return a;
}
poly operator * (poly a,poly b)
{
    int n=a.size()+b.size()-1,k=ext(n);
    a.resize(1<<k),b.resize(1<<k);init(k);
    NTT(a,k,1),NTT(b,k,1);
    for (int i=0;i<(1<<k);i++)a[i]=a[i]*b[i];
    NTT(a,k,-1);a.resize(kk+1);return a;
}

struct node
{
	poly f1,f2,f3;
	void clear()
	{
		f1.resize(0);
		f2.resize(0);
		f3.resize(0);
	}
}ans;

void print(poly a)
{
	for (int i=1;i<=kk;i++)
		printf("%lld ",a[i]);
	puts("");
}

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

node fun1(node x)
{
	node y;y.clear();int n=kk*2+1,k=ext(n);init(k);
	poly xx;xx=one2();xx.resize(1<<k);NTT(xx,k,1);
    x.f1.resize(1<<k),x.f2.resize(1<<k),x.f3.resize(1<<k);
	NTT(x.f1,k,1),NTT(x.f2,k,1),NTT(x.f3,k,1);
    y.f1.resize(1<<k),y.f2.resize(1<<k),y.f3.resize(1<<k);
	for (int i=0;i<(1<<k);i++)
		y.f1[i]=x.f2[i]*x.f2[i]+x.f1[i]*x.f1[i]*xx[i],
		y.f2[i]=x.f2[i]*x.f3[i]+xx[i]*x.f1[i]*x.f2[i],
		y.f3[i]=x.f3[i]*x.f3[i]+xx[i]*x.f2[i]*x.f2[i];
	NTT(y.f1,k,-1),NTT(y.f2,k,-1),NTT(y.f3,k,-1);
    y.f1.resize(kk+1),y.f2.resize(kk+1),y.f3.resize(kk+1);
	return y;
}

node fun2(node x)
{
	node y;y.clear();y.f2=x.f3,y.f1=x.f2;
	y.f3.resize(kk+1);
	for (int i=0;i<=kk;i++)
		y.f3[i]=x.f3[i];
	for (int i=1;i<=kk;i++)
		y.f3[i]+=x.f3[i-1]+x.f2[i-1];
	return y;
}

signed main()
{
	n=read(),kk=read();ans.f2.resize(kk+1),ans.f1.resize(kk+1);
	ans.f3=one(),ans.f3.resize(kk+1);
	for (int i=31;i>=0;i--)
	{
		ans=fun1(ans);
		if (n&(1<<i))
			ans=fun2(ans);
//		print(ans.f3);
//		print(ans.f2);
//		print(ans.f1);
	}
	print(ans.f3);
    return 0;
}