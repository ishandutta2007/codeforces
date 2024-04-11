#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
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

const int Mod=1e9+7;
const int M=1e5+10;
int n,a[M];
map<int,int>t;

int fac[M],ifac[M];

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

void init(int n)
{
	fac[0]=ifac[0]=1;
	for (int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%Mod,
		ifac[i]=poww(fac[i],Mod-2);
}

int C(int m,int n)
{
	return fac[m]*ifac[n]%Mod*ifac[m-n]%Mod;
}

signed main()
{
	n=read();init(1e5);int sum=0,cnt=0,cnt1=0,cnt2=0;
	for (int i=1;i<=n;i++)t[a[i]=read()]++,sum+=a[i];
	if (sum%n!=0)return puts("0"),0;
	for (int i=1;i<=n;i++)
		if (a[i]*n==sum)cnt++;
		else if (a[i]*n<sum)cnt1++;
		else cnt2++;
	if (cnt1==1||cnt2==1)
	{
		int x=n,ans=1;
		for (int i=1;i<=n;i++)
			if (t[a[i]])
				ans=ans*C(x,t[a[i]])%Mod,x-=t[a[i]],t[a[i]]=0;
		cout<<ans<<endl;
		return 0;
	}
	int ans=C(n,cnt);
	if (cnt1&&cnt2)ans=ans*2%Mod;
	for (int i=1;i<=n;i++)
		if (t[a[i]])
		{
			if (a[i]*n<sum)
				ans=ans*C(cnt1,t[a[i]])%Mod,cnt1-=t[a[i]],t[a[i]]=0;
			else if (a[i]*n>sum)
				ans=ans*C(cnt2,t[a[i]])%Mod,cnt2-=t[a[i]],t[a[i]]=0;
		}
	cout<<ans<<endl;
	return 0;
}
/*

*/