#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int Mod=998244353;
const int M=1e5+10;
int n,a[M],suf[M],pre[M],fac[M],ifac[M];

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

int work(int n1,int n2)
{
	int res=0;
	for (int i=0;i<=min(n1,n2);i++)res=(res+C(n1,i)*C(n2,i))%Mod;
	return res;
}

void solve()
{
	n=read();suf[n+1]=0;
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)pre[i]=a[i]+pre[i-1];
	for (int i=n;i>=1;i--)suf[i]=suf[i+1]+a[i];
	if (suf[1]==0)return cout<<poww(2,n-1)%Mod<<'\n',void();
	int l=1,r=n;
	while(a[l]==0)l++;
	while(a[r]==0)r--;
	int ans=work(l-1,n-r);
	while(l<=r)
	{
		while(pre[l]!=suf[r]&&l<=r)
		{
			if (pre[l]<suf[r])l++;
			else r--;
		}
//		cerr<<l<<' '<<r<<' '<<ans<<'\n';
		if (l>r)break;
		int L=l+1,R=r-1;
		while(a[L]==0&&L<=R)L++;
		while(a[R]==0&&L<=R)R--;
		if (L>R)return cout<<ans*poww(2,r-l)%Mod<<'\n',void();
		ans=ans*work(L-l,r-R)%Mod,l=L,r=R;
	}
	cout<<ans<<'\n';
}

signed main()
{
	init_C(1e5);
	WT solve();
	return 0;
}