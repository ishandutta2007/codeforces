#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
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

const int Mod=998244353;
const int M=1e6+10;
string s;
int n,a[M],sum1[M],sum2[M],sum3[M],sum4[M],ans;
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
int inv(int x){return poww(x,Mod-2);}
void init(int n)
{
	fac[0]=ifac[0]=1;
	for (int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%Mod,
		ifac[i]=inv(fac[i]);
}
int C(int m,int n)
{
	if (m<n||n<0||m<0)return 0;
	return fac[m]*ifac[n]%Mod*ifac[m-n]%Mod;
}

signed main()
{
	cin>>s;n=s.size();init(n);
	for (int i=1;i<=n;i++)
		if (s[i-1]=='(')a[i]=1,sum1[i]++;
		else if (s[i-1]==')')a[i]=2,sum2[i]++;
		else a[i]=3,sum3[i]++;
	for (int i=1;i<=n;i++)
		sum1[i]+=sum1[i-1],
		sum2[i]+=sum2[i-1],
		sum3[i]+=sum3[i-1];
	for (int i=1;i<n;i++)
	{
		int s1=sum1[i],s2=sum3[i],s3=sum2[n]-sum2[i],s4=sum3[n]-sum3[i];
		ans=(ans+s1*C(s2+s4,s3+s4-s1)%Mod+s2*C(s2+s4-1,s4+s3-s1-1)%Mod)%Mod;
	}cout<<ans<<endl;
	return 0;
}