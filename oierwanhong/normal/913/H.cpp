#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 5011,mod = 998244353,inv2=(mod+1)>>1;
ll Qpow(ll a,ll p)
{
	if(a==2&&p==mod-2)return inv2;
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
struct Mint
{
	int x;
	Mint():x(0) {}
	Mint(ll x):x((0<=x&&x<mod?x:(x%mod+mod)%mod)) {}
	void operator+= (Mint you){x+=you.x;if(x>=mod)x-=mod;}
	void operator-= (Mint you){x-=you.x;if(x<0)x+=mod;}
	void operator*= (Mint you){x=ll(x)*you.x%mod;}
	void operator/= (Mint you){x=ll(x)*Qpow(you.x,mod-2)%mod;}
	Mint Inv(){return Qpow(x,mod-2);}
};
Mint operator+ (Mint a,Mint b){int t=a.x+b.x;return t>=mod?t-mod:t;}
Mint operator- (Mint a,Mint b){int t=a.x-b.x;return t<0?t+mod:t;}
Mint operator* (Mint a,Mint b){return ll(a.x)*b.x%mod;}
Mint operator/ (Mint a,Mint b){return ll(a.x)*Qpow(b.x,mod-2)%mod;}

typedef std::vector<Mint> poly;
const int L = 1000000;
Mint inv[MAXN];
int p1[MAXN],p2[MAXN],pos[MAXN], len,l1,l2,nxt;
poly f1[MAXN],f2[MAXN],res[MAXN];
Mint C[MAXN][MAXN];
Mint pw[MAXN];
void init(int n)
{
	inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=(mod-mod/i)*inv[mod%i];
	C[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	pw[0]=1;
	for(int i=1;i<=n;++i)pw[i]=pw[i-1]*L;
}
poly operator+ (poly a,poly b)
{
	poly res=a;
	if(res.size()<b.size())res.resize(b.size());
	for(int i=0;i<b.size();++i)res[i]+=b[i];
	return res;
}
poly operator- (poly a,poly b)
{
	poly res=a;
	if(res.size()<b.size())res.resize(b.size());
	for(int i=0;i<b.size();++i)res[i]-=b[i];
	return res;
}
poly Int(poly f)
{
	poly res;
	res.emplace_back(0);
	for(int i=0;i<f.size();++i)res.emplace_back(f[i]*inv[i+1]);
	return res;
}
poly Move(poly f)
{
	poly res(f.size());
	for(int i=0;i<f.size();++i)
		for(int j=0;j<=i;++j)
			if((i-j)&1)res[j]-=C[i][j]*f[i]*pw[i-j];
			else res[j]+=C[i][j]*f[i]*pw[i-j];
	return res;
}
Mint eval(poly f,Mint x)
{
	Mint res=0,pw=1;
	for(auto a:f)res+=a*pw,pw*=x;
	return res;
}
int main()
{
	init(5005);
	int n=read();
	len=1;
	pos[1]=0,res[1]={1};
	for(int w=1;w<=n;++w)
	{
		double d;
		scanf("%lf",&d);
		int x=d*L+0.05;
		if(x>w*L)x=w*L;
		l1=l2=0;
		for(int i=1;i<=len;++i)
		{
			f1[i]=Int(res[i]);
			f1[i][0]+=eval(f1[i-1],pos[i])-eval(f1[i],pos[i]);
			p1[++l1]=pos[i];
		}
		p2[++l2]=0,f2[1].clear();
		for(int i=1;i<=len;++i)
		{
			f2[i+1]=Move(f1[i]);
			p2[++l2]=pos[i]+L;
		}
		int it=1,nxt=0;
		for(int i=1;i<=len;++i)
		{
			pos[++nxt]=p1[i];
			res[nxt]=f1[i]-f2[it];
			if(nxt>1&&pos[nxt]==pos[nxt-1])res[nxt-1]=res[nxt],--nxt;
			while(it<l2&&(i==len||p2[it+1]<p1[i+1]))
			{
				res[++nxt]=f1[i]-f2[++it],pos[nxt]=p2[it];
				if(nxt>1&&pos[nxt]==pos[nxt-1])res[nxt-1]=res[nxt],--nxt;
			}
		}
		len=nxt;
		for(int i=1;i<=len;++i)
			if(pos[i]>=x)
			{
				len=i-1;break;
			}
		pos[len+1]=x,res[len+1]={eval(res[len],x)},++len;
	}
	Mint p=Mint(1)/L,ans=res[len][0];
	for(int i=1;i<=n;++i)ans*=p;
	printf("%d\n",ans.x);
	return 0;
}