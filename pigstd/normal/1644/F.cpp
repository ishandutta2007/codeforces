#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int Mod=998244353;
const int M=2e5+10;
int n,k,fac[M],ifac[M],t[M];

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

void init_C(int n)
{
	fac[0]=1;
	for (int i=1;i<=n;i++)fac[i]=fac[i-1]*i%Mod;
	ifac[n]=poww(fac[n],Mod-2);
	for (int i=n-1;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%Mod;
}

int C(int m,int n)
{
	if (n<0||m<n)return 0;
	return fac[m]*ifac[n]%Mod*ifac[m-n]%Mod;
}

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
const modint G=3,Ginv=modint(1)/3;
struct poly
{
    vector<modint>a;
    modint&operator[](int i){return a[i];}
    int size(){return a.size();}
    void resize(int n){a.resize(n);}
}a,b;int rev[M<<2];
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
        for(int i=0;i<n-1;i++)
            a[i]*=inv;
    }
}

poly inv(poly a,int k)
{
    int n=1<<k;a.resize(n);
    if (n==1){a[0]=modint(1)/a[0];return a;}
    poly f,f0=inv(a,k-1);
    f.resize(n),f0.resize(n<<1),a.resize(n<<1);
    for (int i=0;i<n/2;i++)
        f[i]=f0[i]*2;
    init(k+1),NTT(f0,k+1,1),NTT(a,k+1,1);
    for (int i=0;i<(n<<1);i++)
        f0[i]=f0[i]*f0[i]*a[i];
    NTT(f0,k+1,-1),f0.resize(n);
    for (int i=0;i<n;i++)
        f[i]-=f0[i];
    return f;
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
    NTT(a,k,-1);a.resize(n);return a;
}

int work(int n,int k)
{
	/* 
	memset(dp,0,sizeof(dp));
	dp[1][1]=1;
	for (int i=2;i<=n;i++)
		for (int j=1;j<=min(i,k);j++)
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*j)%Mod;
	int res=0;
	for (int i=1;i<=min(n,k);i++)res=(res+dp[n][i])%Mod; 
	return res;
	
	*/
	a.resize(n+1),b.resize(n+1);
	for (int i=0;i<=n;i++)
	{
		a[i]=modint(1)/fac[i];
		if (i&1)a[i]=mod-a[i];
		b[i]=(modint(i)^n)/fac[i];
	}a=a*b;int res=0;
	for (int i=1;i<=min(n,k);i++)res=(res+a[i].x)%Mod;//,cout<<a[i].x<<' ';
//	cout<<n<<' '<<res<<'\n';
	return res;
}

int solve(int n)
{
	if (t[n]!=-1)return t[n];
	int res=work(n,k)-1;
	for (int l=2,r=0;l<=n-1;l=r+1)
		r=(n-1)/((n-1)/l),
		res=(res-solve((n-1)/l+1)*(r-l+1)%Mod+Mod)%Mod;
	return t[n]=res;
}

signed main()
{
	n=read(),k=read();init_C(max(n,k));
	if (k==1)return puts("1"),0;
	memset(t,-1,sizeof(t));t[1]=1;
	cout<<solve(n)<<'\n';
	return 0;
}
/*
dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*j
*/