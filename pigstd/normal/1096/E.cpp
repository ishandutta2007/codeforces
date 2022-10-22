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
const int M=5110;
int fac[M],ifac[M],n,m,k;

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

signed main()
{
	init_C(5100);//return 0;
	n=read(),m=read(),k=read();
	if (k==0)return cout<<poww(n,Mod-2)<<endl,0;
	int cnt1=C(m-k+n-1,n-1),cnt=0;
	for (int i=0;i<=n;i++)
		cnt=(cnt+(i&1?Mod-1:1)*C(m-k*i+n-1,n-1)%Mod*C(n,i))%Mod;
	cnt=(C(n+m-1,n-1)-cnt+Mod)%Mod;
//	cout<<cnt<<' '<<cnt1<<'\n';
//	cout<<inv[n]<<endl;
	cout<<cnt*poww(n,Mod-2)%Mod*poww(cnt1,Mod-2)%Mod;
	return 0;
}