#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7;
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
int n,k,a[M];
modint ans1=1,ans2;

struct poly
{
    vector<modint>a;
    modint&operator[](int i){return a[i];}
    int size(){return a.size();}
    void resize(int n){a.resize(n);}
};

poly one()
{
	poly a;a.resize(1),a[0]=1;return a;
}

poly operator * (poly a,poly b)
{
    int n=a.size()+b.size()-1;
    poly c;c.resize(n);
    for (int i=0;i<a.size();i++) 
    	for (int j=0;j<b.size();j++)
    		c[i+j]+=a[i]*b[j];
    return c;
}

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

void print(poly a){for (int i=0;i<a.size();i++)printf("%lld ",a[i]);puts("");}
void print(modint a){printf("%lld ",a);}


modint ifac[M],ipow[M];

signed main()
{
    cin>>n>>k;poly ans=one();
    for (int i=1;i<=n;i++)
    {
    	cin>>a[i];ans1*=a[i];
    	poly x;x.resize(2);
    	x[0]=a[i],x[1]=-1;
    	ans=ans*x;
//    	print(ans);
	}
	ipow[0]=ifac[0]=1;
//	print(ans);
	for (int i=1;i<=n;i++)
		ipow[i]=ipow[i-1]/n,
		ifac[i]=ifac[i-1]*(k-i+1);
//		printf("%lld %lld\n",ipow[i],ifac[i]);
	for (int i=0;i<=n;i++)ans2+=ans[i]*ifac[i]*ipow[i];
//	print(ans1),print(ans2);
	ans1-=ans2,ans1.x%=mod,ans1.x+=mod,ans1.x%=mod;
	printf("%lld\n",ans1);
	return 0;
}