#include<bits/stdc++.h>
#define int long long
using namespace std;

const int Mod=1e9+7;
const int M=1e5+10;
string s;int len;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int poww(int a,int b)
{
	int r=1;
	while(b)
	{
		if (b&1)r=r*a%Mod;
		a=a*a%Mod;
		b>>=1;
	}
	return r;
}

int fac[M],inv[M];

void init()
{
	fac[0]=1;
	for (int i=1;i<M;i++)fac[i]=fac[i-1]*i%Mod;
	for (int i=0;i<M;i++)inv[i]=poww(fac[i],Mod-2);
}

int p=Mod;
int C(int m,int n)
{
	return fac[m]*inv[m-n]%p*inv[n]%p;
}

int f(int k)
{
	if (k<=1)return 1;
	int cnt=0;
	for (int i=0;i*2<=k;i++)
	{
		int pp=k-i*2;
		// i,p
		cnt+=C(i+pp,i),cnt%=Mod;
	}
	return cnt;
}

signed main()
{
	init();
//	cout<<f(2);
	cin>>s;len=s.size();int cnt=0,ans=1;
	for (int i=0;i<len;i++)
		if (s[i]=='u'||s[i]=='n')
		{
			if (s[i]==s[i-1])
				cnt++;
			else ans*=f(cnt),ans%=Mod,cnt=1;
		}
		else if (s[i]=='m'||s[i]=='w')ans=0;
		else
			ans*=f(cnt),ans%=Mod,cnt=0;
	ans*=f(cnt),ans%=Mod;
	cout<<ans;
	return 0;
}