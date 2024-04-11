#include<bits/stdc++.h>
#define int long long
#define mod Mod
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

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

const int M=1e5+10;
modint ans,f[M];
int n,a[M],p[M],cnt,t[M];

bool isp(int x)
{
	for (int i=2;i*i<=x;i++)
		if (x%i==0)return 0;
	return 1;
}

signed main()
{
	n=read();
//	for (int i=2;i<=1e5;i++)
//		if (isp(i))p[++cnt]=i;
//	printf("%lld\n",ans);
	for (int i=1;i<=n;i++)
		a[i]=read(),t[a[i]]++;
	for (int i=1e5;i>=1;i--)
	{
		int cnt=0;
		for (int j=1;j*i<=1e5;j++)
			cnt+=t[i*j];
		f[i]=(modint(2)^cnt)-1;
//		cout<<cnt<<' ';
//		printf("%lld ",f[i]);
		for (int j=2;j*i<=1e5;j++)
			f[i]-=f[j*i];
//		printf("%lld ",f[i]);
//		puts("");
	}
	printf("%lld",f[1]);
	return 0;
}